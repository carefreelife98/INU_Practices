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
	struct Edge edges[FILE_LEN];
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
void insert_edge(GraphType_* g, int start, int end, float w)
{
	g->edges[g->n].me = start;
	g->edges[g->n].you = end;
	g->edges[g->n].love = w;
	g->n++; // 정점 개수 + 1
    // if(g->edges[g->n].love != 0 && (g->edges[g->n].me != 0 || g->edges[g->n].you != 0))
    // printf("edge 추가 : [%d] <---[%f]---> [%d]\n", g->edges[g->n].me, g->edges[g->n].love, g->edges[g->n].you);
}

typedef struct vertices{
    int v[20];
    int n;
}vertices;

void insert_G_ver(vertices* group, int ver){
	group->v[group->n] = ver;
	group->n++;
    
}

int visited[MAX_VERTICES];

void insert_mst_edge(GraphType_ *MST, int me, int you, float love){
    if(MST != NULL){
        MST->edges[MST->n].me = me;
        MST->edges[MST->n].you = you;
        MST->edges[MST->n].love = love;
        MST->n++;
    }
}

vertices* bfs_list(GraphType *g, int v, GraphType_ *MST){
    GraphNode* w;
    vertices* group_vertices = (vertices*)malloc(5 * sizeof(vertices));
    QueueType* q = (QueueType*)malloc(sizeof(QueueType));
    int sum = 0;
    int g_n = 0;
    
    queue_init(q);
    visited[v] = TRUE;
    insert_G_ver(&group_vertices[g_n], v);

    printf("%d 방문 -> \n", v);
    enqueue(q, v);
    while (!is_empty(q)){
        v = dequeue(q);
        printf("%d 에서 인접 노드 방문 시작: \n", v);

        for(w = g->adj_list[v]; w; w = w->link){
            if(!visited[w->vertex] && w->love <= 6.5){
                visited[w->vertex] = TRUE;

                printf("[love: %f] %d 방문 -> \n", w->love, w->vertex);
                insert_G_ver(&group_vertices[g_n], w->vertex);
                enqueue(q, w->vertex);
                if(w != NULL){
                    insert_mst_edge(&MST[g_n], v, w->vertex, w->love);
                }
                
                if(MST[g_n].n == 20){
                    g_n++;
                }
            }
        }
    }
    for(int i = 0; i < MAX_VERTICES; i++){
        if(visited[i] == 1) sum++;
    }
    if (sum == 100) printf("총 방문 수: [%d]\n", sum);
    free(q);
    return group_vertices;
}

//////////////////////////////// 너비 우선 탐색 끝 //////////////////////////////



//////////////////////////////// priority queue (힙 정렬) 시작 //////////////////////////////

// // 배열 요소를 교환하는 함수
void swap_(Edge* a, Edge* b) {
    Edge temp = *a;
    *a = *b;
    *b = temp;
}

// // 최대 힙 구조를 유지하는 함수
void heapify_(Edge arr[], int n, int i) {
    int largest = i;    // 루트 노드
    int left = 2 * i + 1;    // 왼쪽 자식 노드
    int right = 2 * i + 2;    // 오른쪽 자식 노드
    // 왼쪽 자식과 비교
    if (left < n && arr[left].love > arr[largest].love)
        largest = left;
    // 오른쪽 자식과 비교
    if (right < n && arr[right].love > arr[largest].love)
        largest = right;
    // 루트 노드가 자식보다 작지 않다면 교환
    if (largest != i) {
        swap_(&arr[i], &arr[largest]);
        // 변경된 부분을 대상으로 다시 힙 구조 유지
        heapify_(arr, n, largest);
    }
}

// // Heap Sort 함수
void heapSort_(Edge arr[], int n) {
    // 초기 힙 구조 생성
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify_(arr, n, i);
    // 힙 구조에서 요소를 하나씩 제거하며 정렬
    for (int i = n - 1; i > 0; i--) {
        // 최대값(루트)을 배열의 마지막 요소와 교환
        swap_(&arr[0], &arr[i]);
        // 힙 구조 유지
        heapify_(arr, i, 0);
    }
}
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
            // 위 for문에서 check = 1 로 체크되지 않은 단방향 love는 11을 더해 평균을 구한다.
            data[i].love = (data[i].love + 11) / 2;
            // printf("단방향 [%d] <- [%f] -> [%d] ", data[i].me, data[i].love, data[i].you);
            total++;
            // if(total % 2 == 0){
            //         printf("\n");
            // }
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

// kruskal의 최소 비용 신장 트리 프로그램
void kruskal(GraphType_ *g, int n)
{
	int edge_accepted = 0;	// 현재까지 선택된 간선의 수	
	int uset, vset;			// 정점 u와 정점 v의 집합 번호
	struct Edge e;
	set_init(g->n);				// 집합 초기화
    // int n = sizeof(g->edges) / sizeof(g->edges[0]);
	heapSort_(g->edges, n);
    printf("크루스칼 최소 신장 트리 알고리즘 \n");
	int i = 0;
	while (edge_accepted < n - 1)	// 간선의 수 < (n-1)
	{
		e = g->edges[i];
		uset = set_find(e.me);		// 정점 u의 집합 번호 
		vset = set_find(e.you);		// 정점 v의 집합 번호
		if (uset != vset) {			// 서로 속한 집합이 다르면
			printf("[%d] 간선 (%d,%d) %f 선택", i, e.me, e.you, e.love);
			edge_accepted++;
            printf("[%d]\n", edge_accepted);
			set_union(uset, vset);	// 두개의 집합을 합친다.
		}
		i++;
	}
}

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

void extractEdgesInRange(const GraphType_* graph, const vertices* range, GraphType_ *MST) {

    for (int i = 0; i < graph->n; i++) {
        int start = graph->edges[i].me;
        int end = graph->edges[i].you;

        int startInRange = 0;
        int endInRange = 0;

        for (int j = 0; j < range->n; j++) {
            if (start == range->v[j]) {
                startInRange = 1;
            }
            if (end == range->v[j]) {
                endInRange = 1;
            }
        }

        if (startInRange && endInRange) {
            insert_mst_edge(MST, start, end, graph->edges[i].love);
        }
    }
}
// 1. 크루스칼로 전체 MST를 찾고, 가장 큰 가중치를 가진 간선 4개와 해당 노드를 크루스칼 알고리즘에서 메인함수의 배열에 전달.
// 2. K_graph의 edge에서 첫번째 간선을 삭제. -> 간선을 잇던 두 노드를 기준으로 prim 알고리즘.
// 3. 두 그래프에서 다음 간선을 찾는다. -> 찾으면 과정2 반복.


/// @brief 성공한 알고리즘
// 1. 파일로부터 데이터를 읽는다.
// 2. 서로 언급한 경우 둘의 love를 더해서 weight을 정하고 한명만 언급한 경우 해당 love에 11을 더해 나누어 weight를 정한다.
// 3. 인접 리스트를 사용하여 전체 노드 100개가 포함된 그래프를 생성한다. 
// 4. 그래프를 너비우선탐색을 통해 순회하며 bfs알고리즘 내부에서 적당량 친하다고 할 수 있는 6.5를 기준으로 그룹을 나눈다.
// 5. 그룹을 나눈 것은 vertices 타입에 한 그룹 당 20개의 vertex값을 넣어준 것. (총 5개 그룹)
// 6. vertices에 1~5 그룹의 정점 정보가 담겨있으므로 3번의 그래프에 저장된 그래프와 비교하여 그룹 당 할당된 정점의 범위 내에 있는 간선 전부를 새로운 그래프 MST_group에 넣는다.
// 7. 이로써 모든 간선의 최대 가중치가 6.5 이하인 그룹 5개의 그래프가 생성 되었고, 각 그래프에 kruskal 알고리즘을 사용하여 MST를 구했습니다.

int main(void){
    // HeapType *h = create();
    Data data[FILE_LEN];

    read_data_to_struct(data);
    
    calculate_love(data);

    /////// 100개 노드 그래프 생성 시작 ///////
    GraphType_ *g = (GraphType_*)malloc(sizeof(GraphType_));

    graph_init(g);

    for(int i = 0; i < FILE_LEN; i++){
        insert_edge(g, data[i].me, data[i].you, data[i].love);
        insert_edge(g, data[i].you, data[i].me, data[i].love);
    }

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

    GraphType_ *MST_group = (GraphType_*)malloc(5 * sizeof(GraphType_));
    vertices* group_vertices = bfs_list(graph, 0, MST_group);
    
    for(int i = 0; i < 5; i++){
        printf("=======================Kruskal group[%d]=======================\n", i + 1);
        extractEdgesInRange(g, &group_vertices[i], &MST_group[i]);
        kruskal(&MST_group[i], group_vertices[i].n);
    }
  
    return 0;
}


/// 도출된 간선들 중 10의 가중치를 가진 간선 4개 있는데 그거를 삭제. -> 5개의 mst 도출.

// 1. kruskal로 하나의 전체 MST 그래프를 찾아 해당 간선과 정점의 정보를 찾는다.
// 2. 가장 큰 가중치를 가진 간선 4개를 삭제한다.
// 3. 삭제 간선을 잇는 두 정점을 기준으로 두 개의 새로운 그래프가 된다.
// 4. 인접리스트를 사용한 새로운 그래프와 노드를 생성한다.
// 5. 위와 같은 방식으로 진행 시 58, 73, 98, 99 각각 하나씩의 노드를 가진 그래프(?) 4개와 나머지 노드 전체의 그래프 1개로 나뉜다.
// 6. 따라서 2. 에서 바로 가중치순의 간선 삭제를 하지 않고 4. 까지 진행 후 가장 많은 인접 정점을 가진 정점의 가중치가 가장 높은 간선을 삭제한다.
