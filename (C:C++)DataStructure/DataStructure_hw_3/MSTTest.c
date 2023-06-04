#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define FILE_LEN 959
#define MAX_VERTICES 100
#define NUM_GROUPS 5

#pragma warning(disable:4996)

//////////////////////////////// 구조체, 정의 시작 //////////////////////////////

// FILE로 읽은 데이터
typedef struct Data{
    int me;
    int you;
    float love;
    int check;
} Data;

// 간선을 나타내는 구조체
typedef struct Edge {
	int me, you;
    // int index;
    float love;
} Edge;

typedef struct GraphType_ {
	int n;	// 정점의 개수
	struct Data edges[959];
} GraphType_;

// 그래프 초기화 
void graph_init(GraphType_* g)
{
	g->n = 0;
	for (int i = 0; i < 2 * MAX_VERTICES; i++) {
		g->edges[i].me = 0;
		g->edges[i].you = 0;
		g->edges[i].love = 11.0;
        // g->edges[i].index = 0;
	}
}

// 간선 삽입 연산
void insert_edge(GraphType_* g, int start, int end, float w, int index)
{
	g->edges[g->n].me = start;
	g->edges[g->n].you = end;
	g->edges[g->n].love = w;

	g->n++; // 정점 개수 + 1
}

void swap(Data* a, Data* b) {
    Data temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Data arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].love > arr[largest].love)
        largest = left;

    if (right < n && arr[right].love > arr[largest].love)
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(Data arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void calculate_love(Data* data){
    int total = 0;
    for(int i = 0; i < FILE_LEN; i++){
        data[i].check = 0;
        for(int j = 0; j < FILE_LEN; j++){
            if (data[i].me == data[j].you && data[i].you == data[j].me){
                float love = (data[i].love + data[j].love) / 2;
                data[i].love = love; 
                data[j].love = love;
                data[i].check = 1;
                data[j].check = 1;
                total++;
            }
        }
        if (data[i].check == 0){
            data[i].love = (data[i].love + 11) / 2;
        }
    }
    printf("total = [%d]\n", total);
}

#define NUM_EDGES 959

typedef struct MSTGraph {
    int n;
    Data edges[NUM_EDGES];
    float totalWeight;
} MSTGraph;

int parent[MAX_VERTICES];
int groupAssignment[MAX_VERTICES];

void set_init(int n) {
    for (int i = 0; i < n; i++)
        parent[i] = -1;
}

int set_find(int curr) {
    if (parent[curr] == -1)
        return curr;
    while (parent[curr] != -1)
        curr = parent[curr];
    return curr;
}

void set_union(int a, int b) {
    int root1 = set_find(a);
    int root2 = set_find(b);
    if (root1 != root2)
        parent[root1] = root2;
}

int compareData(const void* a, const void* b) {
    Data* dataA = (Data*)a;
    Data* dataB = (Data*)b;
    return (int)(dataA->love - dataB->love);
}

void kruskal(GraphType_ *g, MSTGraph mst[], int numVertices, int numEdges) {
    int edgeAccepted = 0;   // Number of edges accepted so far
    
    set_init(numVertices);  // Initialize the sets
    
    // Sort the edges in ascending order based on weight
    qsort(g->edges, numEdges, sizeof(Data), compareData);
    
    for (int i = 0; i < numEdges; i++) {
        Data currentEdge = g->edges[i];
        
        int start = currentEdge.me;
        int end = currentEdge.you;
        
        int rootStart = set_find(start);
        int rootEnd = set_find(end);
        
        if (rootStart != rootEnd) {
            // Add the edge to the corresponding MST graph
            mst[groupAssignment[start]].edges[mst[groupAssignment[start]].n++] = currentEdge;
            mst[groupAssignment[start]].totalWeight += currentEdge.love;
            
            // Union the sets
            set_union(rootStart, rootEnd);
            edgeAccepted++;
        }
        
        // Check if we have enough edges in the MST graph for a group
        if (edgeAccepted >= numVertices / NUM_GROUPS)
            break;
    }
}

void printMST(MSTGraph mst[], int numGroups) {
    for (int i = 0; i < numGroups; i++) {
        printf("MST graph %d (Total Weight: %.2f):\n", i + 1, mst[i].totalWeight);
        for (int j = 0; j < mst[i].n; j++) {
            Data currentEdge = mst[i].edges[j];
            printf("(%d, %d) %.2f\n", currentEdge.me, currentEdge.you, currentEdge.love);
        }
        printf("\n");
    }
}

void read_data_to_struct(Data *data) {
    FILE *fp;
    fp = fopen("students2.txt", "r");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }
  
    char buf[30];
    int i = 0;
    while (fgets(buf, 30, fp) != NULL) {
        
        sscanf(buf, "%d %d %f", &data[i].me, &data[i].you, &data[i].love);
        i++;
    }
    printf("FILE legth: [%d]\n", i);
    
    fclose(fp);
}

int main(void){

    Data data[FILE_LEN];

    read_data_to_struct(data);
    
    calculate_love(data);

    GraphType_ *g = (GraphType_*)malloc(sizeof(GraphType_));

    graph_init(g);

    for(int i = 0; i < FILE_LEN; i++){
        insert_edge(g, data[i].me, data[i].you, data[i].love, i);
    }
    printf("정점 삽입 완료 : %d 개\n", g->n);
    printf("간선 삽입 완료\n");

    MSTGraph mst[NUM_GROUPS];
    
    g->n = NUM_EDGES;  // Number of edges
    
    // Initialize group assignment to -1
    for (int i = 0; i < MAX_VERTICES; i++)
        groupAssignment[i] = -1;
    
   // Assign vertices to groups based on their connections' total weight
    for (int v = 0; v < MAX_VERTICES; v++) {
        float minTotalWeight = __FLT_MAX__;
        int assignedGroup = -1;
        
        // Find the group with the minimum total weight
        for (int group = 0; group < NUM_GROUPS; group++) {
            float totalWeight = 0.0f;
            
            // Calculate the total weight of connections in the group
            for (int i = 0; i < mst[group].n; i++) {
                Data edge = mst[group].edges[i];
                totalWeight += edge.love;
            }
            
            if (totalWeight < minTotalWeight) {
                minTotalWeight = totalWeight;
                assignedGroup = group;
            }
        }
        
        groupAssignment[v] = assignedGroup;
        mst[assignedGroup].totalWeight = minTotalWeight;
    }
    
    // Perform Kruskal's algorithm for each group
    for (int i = 0; i < NUM_GROUPS; i++) {
        mst[i].n = 0;
        mst[i].totalWeight = 0.0f;
    }
    
    kruskal(g, mst, MAX_VERTICES, g->n);
    
    // Print the MST graphs
    printMST(mst, NUM_GROUPS);
    
    return 0;
}
