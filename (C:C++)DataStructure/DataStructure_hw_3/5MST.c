#include<stdio.h>
#include<stdlib.h>

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
    // int index;
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
//////////////////////////////// 구조체, 정의 끝 //////////////////////////////


//////////////////////////////// 그래프 생성 시작 //////////////////////////////

// 그래프 초기화
void init_graph(GraphType* g){
    int v;
    g->n = 0;
    for(v = 0; v < MAX_VERTICES; v++){
        g->adj_list[v] = NULL;
    }
}

// 정점 삽입 연산
void insert_graph_vertex(GraphType* g, int v){
    if(((g->n) + 1) > MAX_VERTICES){
        fprintf(stderr, "그래프: 정점의 개수 초과\n");
        return;
    }
    g->n++;
}

void insert_graph_edge(GraphType* g, int u, int v, float love){
    GraphNode* node;
    if(u >= g->n || v >= g->n){
        printf("g->n : [%d], u = [%d], v =[%d]\n", g->n, u, v);
        fprintf(stderr, "그래프: 정점 번호 오류\n");
        return;
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    node->love = love;
    g->adj_list[u] = node;

    // // 무방향 그래프이므로 반대 방향으로의 간선도 추가.
    // node = (GraphNode*)malloc(sizeof(GraphNode));
    // node->vertex = u;
    // node->link = g->adj_list[v];
    // g->adj_list[v] = node;

    // printf("%d -> 간선 추가 \n", node->me);
}

void print_adj_list(GraphType* g){
    int num = 0;
    printf("그래프의 노드 개수: [%d]\n", g->n);
    for(int i = 0; i < g->n; i++){
        GraphNode* p = g->adj_list[i];
        printf("정점 %d의 인접 리스트: ", i);
        while(p != NULL){
            printf("-> %d", p->vertex);
            p = p->link;
            num++;
        }
        printf("\n");
    }
    printf("%d 개\n", num);
}
//////////////////////////////// 그래프 생성 끝 //////////////////////////////

//////////////////////////////// 너비 우선 탐색 시작 //////////////////////////////
#define MAX_QUEUE_SIZE 100
typedef int element;

//큐 타입
typedef struct{
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;

void error(char* message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//큐 초기화
void queue_init(QueueType* q){
    q->front = q->rear = 0;
}

int is_empty(QueueType* q){
    return (q->front == q->rear);
}

//포화 상태 검출 함수
int is_full(QueueType* q){
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//삽입 함수
void enqueue(QueueType* q, element item){
    if(is_full(q)){
        error("큐가 포화상태\n");
    }    
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}

element dequeue(QueueType* q){
    if(is_empty(q)){
        error("큐가 공백\n");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}

#define TRUE 1
#define FALSE 0

int visited[MAX_VERTICES];
void bfs_list(GraphType *g, int v){
    GraphNode* w;
    QueueType* q = (QueueType*)malloc(sizeof(QueueType));

    queue_init(q);
    visited[v] = TRUE;
    printf("%d 방문 -> ", v);
    enqueue(q, v);
    while (!is_empty(q)){
        v = dequeue(q);
        for(w = g->adj_list[v]; w; w = w->link){
            if(!visited[w->vertex]){
                visited[w->vertex] = TRUE;
                printf("%d 방문 -> ", w->vertex);
                enqueue(q, w->vertex);
            }
        }
    }
}

//////////////////////////////// 너비 우선 탐색 끝 //////////////////////////////



//////////////////////////////// priority queue (힙 정렬) 시작 //////////////////////////////
typedef struct {
    Edge heap[MAX_VERTICES];
    int heap_size;
}HeapType_;
HeapType_* create(){
    return (HeapType_*)malloc(sizeof(HeapType_));
}

void init_heap(HeapType_* h){
    h->heap_size = 0;
}

void insert_max_heap(HeapType_* h, Edge e){
    int i;
    i = ++(h->heap_size);

    while((i != 1) && (e.love > h->heap[i / 2]. love)){
        h->heap[i] = h->heap[i / 2];
        i/= 2;
    }
    h->heap[i] = e;
}

Edge delete_max_heap(HeapType_* h){
    int parent, child;
    Edge item, temp;
    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size){
        if ((child < h->heap_size) && (h->heap[child].love) < h->heap[child + 1].love)
            child++;
        if(temp.love >= h->heap[child].love) break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

// void print_data(Edge* data){
//     printf("Data data[FILE_len] 출력\n");
//     for(int i = 0; i < FILE_LEN; i++){
//         printf("data[%d] me:[%d] you:[%d] love:[%f]\n", i, data[i].me, data[i].you, data[i].love);
//         // if(i % 3 == 0){
//         //     printf("\n");
//         // }
//     }
// }
// 배열 요소를 교환하는 함수
void swap(GraphNode* a, GraphNode* b) {
    GraphNode temp = *a;
    *a = *b;
    *b = temp;
}

// 최대 힙 구조를 유지하는 함수
void heapify(GraphNode* arr[], int n, int i) {
    int largest = i;    // 루트 노드
    int left = 2 * i + 1;    // 왼쪽 자식 노드
    int right = 2 * i + 2;    // 오른쪽 자식 노드

    // 왼쪽 자식과 비교
    if (left < n && arr[left]->love > arr[largest]->love)
        largest = left;

    // 오른쪽 자식과 비교
    if (right < n && arr[right]->love > arr[largest]->love)
        largest = right;

    // 루트 노드가 자식보다 작지 않다면 교환
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // 변경된 부분을 대상으로 다시 힙 구조 유지
        heapify(arr, n, largest);
    }
}

// Heap Sort 함수
void heapSort(GraphNode *arr[MAX_VERTICES], int n) {
    // 초기 힙 구조 생성
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 힙 구조에서 요소를 하나씩 제거하며 정렬
    for (int i = n - 1; i > 0; i--) {
        // 최대값(루트)을 배열의 마지막 요소와 교환
        swap(arr[0], arr[i]);

        // 힙 구조 유지
        heapify(arr, i, 0);
    }
}
// // 배열 요소를 교환하는 함수
// void swap(Edge* a, Edge* b) {
//     Edge temp = *a;
//     *a = *b;
//     *b = temp;
// }

// // 최대 힙 구조를 유지하는 함수
// void heapify(Edge arr[], int n, int i) {
//     int largest = i;    // 루트 노드
//     int left = 2 * i + 1;    // 왼쪽 자식 노드
//     int right = 2 * i + 2;    // 오른쪽 자식 노드
//     // 왼쪽 자식과 비교
//     if (left < n && arr[left].love > arr[largest].love)
//         largest = left;
//     // 오른쪽 자식과 비교
//     if (right < n && arr[right].love > arr[largest].love)
//         largest = right;
//     // 루트 노드가 자식보다 작지 않다면 교환
//     if (largest != i) {
//         swap(&arr[i], &arr[largest]);
//         // 변경된 부분을 대상으로 다시 힙 구조 유지
//         heapify(arr, n, largest);
//     }
// }

// // Heap Sort 함수
// void heapSort(Edge arr[], int n) {
//     // 초기 힙 구조 생성
//     for (int i = n / 2 - 1; i >= 0; i--)
//         heapify(arr, n, i);
//     // 힙 구조에서 요소를 하나씩 제거하며 정렬
//     for (int i = n - 1; i > 0; i--) {
//         // 최대값(루트)을 배열의 마지막 요소와 교환
//         swap(&arr[0], &arr[i]);
//         // 힙 구조 유지
//         heapify(arr, i, 0);
//     }
// }
//////////////////////////////// priority queue (힙 정렬) 끝 //////////////////////////////

//////////////////////////////// 친밀도 계산 시작 //////////////////////////////

// 파일에 저장된 양방향 및 단방향 love 계산 후 data에 저장됨.
// data에 저장된 노드, 간선을 제외 하고는 서로 언급도 되지 않은 관계이므로 잇지 않는다.
// data의 love를 기준으로 heap sort 하여 love가 작은(우선순위 최상) 순부터 정렬.
// 순차대로 우선순위(love)가 작은 data 의 학생(me, you)을 그룹화 (20 명씩)
// 그룹화를 어떻게 할 지 생각해보자.
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
//////////////////////////////// 친밀도 계산 끝 //////////////////////////////

//////////////////////////////// Kruskal (시작) //////////////////////////////
int parent[MAX_VERTICES];		// 부모 노드
// 초기화
void set_init(int n)
{
	for (int i = 0; i<n; i++) 
		parent[i] = -1;
}
// curr가 속하는 집합을 반환한다.
int set_find(int curr)
{
	if (parent[curr] == -1)
		return curr; 			// 루트 
	while (parent[curr] != -1) curr = parent[curr];
	return curr;
}
// 두개의 원소가 속한 집합을 합친다.
void set_union(int a, int b)
{
	int root1 = set_find(a);	// 노드 a의 루트를 찾는다. 
	int root2 = set_find(b);	// 노드 b의 루트를 찾는다. 
	if (root1 != root2) 	// 합한다. 
		parent[root1] = root2;
}

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
    // g->edges[g->n].index = index;
	g->n++; // 정점 개수 + 1
    // if(g->edges[g->n].love != 0 && (g->edges[g->n].me != 0 || g->edges[g->n].you != 0))
    // printf("edge 추가 : [%d] <---[%f]---> [%d]\n", g->edges[g->n].me, g->edges[g->n].love, g->edges[g->n].you);
}
// qsort()에 사용되는 함수
int compare(const void* a, const void* b)
{
	struct Edge* x = (struct Edge*)a;
	struct Edge* y = (struct Edge*)b;
	return (x->love - y->love);
}
// // kruskal의 최소 비용 신장 트리 프로그램
// void kruskal(GraphType_ *g)
// {
// 	int edge_accepted = 0;	// 현재까지 선택된 간선의 수	
// 	int uset, vset;			// 정점 u와 정점 v의 집합 번호
// 	struct Edge e;
// 	set_init(g->n);				// 집합 초기화
//     int n = sizeof(g->edges) / sizeof(g->edges[0]);
// 	heapSort(g->edges, n);
//     printf("크루스칼 최소 신장 트리 알고리즘 \n");
// 	int i = 0;
// 	while (edge_accepted < MAX_VERTICES - 1)	// 간선의 수 < (n-1)
// 	{
// 		e = g->edges[i];
// 		uset = set_find(e.me);		// 정점 u의 집합 번호 
// 		vset = set_find(e.you);		// 정점 v의 집합 번호
// 		if (uset != vset) {			// 서로 속한 집합이 다르면
// 			printf("[%d] 간선 (%d,%d) %f 선택", i, e.me, e.you, e.love);
// 			edge_accepted++;
//             printf("[%d]\n", edge_accepted);
// 			set_union(uset, vset);	// 두개의 집합을 합친다.
// 		}
// 		i++;
// 	}
// }

// void delete_low_priority_edge(Edge edges[], int* size, int index) {
//     if (index < 0 || index >= *size) {
//         printf("유효하지 않은 인덱스입니다.\n");
//         return;
//     }
//     for (int i = index; i < *size - 1; i++) {
//         edges[i] = edges[i + 1];
//     }
//     (*size)--;
// }

// kruskal의 최소 비용 신장 트리 프로그램
// void kruskal_return_arr(GraphType_ *g, Edge final[], Edge d_edge[])
// {
// 	int edge_accepted = 0;	// 현재까지 선택된 간선의 수	
// 	int uset, vset;			// 정점 u와 정점 v의 집합 번호
// 	struct Edge e;
// 	set_init(g->n);				// 집합 초기화
//     int n = sizeof(g->edges) / sizeof(g->edges[0]);
// 	heapSort(g->edges, n);
//     printf("크루스칼 최소 신장 트리 알고리즘 \n");
// 	int i = 0;
//     int E_num = 0;
// 	while (edge_accepted < MAX_VERTICES - 1)	// 간선의 수 < (n-1)
// 	{
// 		e = g->edges[i];
// 		uset = set_find(e.me);		// 정점 u의 집합 번호 
// 		vset = set_find(e.you);		// 정점 v의 집합 번호
// 		if (uset != vset) {			// 서로 속한 집합이 다르면
// 			printf("[%d] 간선 (%d,%d) %f 선택 ", i, e.me, e.you, e.love);
//             // 큰 가중치를 가진 4개의 간선을 찾아 인자로 받은 d_edge배열에 저장.
//             if(e.love >= 10 && E_num < 4){
//                 d_edge[E_num] = e;
//                 E_num++;
//             }
//             // 해당 MST의 간선을 최종 그래프가 될 간선의 배열(final)에 복사.
//             else{
//                 final[edge_accepted] = g->edges[i];
//                 printf("final 그래프 추가 최종 간선: index:[%d] me:[%d] you:[%d] love:[%f] ", final[edge_accepted].index, final[edge_accepted].me, final[edge_accepted].you, final[edge_accepted].love);
//             }
// 			edge_accepted++;
//             printf("[%d]\n", edge_accepted);
// 			set_union(uset, vset);	// 두개의 집합을 합친다.
// 		}
// 		i++;
// 	}
// }
void kruskal_return_arr(GraphType_ *g, Edge final[])
{
	int edge_accepted = 0;	// 현재까지 선택된 간선의 수	
	int uset, vset;			// 정점 u와 정점 v의 집합 번호
	struct Edge e;
    set_init(g->n);				// 집합 초기화
    int n = sizeof(g->edges) / sizeof(g->edges[0]);
	// heapSort(g->edges, n);
    printf("크루스칼 최소 신장 트리 알고리즘 \n");
	int i = 0;
    int E_num = 0;
	while (edge_accepted < MAX_VERTICES - 1)	// 간선의 수 < (n-1)
	{
		e = g->edges[i];
		uset = set_find(e.me);		// 정점 u의 집합 번호 
		vset = set_find(e.you);		// 정점 v의 집합 번호
		if (uset != vset) {			// 서로 속한 집합이 다르면
			// printf("[%d] 간선 (%d,%d) %f 선택 ", i, e.me, e.you, e.love);
            final[edge_accepted] = g->edges[i];
            printf("final[%d] 그래프 추가 최종 간선: me:[%d] you:[%d] love:[%f] ", edge_accepted, final[edge_accepted].me, final[edge_accepted].you, final[edge_accepted].love);
			edge_accepted++;
            printf("[%d]\n", edge_accepted);
			set_union(uset, vset);	// 두개의 집합을 합친다.
		}
		i++;
	}
}
void kruskal_return_arr_test(GraphType_ *g, Edge final[])
{
	int edge_accepted = 0;	// 현재까지 선택된 간선의 수	
	int uset, vset;			// 정점 u와 정점 v의 집합 번호
	struct Edge e;
    set_init(g->n);				// 집합 초기화
    int n = sizeof(g->edges) / sizeof(g->edges[0]);
	// heapSort(g->edges, n);
    printf("크루스칼 최소 신장 트리 알고리즘 \n");
	int i = 0;
    int E_num = 0;
	while (edge_accepted < MAX_VERTICES - 1)	// 간선의 수 < (n-1)
	{
		e = g->edges[i];
		uset = set_find(e.me);		// 정점 u의 집합 번호 
		vset = set_find(e.you);		// 정점 v의 집합 번호
		if (uset != vset) {			// 서로 속한 집합이 다르면
			// printf("[%d] 간선 (%d,%d) %f 선택 ", i, e.me, e.you, e.love);
            final[edge_accepted] = g->edges[i];
            printf("final[%d] 그래프 추가 최종 간선: me:[%d] you:[%d] love:[%f] ", edge_accepted, final[edge_accepted].me, final[edge_accepted].you, final[edge_accepted].love);
			edge_accepted++;
            printf("[%d]\n", edge_accepted);
			set_union(uset, vset);	// 두개의 집합을 합친다.
		}
		i++;
	}
}

//이렇게 하면 안됨. 간선이 아직 전부 추가되지 않아서 크루스칼이기 때문에 그래프가 완성 되어있지 않아서
//간선 삭제 한다고 이전 까지의 노드와 간선들이 하나의 그래프가 되는 것이 아님..
// void Grouping(GraphType_ group, int me, int you, float love){
//     insert_edge(&group, me, you, love);
// }
// void kruskal_grouping(GraphType_ *g, GraphType_ group[]){
// 	int edge_accepted = 0;	// 현재까지 선택된 간선의 수	
// 	int uset, vset;			// 정점 u와 정점 v의 집합 번호
// 	struct Edge e;
// 	set_init(g->n);				// 집합 초기화
//     int n = sizeof(g->edges) / sizeof(g->edges[0]);
// 	heapSort(g->edges, n);
//     printf("크루스칼 최소 신장 트리 알고리즘 \n");
// 	int i = 0;
//     int group_num = 0;
// 	while (edge_accepted < MAX_VERTICES - 1)	// 간선의 수 < (n-1)
// 	{
// 		e = g->edges[i];
// 		uset = set_find(e.me);		// 정점 u의 집합 번호 
// 		vset = set_find(e.you);		// 정점 v의 집합 번호
// 		if (uset != vset) {			// 서로 속한 집합이 다르면
//             // 마지막 그룹이면 어떤 조건에 해당되지 않고 전부 그룹에 추가. (최대 그룹이 5개이므로 간선 삭제 하면 안됨.)
//             if (group_num == 4){
//                 printf("[%d] 간선 (%d,%d) %f 선택", i, e.me, e.you, e.love);
//                 Grouping(group[group_num], e.me, e.you, e.love); // GraphType_ group[5] 배열의 요소인 그래프에 가중치가 10보다 작을 시 간선 추가.
//                 edge_accepted++;
//                 printf("[%d]\n", edge_accepted);
//                 set_union(uset, vset);	// 두개의 집합을 합친다.
//             }
//             // 마지막 그룹이 아니고, 가중치가 10보다 작다면 그룹에 추가.
//             else if(e.love < 10){             
//                 printf("[%d] 간선 (%d,%d) %f 선택", i, e.me, e.you, e.love);
//                 Grouping(group[group_num], e.me, e.you, e.love); // GraphType_ group[5] 배열의 요소인 그래프에 가중치가 10보다 작을 시 간선 추가.
//                 edge_accepted++;
//                 printf("[%d]\n", edge_accepted);
//                 set_union(uset, vset);	// 두개의 집합을 합친다.
//             }else{
//                 printf("[%d] 간선[%d-[%f]-%d]의 가중치가 10보다 크므로 간선 삭제하여 그룹핑 합니다.\n", i, e.me, e.love ,e.you);
//                 group_num++; // 간선의 가중치가 10보다 같거나 클 시 간선 삽입을 하지 않고 다음 그래프로 그룹핑.
//             }
// 		}
// 		i++;
// 	}
// }

//////////////////////////////// Kruskal (끝) //////////////////////////////
int* findTop4Nodes(GraphType* graph) {
    int* nodeCounts = (int*)calloc(graph->n, sizeof(int));

    // 각 노드의 인접 노드 개수 계산
    for (int i = 0; i < graph->n; i++) {
        GraphNode* curr = graph->adj_list[i];
        while (curr != NULL) {
            nodeCounts[curr->vertex]++;
            curr = curr->link;
        }
    }
    // 상위 5개 노드 인덱스를 찾기 위한 배열 생성
    int* top5Nodes = (int*)malloc(5 * sizeof(int));
    for (int i = 0; i < 4; i++) {
        int maxIndex = 0;
        int maxCount = 0;
        for (int j = 0; j < graph->n; j++) {
            if (nodeCounts[j] > maxCount) {
                maxCount = nodeCounts[j];
                maxIndex = j;
            }
        }
        top5Nodes[i] = maxIndex;
        nodeCounts[maxIndex] = 0; // 이미 선택한 노드는 카운트를 0으로 설정하여 다음 최댓값을 찾을 때 제외
    }
    free(nodeCounts);
    return top5Nodes;
}

// 인접리스트의 연결리스트 노드 삭제.
// 노드를 삭제하는 함수
void deleteNode(GraphType* graph, int vertex) {
    if (vertex < 0 || vertex >= graph->n) {
        printf("유효하지 않은 노드입니다.\n");
        return;
    }
    // 인접 리스트에서 노드와 연결된 간선 삭제
    GraphNode* currNode = graph->adj_list[vertex];
    while (currNode != NULL) {
        int adjVertex = currNode->vertex;
        GraphNode* prevNode = graph->adj_list[adjVertex];
        // 첫 번째 노드인 경우
        if (prevNode->vertex == vertex) {
            graph->adj_list[adjVertex] = prevNode->link;
            free(prevNode);
        } else {
            // 중간이나 마지막 노드인 경우
            while (prevNode->link != NULL) {
                if (prevNode->link->vertex == vertex) {
                    GraphNode* deleteNode = prevNode->link;
                    prevNode->link = deleteNode->link;
                    free(deleteNode);
                    break;
                }
                prevNode = prevNode->link;
            }
        }
        currNode = currNode->link;
    }
    // 인접 리스트에서 해당 노드 삭제
    GraphNode* deleteNode = graph->adj_list[vertex];
    graph->adj_list[vertex] = deleteNode->link;
    free(deleteNode);
    printf("노드 %d가 삭제되었습니다.\n", vertex);
}
// void delete_node(GraphType* g, int index){
//     GraphType *temp = g;
//     int max = 0;
//     // 최대 가중치 노드 찾기
//     while(temp->adj_list[index] != NULL){
//         if(temp->adj_list[index]->love > max){
//             max = temp->adj_list[index]->love;
//         }
//         temp->adj_list[index] = temp->adj_list[index]->link;
//     }
//     printf("max:[%f]\n", max);
//     // 해당 노드 삭제
//     while(g->adj_list[index] != NULL){
//         // 다음 노드가 max와 같으면 다음 노드 삭제
//         if(g->adj_list[index]->link->love == max){
//             g->adj_list[index]->link = g->adj_list[index]->link->link;
//             printf("삭제 노드 v = [%d], love = [%f]", g->adj_list[index]->vertex)
//         }
//         g->adj_list[index] = g->adj_list[index]->link;
//     }
// }




//////////////////////////////// test //////////////////////////////
int groupAssignment[100];
// Function to compare edges based on their weights (used for sorting)
int compareEdges(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*)a;
    struct Edge* edgeB = (struct Edge*)b;
    return edgeA->love - edgeB->love;
}
// Function to find the parent of a vertex
int findParent(int vertex) {
    if (parent[vertex] == -1)
        return vertex;
    while(parent[vertex] != -1) vertex = parent[vertex];
    return vertex;
}
// Function to perform union of two sets
void unionSets(int* parent, int x, int y) {
    int parentX = findParent(x);
    int parentY = findParent(y);
    parent[parentX] = parentY;
}
// Function to divide vertices into 5 groups with the lowest weight
void divideIntoGroups(Edge edges[], int numEdges, int numVertices) {
    // Sort the edges in ascending order based on their weights
    // qsort(edges, numEdges, sizeof(struct Edge), compareEdges);
    // heapSort(edges, 99);
    // Create an array to keep track of the group assignment for each vertex
    // 각 정점의 그룹 할당 여부를 담은 배열 생성 및 -1로 초기화. (-1 : 그룹 할당 되지 않음)
    for (int i = 0; i < numVertices; i++) {
        groupAssignment[i] = -1; // Initialize group assignment to -1 (no group)
    }
    
    // 5개의 그룹을 저장하기 위한 배열 group 생성.
    int groups[5];
    printf("그룹 배열 생성 및 초기화 완료\n");

    int parentStart;
    int parentEnd;
    
    // love(가중치)를 기준으로 오름차순 정렬된 edge를 순회.
    for (int i = 0; i < numEdges; i++) {
        
        //edge 하나를 매개변수로 받은 edges 배열에서 꺼낸다.
        struct Edge currentEdge = edges[i];
        printf("Edge: [%d] [%f] [%d]\n", edges[i].me, edges[i].love, edges[i].you);

        // edge 가 cycle을 생성하게 되는지 parent 배열을 사용하여 검사.
        // cycle을 생성한다면 continue 하여 그룹에 포함시키지 않고 다음 edge를 탐색한다.
        parentStart = findParent(currentEdge.me);
        parentEnd = findParent(currentEdge.you);
        if (parentStart == parentEnd)
            continue;

        // 그룹 중 가장 낮은 가중치가 쌓인 그룹에 현재 간선을 추가한다.
        int groupIndex = -1;
        float minWeight = 2174583.0;
        
        for (int j = 0; j < 5; j++) {   // 그룹 number (1,2,3,4,5)
            float cumulativeWeight = 0;
            for (int k = 0; k < numVertices; k++) { // 각 정점(0~99)의 그룹 할당 여부 확인을 groupAssignment[100] 배열을 통해 검사.
                if (groupAssignment[k] == j)    // 만약 정점 k 가 그룹 j에 할당되어 있으면, 
                    cumulativeWeight += edges[k].love;  // 정점 k의 간선 가중치를 cumulative weight 에 추가.
            }
            if (cumulativeWeight < minWeight) {
                minWeight = cumulativeWeight;
                groupIndex = j;
            }
        }
        groupAssignment[currentEdge.me] = groupIndex;
        groupAssignment[currentEdge.you] = groupIndex;
        printf("finish\n");
    }

    // 아직 그룹에 할당 되지 않은 정점이 있으면 가장 낮은 가중치를 가진 그룹에 추가.
    for (int i = 0; i < numVertices; i++) {
        if (groupAssignment[i] == -1) {
            int groupIndex = -1;
            float minWeight = 2174583.0;
            for (int j = 0; j < 5; j++) {
                float cumulativeWeight = 0;
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
}

//////////////////////////////// test //////////////////////////////
//////////////////////////////// FILE 저장 및 친밀도 계산 (시작) //////////////////////////////

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
    // GraphType_ *g = (GraphType_*)malloc(sizeof(GraphType_));

    // graph_init(g);

    // for(int i = 0; i < FILE_LEN; i++){
    //     insert_edge(g, data[i].me, data[i].you, data[i].love, i);
    // }
    // printf("정점 삽입 완료 : %d 개\n", g->n);
    // printf("간선 삽입 완료\n");

    /////// 100개 노드 그래프 생성 끝 ///////

    // 최종 그래프 5개의 간선 정보를 가진 구조체 배열. 노드가 100개이므로 간선은 99개.
    // Edge final[99];
    
    // kruskal_return_arr(g, final);

    // int size_final = sizeof(final) / sizeof(final[0]);

    // // printf("4개 간선의 삭제 후 현재 final 배열:\n");
    // for (int i = 0; i < size_final; i++){
    //     printf("i:[%d] me:[%d] you:[%d] love:[%f] \n", i, final[i].me, final[i].you, final[i].love);
    // }

    // 인접리스트를 이용한 새로운 그래프 생성
    GraphType *graph;
    graph = (GraphType*)malloc(sizeof(GraphType));
    // 그래프 초기화
    init_graph(graph);
    printf("그래프 초기화\n");
    // 정점 추가
    for (int i = 0; i < 100; i++){
        insert_graph_vertex(graph, i);
    }
    printf("vertex 추가\n");

    int size = sizeof(graph->adj_list) / sizeof(graph->adj_list[0]);
    // 간선 추가
    for(int i = 0; i < FILE_LEN; i++){
        insert_graph_edge(graph, data[i].me, data[i].you, data[i].love);
        insert_graph_edge(graph, data[i].you, data[i].me, data[i].love);
    }

    print_adj_list(graph);

    bfs_list(graph, 0);
    // heapSort(graph->adj_list, size);

    // printf("힙정렬 후 adj_list: \n");
    // for(int i = 0; i < graph->n; i++){
    //     GraphNode* temp = graph->adj_list[i];
    //     while(temp != NULL){
    //         printf(" [%d %f %d] -> ", i, temp->love, temp->vertex);
    //         temp = temp->link;
    //     }
    //     printf("\n");
    // }

    // int *top4Nodes = findTop4Nodes(graph);
    // printf("\n가장 많은 인접 노드를 가진 노드의 인덱스 (상위 4개):\n");
    // for (int i = 0; i < 4; i++) {
    //     printf("%d ", top4Nodes[i]);
    // }
    // printf("\n");
    // printf("최대 가중치 노드 삭제\n");
    // for(int i = 0; i < 4; i++){
    //     printf("[%d]", i);
    //     deleteNode(graph, top4Nodes[i]);
    // }
    // printf("삭제 후 인접 리스트:\n");
    // print_adj_list(graph);
    return 0;
}


/// 도출된 간선들 중 10의 가중치를 가진 간선 4개 있는데 그거를 삭제. -> 5개의 mst 도출.

// 1. kruskal로 하나의 전체 MST 그래프를 찾아 해당 간선과 정점의 정보를 찾는다.
// 2. 가장 큰 가중치를 가진 간선 4개를 삭제한다.
// 3. 삭제 간선을 잇는 두 정점을 기준으로 두 개의 새로운 그래프가 된다.
// 4. 인접리스트를 사용한 새로운 그래프와 노드를 생성한다.
// 5. 위와 같은 방식으로 진행 시 58, 73, 98, 99 각각 하나씩의 노드를 가진 그래프(?) 4개와 나머지 노드 전체의 그래프 1개로 나뉜다.
// 6. 따라서 2. 에서 바로 가중치순의 간선 삭제를 하지 않고 4. 까지 진행 후 가장 많은 인접 정점을 가진 정점의 가중치가 가장 높은 간선을 삭제한다.
