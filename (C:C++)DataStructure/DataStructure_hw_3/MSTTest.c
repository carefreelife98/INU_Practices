#include <stdio.h>
#include <stdlib.h>

#define FILE_LEN 959
#define MAX_VERTICES 100

#pragma warning(disable:4996)

//////////////////////////////// 구조체, 정의 시작 //////////////////////////////

// FILE로 읽은 데이터
typedef struct Data{
    int me;
    int you;
    float love;
    int check;
    struct Data* link;
} Data;

typedef struct {
	Data heap[FILE_LEN];
	int heap_size;
} HeapType;

// 간선을 나타내는 구조체
typedef struct Edge {
	int me, you;
    float love;
} Edge;

typedef struct GraphNode{
    int vertex;
    float love;
    struct GraphNode* link;
}GraphNode;

typedef struct GraphType{
    int n; // 정점의 개수
    GraphNode* adj_list[MAX_VERTICES];
}GraphType;

typedef struct GraphType_ {
	int n;	// 정점의 개수
	struct Edge edges[2 * MAX_VERTICES];
} GraphType_;

// Structure to represent an edge
// struct Edge {
//     int start;
//     int end;
//     int weight;
// };

// Function to compare edges based on their weights (used for sorting)
int compareEdges(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*)a;
    struct Edge* edgeB = (struct Edge*)b;
    return edgeA->love - edgeB->love;
}

// Function to find the parent of a vertex
int findParent(int* parent, int vertex) {
    if (parent[vertex] == -1)
        return vertex;
    return findParent(parent, parent[vertex]);
}

// Function to perform union of two sets
void unionSets(int* parent, int x, int y) {
    int parentX = findParent(parent, x);
    int parentY = findParent(parent, y);
    parent[parentX] = parentY;
}

// Function to divide vertices into 5 groups with the lowest weight
void divideIntoGroups(struct Edge* edges, int numEdges, int numVertices) {
    // Sort the edges in ascending order based on their weights
    qsort(edges, numEdges, sizeof(struct Edge), compareEdges);

    // Create an array to keep track of the group assignment for each vertex
    int* groupAssignment = (int*)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++) {
        groupAssignment[i] = -1; // Initialize group assignment to -1 (no group)
    }

    // Create an array to store the 5 groups
    int** groups = (int**)malloc(5 * sizeof(int*));
    for (int i = 0; i < 5; i++) {
        groups[i] = (int*)malloc(numVertices * sizeof(int));
    }

    // Iterate through the sorted edges
    for (int i = 0; i < numEdges; i++) {
        struct Edge currentEdge = edges[i];

        // Check if adding the edge creates a cycle in the current groups
        int parentStart = findParent(groupAssignment, currentEdge.me);
        int parentEnd = findParent(groupAssignment, currentEdge.you);
        if (parentStart == parentEnd)
            continue; // Skip the edge

        // Add the edge and its vertices to one of the groups with the lowest cumulative weight
        int groupIndex = -1;
        int minWeight = INT32_MAX;
        for (int j = 0; j < 5; j++) {
            int cumulativeWeight = 0;
            for (int k = 0; k < numVertices; k++) {
                if (groupAssignment[k] == j)
                    cumulativeWeight += edges[k].love;
            }
            if (cumulativeWeight < minWeight) {
                minWeight = cumulativeWeight;
                groupIndex = j;
            }
        }
        groupAssignment[currentEdge.me] = groupIndex;
        groupAssignment[currentEdge.you] = groupIndex;
    }

    // Assign remaining vertices to the groups with the lowest cumulative weight
    for (int i = 0; i < numVertices; i++) {
        if (groupAssignment[i] == -1) {
            int groupIndex = -1;
            int minWeight = INT32_MAX;
            for (int j = 0; j < 5; j++) {
                int cumulativeWeight = 0;
                for (int k = 0; k < numVertices; k++) {
                    if (groupAssignment[k] == j)
                        cumulativeWeight += edges[k].love;
                }
                if (cumulativeWeight < minWeight) {
                    minWeight = cumulativeWeight;
                    groupIndex = j;
                }
            }
            groupAssignment[i] = groupIndex;
        }
    }

    // Print the 5 groups of vertices with the lowest weight
    for (int i = 0; i < 5; i++) {
        printf("Group %d: ", i+1);
        for (int j = 0; j < numVertices; j++) {
            if (groupAssignment[j] == i)
                printf("%d ", j);
        }
        printf("\n");
    }

    // Free dynamically allocated memory
    free(groupAssignment);
    for (int i = 0; i < 5; i++) {
        free(groups[i]);
    }
    free(groups);
}

// 그래프 초기화 
void graph_init(GraphType_* g)
{
	g->n = 0;
	for (int i = 0; i < 2 * MAX_VERTICES; i++) {
		g->edges[i].me = 0;
		g->edges[i].you = 0;
		g->edges[i].love = 11.0;
	}
}

// 간선 삽입 연산
void insert_edge(GraphType_* g, int start, int end, float w, int index)
{
	g->edges[g->n].me = start;
	g->edges[g->n].you = end;
	g->edges[g->n].love = w;
	g->n++; // 정점 개수 + 1
    printf("edge 추가 : [%d] <---[%f]---> [%d]\n", g->edges[g->n].me, g->edges[g->n].love, g->edges[g->n].you);
}

//////////////////////////////// FILE 저장 및 친밀도 계산 (시작) //////////////////////////////
void calculate_love(Data* data){
    int total = 0;
    for(int i = 0; i < FILE_LEN; i++){
        data[i].check = 0;
        // 만약 양방향 love 였다면 아래에서 서로의 평균으로 갱신된다.
        for(int j = 0; j < FILE_LEN; j++){
            // j_you가 데이터를 처음부터 읽으며 i_me와 같은 데이터를 찾는다.(양 방향 love 찾기)
            if (data[i].me == data[j].you && data[i].you == data[j].me){
                float love = (data[i].love + data[j].love) / 2;
                // 둘의 평균으로 love 변경.
                data[i].love = love; 
                data[j].love = love;
                // 갱신된 값이라고 표기
                data[i].check = 1;
                data[j].check = 1;
                // printf("양방향 love [%d] <-[love: %f]-> [%d]    ", data[i].me, love, data[i].you);
                total++;
                // if(total % 2 == 0){
                //     printf("\n");
                // }
            }
        }
        if (data[i].check == 0){
            // 위 for문에서 twin = 1 로 체크되지 않은 단방향 love는 11을 더해 평균을 구한다.
            data[i].love = (data[i].love + 11) / 2;
        }
    }
    printf("total = [%d]\n", total);
}

void read_data_to_struct(Data *data) {
    FILE *fp;
    fp = fopen("students2.txt", "r"); // 읽기 모드로 파일을 연다.
    if (fp == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }
    // 파일에서 데이터를 읽어와 구조체에 저장.
    char buf[30];
    int i = 0;
    while (fgets(buf, 30, fp) != NULL) {
        // 각 행의 데이터를 구조체에 저장
        sscanf(buf, "%d %d %f", &data[i].me, &data[i].you, &data[i].love);
        i++;
    }
    printf("FILE legth: [%d]\n", i);
    // 파일 닫기.
    fclose(fp);
}

//////////////////////////////// FILE 저장 및 친밀도 계산 (끝) //////////////////////////////


// 1. 크루스칼로 전체 MST를 찾고, 가장 큰 가중치를 가진 간선 4개와 해당 노드를 크루스칼 알고리즘에서 메인함수의 배열에 전달.
// 2. K_graph의 edge에서 첫번째 간선을 삭제. -> 간선을 잇던 두 노드를 기준으로 prim 알고리즘.
// 3. 두 그래프에서 다음 간선을 찾는다. -> 찾으면 과정2 반복.
int main(void){
    // HeapType *h = create();
    Data data[FILE_LEN];

    read_data_to_struct(data);

    calculate_love(data);

    /////// 100개 노드 그래프 생성 시작 ///////
    GraphType_ *g = (GraphType_*)malloc(sizeof(GraphType_));

    graph_init(g);

    for(int i = 0; i < FILE_LEN; i++){
        insert_edge(g, data[i].me, data[i].you, data[i].love, i);
    }
    printf("정점 삽입 완료 : %d 개\n", g->n);
    printf("간선 삽입 완료\n");

    /////// 100개 노드 그래프 생성 끝 ///////
    
    // 삭제될 4개의 최대 가중치를 가진 간선 정보 저징.
    // Edge to_delete[4];

    // 최종 그래프 5개의 간선 정보를 가진 구조체 배열. 노드가 100개이므로 간선은 99개.
    Edge final[99];

    // Sample input
    int numVertices = 100;
    int numEdges = 99;
    // Initialize edges (start, end, weight)

    // Call the function to divide vertices into 5 groups with the lowest weight
    divideIntoGroups(final, numEdges, numVertices);

    return 0;
}
