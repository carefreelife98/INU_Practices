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

typedef struct Edge {			// 간선을 나타내는 구조체
	int me, you;
    float love;
} Edge;
typedef struct GraphType_ {
	int n;	// 정점의 개수
	struct Edge edges[2 * MAX_VERTICES];
} GraphType_;
//////////////////////////////// 구조체, 정의 끝 //////////////////////////////


//////////////////////////////// 그래프 생성 시작 //////////////////////////////
// typedef struct GraphNode {
//     int me;
//     struct GraphNode* link;
// }GraphNode;

typedef struct GraphType {
    int n; // 정점의 개수
    Data* adj_list[MAX_VERTICES];
}GraphType;

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

void insert_graph_edge(GraphType* g, int u, int v){
    Data* node;
    if(u >= g->n || v >= g->n){
        fprintf(stderr, "그래프: 정점 번호 오류\n");
        return;
    }
    node = (Data*)malloc(sizeof(Data));
    node->me = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
    // printf("%d -> 간선 추가 \n", node->me);
}

void print_adj_list(GraphType* g){
    int num = 0;
    for(int i = 0; i < g->n; i++){
        Data* p = g->adj_list[i];
        printf("정점 %d의 인접 리스트: ", i);
        while(p != NULL){
            printf("-> %d", p->me);
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
void bfs_list(GraphType* g, int v){
    Data* w;
    QueueType* q;

    queue_init(q);
    visited[v] = TRUE;
    printf("%d 방문 -> ", v);
    enqueue(q, v);
    while (!is_empty(q)){
        v = dequeue(q);
        for(w = g->adj_list[v]; w; w= w->link){
            if(!visited[w->me]){
                visited[w->me] = TRUE;
                printf("%d 방문 -> ", w->me);
                enqueue(q, w->me);
            }
        }
    }
}

//////////////////////////////// 너비 우선 탐색 끝 //////////////////////////////



//////////////////////////////// priority queue (힙 정렬) 시작 //////////////////////////////

void print_data(Edge* data){
    printf("Data data[FILE_len] 출력\n");
    for(int i = 0; i < FILE_LEN; i++){
        printf("data[%d] me:[%d] you:[%d] love:[%f]\n", i, data[i].me, data[i].you, data[i].love);
        // if(i % 3 == 0){
        //     printf("\n");
        // }
    }
}
// 배열 요소를 교환하는 함수
void swap(Edge* a, Edge* b) {
    Edge temp = *a;
    *a = *b;
    *b = temp;
}

// 최대 힙 구조를 유지하는 함수
void heapify(Edge arr[], int n, int i) {
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
        swap(&arr[i], &arr[largest]);

        // 변경된 부분을 대상으로 다시 힙 구조 유지
        heapify(arr, n, largest);
    }
}

// Heap Sort 함수
void heapSort(Edge arr[], int n) {
    // 초기 힙 구조 생성
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 힙 구조에서 요소를 하나씩 제거하며 정렬
    for (int i = n - 1; i > 0; i--) {
        // 최대값(루트)을 배열의 마지막 요소와 교환
        swap(&arr[0], &arr[i]);

        // 힙 구조 유지
        heapify(arr, i, 0);
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
            // 위 for문에서 twin = 1 로 체크되지 않은 단방향 love는 11을 더해 평균을 구한다.
            data[i].love = (data[i].love + 11) / 2;
        }
    }
    printf("total = [%d]\n", total);
}
//////////////////////////////// 친밀도 계산 끝 //////////////////////////////

//////////////////////////////// 5개 그룹화 (시작) //////////////////////////////


void check_init(int check[]){
    // check 배열을 0 으로 초기화
    for(int i = 0; i < MAX_VERTICES; i++) {
        check[i] = 0;
    }
}

// 1. 배열 check 를 만들어 check 하는 방법.
// 2. 학생이 가지고 있는 데이터 check에 표시하여 그룹화 하는 방법.

void print_not_checked(int check[]){
    for(int i = 0; i < MAX_VERTICES; i++){
        if(check[i] == 0){
            printf("not checked : [%d]\n", i);
        }
    }
}
// 그냥 넣지 말고 data 배열의 가장 앞부터 시작해서 you를 타고 you의 가장 친한 친구.. -> 일렬로 된 그래프가 될 수 있다.

// // 아니면 각 학생들의 count를 세서 가장 높은 count를 가진 top 5 학생을 기준으로 5개의 그룹 짜기?
// void groupingV2(Data data[]){
//     Data main_student[5];
//     int result = 0;
//     float love_result = 300.0;
//     for(int i = 0; i < FILE_LEN; i++){
//         int total = 0;
//         float love_sum = 0.0;
//         for(int j = 0; j < FILE_LEN; j++){
//             if(data[i].me == data[j].me){
//                 love_sum += data[j].love;
//                 total++;
//             }
//             if(data[i].me == data[j].you){
//                 love_sum += data[j].love;
//                 total++; 
//             }
//         }
//         if(total >= result && love_sum <= love_result){
//             result = total;
//             love_result = love_sum;
//         }
//         printf("[%d] 학생의 언급 수 : [%d], 총 love : [%f]  ", data[i].me, total, love_sum);
//         if(i % 2 == 0){
//             printf("\n");
//         }
//     }
//     printf("total = [%d], love = [%f] \n", result, love_result);
// }


// void groupingV1(Data data[], Data group[], int check[], int group_num){
//     // check[] : 0 ~ 99 까지의 학생의 소속이 있는지 확인하는 배열
//     // check 배열을 탐색하여 인덱스에 대응하는 데이터(group_num)가 존재하면 해당 인덱스와 같은 학생은 소속이 이미 있는 것.
//     int index = 0;
//     for(int i = 0; i < FILE_LEN; i++){
//         // 오름차순으로 정렬된 데이터의 me, you 값과 check 배열의 인덱스(0~99)를 통해
//         // 기존에 그룹화 된 학생인지 판별.
//         if(check[data[i].me] == 0 && check[data[i].you] == 0){
//             // if(index == MAX_GROUP - 1){
//             //     printf("그룹[%d]에 인원이 꽉 찼으므로 종료합니다: [%d]명\n", group_num, index + 1);
//             //     break;
//             // }
//             // 아직 소속이 없는 학생이라면 그룹에 추가.
//             group[index] = data[i];
//             printf("그룹[%d] %d번째 멤버 추가: [%d] <---love:[%f]---> [%d]\n", group_num, index, data[i].me, data[i].love, data[i].you);
//             // check 배열에 그룹의 번호를 check
//             check[data[i].me] = group_num;
//             check[data[i].you] = group_num;
//             index++;
//         }
//     }
    // for(int i = 0; i < MAX_VERTICES; i++){
    //     if(check[i] == 0){
    //         for(int j = 0; j < FILE_LEN; j++){
    //             if((data[j].me == i || data[j].you == i) && check[data[j].me] == 0 && check[data[j].you == 0]){
    //                 group[index] = data[i];
    //                 printf("그룹[%d] %d번째 멤버 추가: [%d] <---love:[%f]---> [%d]\n", group_num, index, data[j].me, data[j].love, data[j].you);
    //                 check[data[j].me] = group_num;
    //                 check[data[j].you] = group_num;
    //                 // if(index == 49){
    //                 //     printf("그룹[%d]에 인원이 꽉 찼으므로 종료합니다: [%d]명\n", group_num, index + 1);
    //                 //     return;
    //                 // }
    //                 index++;
    //             }
    //         }
    //     }
    // }
// }

//////////////////////////////// 5개 그룹화 (끝) //////////////////////////////

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
	}
}
// 간선 삽입 연산
void insert_edge(GraphType_* g, int start, int end, float w)
{
	g->edges[g->n].me = start;
	g->edges[g->n].you = end;
	g->edges[g->n].love = w;
	g->n++; // 정점 개수 + 1

    if(g->edges[g->n].love != 0 && (g->edges[g->n].me != 0 || g->edges[g->n].you != 0))
        printf("edge 추가 : [%d] <---[%f]---> [%d]\n", g->edges[g->n].me, g->edges[g->n].love, g->edges[g->n].you);
}
// qsort()에 사용되는 함수
int compare(const void* a, const void* b)
{
	struct Edge* x = (struct Edge*)a;
	struct Edge* y = (struct Edge*)b;
	return (x->love - y->love);
}
// kruskal의 최소 비용 신장 트리 프로그램
void kruskal(GraphType_ *g)
{
	int edge_accepted = 0;	// 현재까지 선택된 간선의 수	
	int uset, vset;			// 정점 u와 정점 v의 집합 번호
	struct Edge e;
	
	set_init(g->n);				// 집합 초기화
    int n = sizeof(g->edges) / sizeof(g->edges[0]);
	heapSort(g->edges, n);
	printf("크루스칼 최소 신장 트리 알고리즘 \n");
	int i = 0;

	while (edge_accepted < MAX_VERTICES - 1)	// 간선의 수 < (n-1)
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

//////////////////////////////// Kruskal (끝) //////////////////////////////

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

int main(void){
    // HeapType *h = create();
    Data data[FILE_LEN];

    read_data_to_struct(data);

    calculate_love(data);

    // print_data(data);

    /////// 100개 노드 그래프 생성 시작 ///////
    GraphType_ *g = (GraphType_*)malloc(sizeof(GraphType_));

    graph_init(g);

    // for(int i = 0; i < MAX_VERTICES; i++){
    //     insert_graph_vertex(g, i);
    // }
    for(int i = 0; i < FILE_LEN; i++){
        insert_edge(g, data[i].me, data[i].you, data[i].love);
    }
    printf("정점 삽입 완료 : %d 개\n", g->n);
    printf("간선 삽입 완료\n");
    // print_adj_list(g);
    /////// 100개 노드 그래프 생성 끝 ///////
    kruskal(g);
    // for(int i = 0; i < MAX_VERTICES; i++){
    
    // }

    return 0;
}


/// 도출된 간선들 중 10의 가중치를 가진 간선 4개 있는데 그거를 삭제. -> 5개의 mst 도출.