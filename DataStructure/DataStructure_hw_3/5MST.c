#include<stdio.h>
#include<stdlib.h>

#define FILE_LEN 959
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

// 힙 정렬 우선순위 큐
#define MAX_ELEMENT 100


#pragma warning(disable:4996)

//////////////////////////////// 구조체, 정의 시작 //////////////////////////////

// 그래프
typedef struct GraphType {
	int n;	// 정점의 개수
	float weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// 파일에서 읽은 데이터
typedef struct {
    int me;
    int you;
    float love;
} Data;

// 우선 순위 큐에 삽입될 비방향 간선의 최종 친밀도
typedef struct {
    int me;
    int you[20]; // 한명당 다른 사람에 대한 친밀도 최대 20개 정도 설정.
    float love[20]; // 해당 사람에 대한 친밀도
} element;

// 계산된 학생 0 ~ 99 까지의 최종 친밀도가 저장된 heap.
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

//////////////////////////////// 구조체, 정의 끝 //////////////////////////////

//////////////////////////////// priority queue (힙 정렬) 시작 //////////////////////////////

// 동적 메모리 할당
HeapType* create(){
    return (HeapType*)malloc(sizeof(HeapType));
}

void init_heap(HeapType *h){
    h->heap_size = 0;
}

//////////////////////////////// priority queue (힙 정렬) //////////////////////////////

//////////////////////////////// Graph (인접행렬) //////////////////////////////

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

// 그래프 초기화 
void init(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r<MAX_VERTICES; r++)
		for (c = 0; c<MAX_VERTICES; c++)
			g->weight[r][c] = INF;
}

// 정점 삽입 연산
void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}

// 간선 삽입 연산
void insert_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g->weight[start][end] = 1;
	g->weight[end][start] = 1;
}

// 간선 삽입 연산
void insert_edge_with_data(GraphType* g, Data* data)
{
    for(int i = 0; i < 1000; i++){
        if (data->me >= g->n || data->you >= g->n) {
            fprintf(stderr, "그래프: 정점 번호 오류");
            return;
        }
        g->weight[data->me][data->you] = 1;
        g->weight[data->you][data->me] = 1;
    }
}

//////////////////////////////// Graph (인접행렬) //////////////////////////////



//////////////////////////////// PRIM 알고리즘 //////////////////////////////

// 최소 dist[v] 값을 갖는 정점을 반환
int get_min_vertex(int n)
{
	int v, i;
	for (i = 0; i <n; i++)
		if (!selected[i]) {
			v = i;
			break;
		}
	for (i = 0; i < n; i++)
		if (!selected[i] && (distance[i] < distance[v])) v = i;
	return (v);
}

//
void prim(GraphType* g, int s)
{
	int i, u, v;

	for (u = 0; u<g->n; u++)
		distance[u] = INF;
	distance[s] = 0;
	for (i = 0; i<g->n; i++) {
		u = get_min_vertex(g->n);
		selected[u] = TRUE;
		if (distance[u] == INF) return;
		printf("정점 %d 추가\n", u);
		for (v = 0; v<g->n; v++)
			if (g->weight[u][v] != INF)
				if (!selected[v] && g->weight[u][v]< distance[v])
					distance[v] = g->weight[u][v];
	}
}

//////////////////////////////// PRIM 알고리즘 (끝) //////////////////////////////

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
    printf("while start\n");
    while (fgets(buf, 30, fp) != NULL) {
        // 각 행의 데이터를 구조체에 저장
        sscanf(buf, "%d %d %f", &data[i].me, &data[i].you, &data[i].love);
        // printf("me: %d, you: %d, love: %f\n", data[i].me, data[i].you, data[i].love);
        i++;
    }
    printf("FILE legth: [%d]\n", i);
    
    // 파일 닫기.
    fclose(fp);
}
// void print_students_data(Data* data) {
//     printf("\n ------------------파일 읽기 시작-------------------- \n");
//     // printf("me\tyou\tlove\n");
//     for (int i = 0; i < 1000; i++) {
//         printf("%d\t%d\t%f\n", &data[i].me, &data[i].you, &data[i].love);
//     }
//     printf(" ------------------파일 읽기 끝-------------------- \n\n");
// }

// // 두 학생 사이의 친밀도 계산 - heap[] 에 바로 삽입
// void cal_love(element element[], Data* data){

//     // i번째 me 를 기준으로 love 계산하여 heap[] 에 저장.
//     for(int i = 0; i < 1000; i++){
//         for(int j = 0; j < 1000; j++){
//             // me가 you에 대한 love 가 없지만 you가 me에게 love 있는 경우
//             if(data[i].me == data[j].you && data[i].you != data[j].me){
//                 element[i].me = data[i].me;
//                 element[i].you[j] = data[j].you;
//                 element[i].love[j] = (11 + data[j].love) / 2;
//                 printf("\n1.단방향 love i:[%d], j:[%d] [%f]\n", i, j, element[i].love[j]);
//             }
//             // 두 데이터가 같은 두 학생을 잇는 간선이라면, 친밀도 계산
//             else if(data[i].me == data[j].you && data[i].you == data[j].me){
//                 element[i].me = data[i].me;
//                 element[i].you[j] = data[j].you;
//                 element[i].love[j] = (data[i].love + data[j].love) / 2;        
//                 printf("\n2.양 방향 love i:[%d], j:[%d] [%f]\n", i, j, element[i].love[j]);
//             }
//             // // me가 you에 대한 love 가 있지만 you가 me에게 love 없는 경우
//             // else {
//             //     element[i].me = data[i].me;
//             //     element[i].you[j] = data[j].you;
//             //     element[i].love[j] = (data[i].love + 11) / 2;
//             //     printf("3.단방향 love %f\n", element[i].love[j]);
//             // }
//         }
//     }
// }

void cal_love(element heap[], Data* data){
    for(int i = 0; i < FILE_LEN; i++){
        int jump = 0;
        
        for(int j = i; j < FILE_LEN; j++){
            // 같은 me 인 경우를 0~99 까지의 heap에 삽입.
            if(data[i].me == data[j].me){
                //heap의 인덱스는 me로 설정 (me : 학생 0~99)
                heap[data[i].me].me = data[i].me;
                heap[data[i].me].you[j] = data[j].you;
                heap[data[i].me].love[j] = data[j].love;
                printf("i, j = [%d, %d] heap[%d] 에 데이터 추가: me[%d], you[%d], love[%f]\n", i, j, data[i].me, heap[data[i].me].me, heap[data[i].me].you[j], heap[data[i].me].love[j]);
                jump += 1;
            }
            else if(data[i].me != data[j].me){
                // printf("data[i].me [%d] != data[j].me [%d]\n", data[i].me, data[j].me);
                // printf("jump[%d]\n\n", jump);
                i = i + jump - 1;
                break;
            }
            
        }
    }
}

void print_data(Data* data){
    printf("Data data[FILE_len] 출력\n");
    for(int i = 0; i < FILE_LEN; i++){
        printf("data[%d] , me:[%d] , you:[%d], love:[%f]\n", i, data[i].me, data[i].you, data[i].love);
    }
}

void print_heap_data(HeapType* h){
    printf("heap_data 출력\n");
    int i = 0;
    for(int i = 0; i < 99; i++){
        printf("me: [%d]\n", h->heap[i].me);
        int j = 0;
        while(h->heap[i].you[j] != NULL){
            printf("you : [%d], love : [%f]\n", h->heap[i].you[j], h->heap[i].love[j]);
            j++;
        }
    }
    
}

//////////////////////////////// FILE 저장 및 친밀도 계산 (끝) //////////////////////////////

int main(void){
    GraphType *g;
    HeapType *h = create();
    Data data[FILE_LEN];
    printf("데이터 생성\n");
    read_data_to_struct(data);
    printf("데이터 읽음\n");
    // print_students_data(data);
    cal_love(h->heap, data);
    // print_data(data);
    printf("cal_love 완료\n");
    print_heap_data(h);
}