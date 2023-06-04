#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 10
#define MAX_VERTICES 50

typedef int element;

typedef struct {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

// 오류 함수
void error(char *message){
    fprintf(stderr, "%s", message);
    exit(1);
}

// 큐 초기화
void queue_init(QueueType *q){
    q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType *q){
    return q->front == q->rear;
}

// 포화 상태 검출 함수
int is_full(QueueType *q){
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 삽입 함수
void enqueue(QueueType *q, element item){
    if(is_full(q)){
        error("큐: 포화 상태\n");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}

// 삭제 함수.
element dequeue(QueueType *q){
    if(is_empty(q)){
        error("큐: 공백 상태\n");
        exit(1);
    }
    q->front = ((q->front - 1) % MAX_QUEUE_SIZE);
    return q->queue[q->front];
}

////////////////// 인접 행렬로 구현된 너비 우선 탐색 //////////////////

typedef struct GraphType{
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int visited[MAX_VERTICES];

// 그래프 초기화
void init_graph(GraphType *g){
    int r, c;
    g->n = 0;
    for(r = 0; r < MAX_VERTICES; r++){
        for(c = 0; c < MAX_VERTICES; c++){
            g->adj_mat[r][c] = 0;
        }
    }
}

// 정점 삽입 연산
void insert_vertex(GraphType *g, int v){
    if((g->n) + 1 > MAX_VERTICES){
        fprintf(stderr, "정점 개수 초과\n");
        return;
    }
    g->n++; // 정점의 삽입은 정점 개수의 증가로서만 구현된다.
}

// 간선 삽입 연산
void insert_edge(GraphType *g, int start, int end){
    // 간선의 양 정점 번호가 최대 정점 개수보다 크면 오류.
    if(start >= g->n || end >= g->n){
        fprintf(stderr, "간선을 잇는 정점의 번호 오류\n");
        return;
    }
    // 인접 행렬으로 구현된 그래프이므로 양방향 전부 간선이 있음을 표시해 주어야 한다.
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
    printf("%d %d\n", g->adj_mat[start][end], g->adj_mat[end][start]);
}

void bfs_mat(GraphType* g, int v){
    
    printf("ok");
    QueueType *q = (QueueType *)malloc(sizeof(QueueType));
    queue_init(q);  // 큐 초기화
    visited[v] = TRUE;  // 시작 정점 v의 방문 표시.
    printf("%d 방문 -> ", v);
    enqueue(q, v);  // 시작 정점을 큐에 저장.
    
    // 큐가 공백 상태가 될 때까지 반복.
    while(!is_empty(q)){
        v = dequeue(q); // 큐에서 정점을 추출.
        // 인접 정점 탐색
        for(int w = 0; w < g->n; w++){
            // 시작 정점 v와 이어진 간선의 반대 정점 w가 있고(1로 나타내어짐),
            // visited 배열에 해당 정점 w가 존재하지 않는다면
            if(g->adj_mat[v][w] && !visited[w]){
                visited[w] = TRUE; // 정점 w의 방문 표시.
                printf("%d 방문 -> ", w);
                enqueue(q,w); // v의 인접 정점인 w를 큐에 삽입.
            }
        }
    }
    free(q);
}

////////////////// 인접 리스트로 구현된 너비 우선 탐색 //////////////////

typedef struct GraphNode {
    int vertex;
    struct GraphNode *link;
}GraphNode;

typedef struct GraphType_adj_list {
    int n;
    GraphNode *adj_list[MAX_VERTICES];
}GraphType_adj_list;

void init_graph_adj_list(GraphType_adj_list *g){
    g->n = 0;
    for(int i = 0; i < MAX_VERTICES; i++){
        g->adj_list[i] = NULL;
    }
}

void insert_vertex_adj_list(GraphType_adj_list *g){
    if(((g->n) + 1) > MAX_VERTICES){
        fprintf(stderr, "정점의 개수 초과\n");
        return;
    }
    // 인접행렬로 구현된 BFS와 마찬가지로 정점의 삽입은 개수의 증가 뿐이다.
    g->n++;
}

void insert_edge_adj_list(GraphType_adj_list *g, int u, int v){
    GraphNode *node;
    if(u >= g->n || v >= g->n){
        fprintf(stderr, "정점의 번호가 정점의 개수와 불일치\n");
        return;
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

void bfs_list(GraphType_adj_list* g, int v){
    GraphNode *w = (GraphNode*)malloc(sizeof(GraphNode));
    QueueType *q = (QueueType*)malloc(sizeof(QueueType));
    
    queue_init(q);    // 큐의 초기화
    visited[v] = TRUE;  //  첫번째 정점 v 방문 표시
    printf("%d 방문 -> ", v);
    enqueue(q, v);  // 시작 정점을 큐에 삽입
    while (!is_empty(q)){   // 큐가 소진 될 때까지 실행
        v = dequeue(q);
        // 정점의 인접 리스트 끝까지 탐색.
        for(w = g->adj_list[v]; w; w = w->link){
            // 정점의 인접 리스트 중 아직 방문하지 않은 정점이 있다면
            if(!visited[w->vertex]){
                visited[w->vertex] = TRUE;  // 해당 정점의 방문 표시
                printf("%d 방문 -> ", w->vertex);
                enqueue(q, w->vertex);  // 해당 정점을 큐에 삽입.
            }
        }
    }
    free(w);
    free(q);
}

int main(void)
{
    /////// 인접 행렬로 구현한 BFS ///////

	GraphType *g;
	g = (GraphType *)malloc(sizeof(GraphType));
	init_graph(g);
	for (int i = 0; i<6; i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 2);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 0, 4);
	insert_edge(g, 4, 5);
	insert_edge(g, 1, 5);

    /////// 인접 리스트로 구현한 BFS ///////

    GraphType_adj_list *g_adj_list 
    = (GraphType_adj_list*)malloc(sizeof(GraphType_adj_list));

    init_graph_adj_list(g_adj_list);

	for (int i = 0; i<6; i++)
		insert_vertex_adj_list(g_adj_list);
	insert_edge_adj_list(g_adj_list, 0, 2);
	insert_edge_adj_list(g_adj_list, 2, 1);
	insert_edge_adj_list(g_adj_list, 2, 3);
	insert_edge_adj_list(g_adj_list, 0, 4);
	insert_edge_adj_list(g_adj_list, 4, 5);
	insert_edge_adj_list(g_adj_list, 1, 5);

	// printf("너비 우선 탐색 - 인접 행렬\n");
	// bfs_mat(g, 0);
	// printf("\n");

	printf("너비 우선 탐색 - 인접 리스트\n");
    bfs_list(g_adj_list, 0);
    printf("\n");

	free(g);
    free(g_adj_list);

	return 0;
}
