#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphNode{
    int vertex;
    struct GraphNode *link;
}GraphNode;

typedef struct GraphType {
    int n; // 정점의 개수
    GraphNode *adj_list[MAX_VERTICES];
}GraphType;

// 그래프 초기화
void init_graph(GraphType *g){
    g->n = 0;
    for(int v = 0; v < g->n; v++){
        g->adj_list[v] = NULL;
    }
}

void insert_vertex(GraphType *g, int v){
    if(((g->n) + 1) > MAX_VERTICES){
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

// 간선 삽입 연산, v를 u의 인접 리스트에 삽입한다.
void insert_edge(GraphType *g, int u, int v){
    GraphNode *node;
    if(u >= g->n || v >= g->n){
        fprintf(stderr, "그래프 : 정점 번호 오류");
        return;
    }
    node = (GraphNode *)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
    element stack[MAX_STACK_SIZE];
    int top;
}StackType;

// 스택 초기화 함수
void init_stack(StackType *s){
    s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType *s){
    return s->top == -1;
}

// 포화 상태 검출 함수
int is_full(StackType *s){
    return (s->top == (MAX_STACK_SIZE - 1));
}

// 삽입 함수
void push(StackType *s, element item){
    if(is_full(s)){
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    s->top++;
    s->stack[s->top] = item;
}

// 삭제 함수
element pop(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "스택이 공백 상태입니다.\n");
        exit(1);
    }
    else return s->stack[(s->top)--];
}

// 위상 정렬 알고리즘
int in_degree[MAX_VERTICES];

int topo_sort(GraphType *g){
    
    int i;
    StackType s;
    GraphNode *node;

    int *in_degree = (int*)malloc(g->n * sizeof(int));
    // 진입 차수 배열 초기화
    for(i = 0; i < g->n; i++){
        in_degree[i] = 0;
    }
    // 모든 정점의 진입 차수 계산
    for(i = 0; i < g->n; i++){
        node = g->adj_list[i];
        while(node != NULL){
            in_degree[node->vertex]++;
            node = node->link;
        }
    }

    // 진입 차수가 0인 정점을 스택에 삽입
    init_stack(&s);
    for(i = 0; i < g->n; i++){
        if(in_degree[i] == 0){
            push(&s, i);
        }
    }

    // 위상 순서를 생성
    while(!is_empty(&s)){
        int w;
        w = pop(&s);
        printf("정점 %d ->", w);    // 정점 출력
        node = g->adj_list[w]; // 각 정점의 진입 차수를 변경
        while (node != NULL){
            int u = node->vertex;
            in_degree[u]--; // 진입 차수 1 감소

            if(in_degree[u] == 0){  // 내차수 0이 될 시 스택에 삽입.
                push(&s, u);
            }
            node = node->link;  // 다음 정점
        }
    }
    free(in_degree);
    printf("\n");
    return (i == g->n); // 반환 값이 1이면 성공, 0이면 실패.
}

int main(void) {
	GraphType *g = (GraphType*)malloc(sizeof(GraphType));

	init_graph(g);
	insert_vertex(g, 0);	insert_vertex(g, 1);
	insert_vertex(g, 2);	insert_vertex(g, 3);
	insert_vertex(g, 4);	insert_vertex(g, 5);
	//정점 0의 인접 리스트 생성
	insert_edge(g, 0, 2);	insert_edge(g, 0, 3);
	//정점 1의 인접 리스트 생성
	insert_edge(g, 1, 3);	insert_edge(g, 1, 4);
	//정점 2의 인접 리스트 생성
	insert_edge(g, 2, 3);	insert_edge(g, 2, 5);
	//정점 3의 인접 리스트 생성
	insert_edge(g, 3, 5);	
    //정점 4의 인접 리스트 생성
	insert_edge(g, 4, 5);
	//위상 정렬 
	topo_sort(g);

    free(g);

	return 0;
}
