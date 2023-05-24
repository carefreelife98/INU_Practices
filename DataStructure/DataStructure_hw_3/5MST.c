#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

#pragma warning(disable:4996)

//////////////////////////////// Graph (인접행렬) //////////////////////////////

typedef struct GraphType {
	int n;	// 정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

// 그래프 초기화 
void init(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r<MAX_VERTICES; r++)
		for (c = 0; c<MAX_VERTICES; c++)
			g->weight[r][c] = 0;
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

//////////////////////////////// PRIM 알고리즘 //////////////////////////////
typedef struct {
    int me;
    int you;
    int love;
} Data;

void read_data(Data *data) {
    FILE *fp;
    fp = fopen("students2.txt", "r"); // 읽기 모드로 파일을 연다.

    printf("fopen\n");
    // 파일에서 데이터를 읽어와 구조체에 저장.
    char buf[30];
    int i = 0;
    printf("while start\n");
    while (fgets(buf, 30, fp) != NULL) {
        // 각 행의 데이터를 구조체에 저장
        fscanf(fp, buf, "%d %d %d", &data[i].me, &data[i].you, &data[i].love);
        printf("me: %d, you: %d, love: %d\n", data[i].me, data[i].you, data[i].love);
        i++;
    }
    printf("while end\n");
    
    // 파일 닫기.
    fclose(fp);
}
void print_students_data(Data* data) {
    printf("\n ------------------파일 읽기 시작-------------------- \n");
    // printf("me\tyou\tlove\n");
    for (int i = 0; i < MAX_VERTICES; i++) {
        printf("%d\t%d\t%d\n", data[i].me, data[i].you, data[i].love);
    }
    printf(" ------------------파일 읽기 끝-------------------- \n\n");
}

int main(void){
    printf("시작\n");
    Data data[MAX_VERTICES];
    printf("데이터 생성\n");
    read_data(data);
    printf("데이터 읽음\n");
    print_students_data(data);
}