#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 50

/////////////////////////////////// 인접 행렬 ///////////////////////////////////
// typedef struct GraphType_mat {
//     int n; //정점의 개수
//     int adj_mat[MAX_VERTICES][MAX_VERTICES];
// }GraphType_mat;

// // 그래프 초기화
// void init_graph(GraphType_mat* g){
//     int r, c;
//     g->n = 0;
    
//     for(r = 0; r < MAX_VERTICES; r++){
//         for(c = 0; c < MAX_VERTICES; c++){
//             g->adj_mat[r][c] = 0;
//         }
//     }
// }

// // 정점 삽입 연산
// void insert_vertex(GraphType_mat* g, int v){
//     // 그래프의 정점 개수 + 1이 정의된 MAX_VERTICES 보다 크면 오류
//     if(((g->n) + 1) > MAX_VERTICES) {
//         fprintf(stderr, "그래프: 정점의 개수 초과\n");
//         return;
//     }
//     // 정점 추가는 n만 증가시켜주면 된다. (현 예는 정적 배열이므로)
//     g->n++;
// }

// // 간선 삽입 연산
// void insert_edge(GraphType_mat* g, int start, int end){
//     if(start >= g->n || end >= g->n){
//         fprintf(stderr, "그래프: 정점 번호 오류\n");
//         return;
//     }
//     g->adj_mat[start][end] = 1;
//     g->adj_mat[end][start] = 1;
// }

// // 인접행렬 출력 함수
// void print_adj_mat(GraphType_mat* g){
//     for(int i = 0; i < g->n; i++){
//         for(int j = 0; j < g->n; j++){
//             printf("%2d ", g->adj_mat[i][j]);
//         }
//         printf("\n");
//     }
// }

// int main(){
// 	GraphType *g;
// 	g = (GraphType *)malloc(sizeof(GraphType));
	
//     init_graph(g);

// 	for(int i=0;i<4;i++){
// 	    insert_vertex(g, i);
//     }

// 	insert_edge(g, 0, 1);
// 	insert_edge(g, 0, 2);
// 	insert_edge(g, 0, 3);
// 	insert_edge(g, 1, 2);
// 	insert_edge(g, 2, 3);
// 	print_adj_mat(g);

// 	free(g);
// }

/////////////////////////////////// 인접 리스트 ///////////////////////////////////

typedef struct GraphNode{
    int vertex;
    struct GraphNode* link;
}GraphNode;

typedef struct GraphType {
    int n; // 정점의 개수
    GraphNode* adj_list[MAX_VERTICES]; // 인접 리스트
}GraphType;

// 그래프 초기화
void init_graph(GraphType* g){
    int v;
    g->n = 0;
    // 인접 리스트 초기화
    for(v = 0; v < MAX_VERTICES; v++){
        g->adj_list[v] = NULL;
    }
}

// 정점 삽입 연산 (행렬과 같음)
void insert_vertex(GraphType* g, int v){
    if(((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "그래프: 정점의 개수 초과\n");
        return;
    }
    g->n++;
}

// 간선 삽입 연산, v를 u의 인접리스트에 삽입한다.
// 정점 u에 간선 (u, v)를 삽입하는 연산은 
// 정점 u의 인접 리스트에 간선을 나타내는 노드를 하나 생성하여 삽입하면 된다.
// 위치는 상관이 없으므로 삽입을 쉽게하기 위해 연결리스트의 처음에 삽입.
void insert_edge(GraphType* g, int u, int v){
    GraphNode* node;
    if(u >= g->n || v >= g->n){
        fprintf(stderr, "그래프: 정점 번호 오류\n");
        return;
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

// 인접 리스트로 구현된 그래프 출력 함수.
void print_adj_list(GraphType* g){
    for(int i = 0; i < g->n; i++){
        GraphNode* p = g->adj_list[i];
        printf("정점 %d의 인접 리스트 ", i);
        while (p != NULL){
            printf("-> %d ", p->vertex);
            p = p->link;
        }
        printf("\n");        
    }
}

int main(void){
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init_graph(g);
    for(int i = 0; i < 4; i++){
        insert_vertex(g, i);
    }
    insert_edge(g, 0 ,1);
    insert_edge(g, 1 ,0);
    insert_edge(g, 0 ,2);
    insert_edge(g, 2 ,0);
    insert_edge(g, 0 ,3);
    insert_edge(g, 3 ,0);
    insert_edge(g, 1 ,2);
    insert_edge(g, 2 ,1);
    insert_edge(g, 2 ,3);
    insert_edge(g, 3 ,2);
    print_adj_list(g);
    free(g);
    return 0;
}