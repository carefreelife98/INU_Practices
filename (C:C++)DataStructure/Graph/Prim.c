#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

typedef struct GraphType {
    int n; // 정점의 개수
    int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

// 최소 dist[v] 값을 갖는 정점을 반환
int get_min_vertex(int n){
    int v, i;
    for (i = 0; i < n; i++){
        // 아직 선택 되지 않은 정점을 찾아 해당 정점의 값을 v에 복사.
        if(!selected[i]){
            v = i;
            break;
        }
    }
    for(i = 0; i < n; i++){
        
        // 아직 선택 되지 않은 정점 중 distance가 가장 작은 값을 가진 정점을 v에 복사.
        if(!selected[i] && (distance[i] < distance[v]))
            v = i;
    }
    // 가장 작은 값을 가진 distance의 정점을 반환.
    return (v);
}

void prim(GraphType *g, int s){
    int i, u, v;
    // distance[] 초기화
    for(u = 0; u < g->n; u++){
        distance[u] = INF;
    }
    distance[s] = 0;    // 시작 정점의 거리 == 0;
    for(i = 0; i < g->n; i++){
        u = get_min_vertex(g->n);
        selected[u] = TRUE;
        if(distance[u] == INF) return;
        printf("정점 %d 추가\n", u);
        for(v = 0; v < g->n; v++){
            if(g->weight[u][v] != INF){
                if(!selected[v] && g->weight[u][v] < distance[v]){
                    distance[v] = g->weight[u][v];
                }
            }
        }
    }
}

int main(void)
{
	GraphType g = { 7, 
	{{ 0, 29, INF, INF, INF, 10, INF },
	{ 29,  0, 16, INF, INF, INF, 15 },
	{ INF, 16, 0, 12, INF, INF, INF },
	{ INF, INF, 12, 0, 22, INF, 18 },
	{ INF, INF, INF, 22, 0, 27, 25 },
	{ 10, INF, INF, INF, 27, 0, INF },
	{ INF, 15, INF, 18, 25, INF, 0 }}
	};
	prim(&g, 0);
	return 0;
}
