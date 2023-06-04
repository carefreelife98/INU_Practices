#include <stdio.h>
#include <stdlib.h>

#define FILE_LEN 959
#pragma warning(disable:4996)
#define NUM_VERTICES 100 // Adjust this based on your actual number of vertices
#define NUM_GRAPHS 5



typedef struct Data{
    int me;
    int you;
    float love;
    int check;
    struct Data* link;
} Data;

typedef struct Edge {
    int v1;
    int v2;
    float weight;
} Edge;

typedef struct Graph {
    int vertices[NUM_VERTICES];
    int numVertices;
} Graph;

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

void mergeGraphs(Graph* graphs, int graphIndex1, int graphIndex2) {
    for (int i = 0; i < graphs[graphIndex2].numVertices; i++) {
        graphs[graphIndex1].vertices[graphs[graphIndex1].numVertices++] = graphs[graphIndex2].vertices[i];
    }
}

int compareWeights(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeA->weight - edgeB->weight;
}

void divideEdgesIntoGraphs(Edge* edges, int numEdges, Graph* graphs) {
    qsort(edges, numEdges, sizeof(Edge), compareWeights);
    printf("sort 성공\n");
    // 정렬된 edges 배열의 각 간선을 순회.
    for (int i = 0; i < numEdges; i++) {

        // edge 하나 꺼낸다.
        Edge edge = edges[i];
        // 현재 간선이 할당될 그래프 넘버.
        int graphIndex = -1;

        // graphs 배열의 각 그래프 순회
        for (int j = 0; j < NUM_GRAPHS; j++) {
            if (graphs[j].vertices[edge.v1] == 1 || graphs[j].vertices[edge.v2] == 1) {
                if (graphIndex == -1) {
                    graphIndex = j;
                } else if (graphIndex != j) {
                    mergeGraphs(graphs, graphIndex, j);
                    graphs[j].numVertices = 0; // Reset the merged graph
                }
            }
        }
        if (graphIndex == -1) {
            for (int j = 0; j < NUM_GRAPHS; j++) {
                if (graphs[j].numVertices == 0) {
                    graphIndex = j;
                    break;
                }
            }
        }

        graphs[graphIndex].vertices[edge.v1] = 1;
        graphs[graphIndex].vertices[edge.v2] = 1;
        graphs[graphIndex].numVertices += 2;
    }
}

int main() {
    Data data[FILE_LEN];

    Edge edges[FILE_LEN]; // Adjust the array size based on your actual number of edges
    
    read_data_to_struct(data);
    
    calculate_love(data);
    // Populate the edges array with actual data
    // ...

    for(int i = 0; i < FILE_LEN; i++){
        edges[i].v1 = data[i].me;
        edges[i].v2 = data[i].you;
        edges[i].weight = data[i].love;
        printf("%d %f %d\n", edges[i].v1, edges[i].weight, edges[i].v2);
    }


    Graph graphs[NUM_GRAPHS];
    for (int i = 0; i < NUM_GRAPHS; i++) {
        graphs[i].numVertices = 0;
        for (int j = 0; j < NUM_VERTICES; j++) {
            graphs[i].vertices[j] = 0;
        }
    }

    divideEdgesIntoGraphs(edges, FILE_LEN, graphs);

    // Print the resulting graphs
    for (int i = 0; i < NUM_GRAPHS; i++) {
        printf("Graph %d: ", i + 1);
        for (int j = 0; j < NUM_VERTICES; j++) {
            if (graphs[i].vertices[j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    return 0;
}
