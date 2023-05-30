#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 50

typedef struct GraphType {
    int n; //정점의 개수
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

// 그래프 초기화
void init_graph(GraphType* g){
    int r, c;
    g->n = 0;
    
    for(r = 0; r < MAX_VERTICES; r++){
        for(c = 0; c < MAX_VERTICES; c++){
            g->adj_mat[r][c] = 0;
        }
    }
}

// 정점 삽입 연산
void insert_vertex(GraphType* g, int v){
    // 그래프의 정점 개수 + 1이 정의된 MAX_VERTICES 보다 크면 오류
    if(((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "그래프: 정점의 개수 초과\n");
        return;
    }
    // 정점 추가는 n만 증가시켜주면 된다. (현 예는 정적 배열이므로)
    g->n++;
}

// 간선 삽입 연산
void insert_edge(GraphType* g, int start, int end){
    if(start >= g->n || end >= g->n){
        fprintf(stderr, "그래프: 정점 번호 오류\n");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

// 인접행렬 출력 함수
void print_adj_mat(GraphType* g){
    for(int i = 0; i < g->n; i++){
        for(int j = 0; j < g->n; j++){
            printf("%2d ", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
	GraphType *g;
	g = (GraphType *)malloc(sizeof(GraphType));
	
    init_graph(g);

	for(int i=0;i<4;i++){
	    insert_vertex(g, i);
    }

	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	print_adj_mat(g);

	free(g);
}
