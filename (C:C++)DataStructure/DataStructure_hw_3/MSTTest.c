#include <stdio.h>
#include <stdlib.h>

// 그래프의 간선을 나타내는 구조체
struct Edge {
    int src, dest, weight;
};

// 그래프의 정점을 나타내는 구조체
struct Graph {
    int V, E; // 정점 수와 간선 수
    struct Edge* edge; // 간선 배열
};

// 그래프 생성
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// 부분 집합을 찾는 함수 (Union-Find 알고리즘 사용)
int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// 두 부분 집합을 합치는 함수 (Union-Find 알고리즘 사용)
void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}


// 간선을 가중치 순으로 비교하는 함수
int compare(const void* a, const void* b) {
    struct Edge* a_edge = (struct Edge*)a;
    struct Edge* b_edge = (struct Edge*)b;
    return a_edge->weight - b_edge->weight;
}

// MST를 구성하는 함수
void printMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V]; // MST의 간선을 저장하는 배열
    int e = 0; // MST의 간선 수
    int i = 0; // 그래프의 간선을 순회하기 위한 인덱스

    // 간선을 가중치 순으로 정렬
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);

    // 간선의 부모 배열 생성 및 초기화
    int* parent = (int*)malloc(V * sizeof(int));
    for (int v = 0; v < V; v++)
        parent[v] = -1;

    // MST 구성
    while (e < V - 1 && i < graph->E) {
        struct Edge next_edge = graph->edge[i++];

        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(parent, x, y);
        }
    }

    // MST 출력
    printf("Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++)
        printf("%d -- %d\t%d\n", result[i].src, result[i].dest, result[i].weight);

    free(parent);
}

int main() {
    int V = 4; // 정점 수
    int E = 5; // 간선 수
    struct Graph* graph = createGraph(V, E);

    // 간선 추가
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    printMST(graph);

    return 0;
}
