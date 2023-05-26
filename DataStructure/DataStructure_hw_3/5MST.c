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

// void insert_love_max_heap(HeapType* h, Data data){
//     int i;
//     i = ++(h->heap_size);

//     // // 트리를 거슬러 올라가며 부모 노드와 비교
//     // while((i != 1) && (data.love > h->heap[i / 2].love)){

//     // }
// }


//////////////////////////////// priority queue (힙 정렬) //////////////////////////////

//////////////////////////////// 친밀도 계산 시작 //////////////////////////////
void calculate_love(Data* data){

    for(int i = 0; i < FILE_LEN; i++){
        for(int j = 0; j < FILE_LEN; j++){
            // j_you가 데이터를 처음부터 읽으며 i_me와 같은 데이터를 찾는다.(양 방향 love 찾기)
            if (data[i].me == data[j].you && data[i].you == data[j].me){
                float love = (data[i].love + data[j].love) / 2;
                printf("양방향 love [%d] <-[love: %f]-> [%d]\n", data[i].me, love, data[i].you);
            }
        }
    }

}
//////////////////////////////// 친밀도 계산 끝 //////////////////////////////

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
        printf("me: %d, you: %d, love: %f\n", data[i].me, data[i].you, data[i].love);
        i++;
    }
    printf("FILE legth: [%d]\n", i);
    
    // 파일 닫기.
    fclose(fp);
}


void cal_love(element* heap, Data* data){
    for(int i = 0; i < FILE_LEN; i++){
        int jump = 0;
        
        for(int j = i; j < FILE_LEN; j++){
            // 같은 me 인 경우를 0~99 까지의 heap에 삽입.
            if(data[i].me == data[j].me){
                //heap의 인덱스는 me로 설정 (me : 학생 0~99)
                heap[data[i].me].me = data[i].me;
                heap[data[i].me].you[j] = data[j].you;
                heap[data[i].me].love[j] = data[j].love;
                // printf("i, j = [%d, %d] heap[%d] 에 데이터 추가: me[%d], you[%d], love[%f]\n", i, j, data[i].me, heap[data[i].me].me, heap[data[i].me].you[j], heap[data[i].me].love[j]);
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

// void print_heap_data(HeapType* h){
//     printf("heap_data 출력\n");
//     int i = 0;
//     for(int i = 0; i < 99; i++){
//         printf("me: [%d]\n", h->heap[i].me);
//         int j = 0;
//         while(h->heap[i].you[j] != NULL){
//             printf("you : [%d], love : [%f]\n", h->heap[i].you[j], h->heap[i].love[j]);
//             j++;
//         }
//     }
// }

//////////////////////////////// FILE 저장 및 친밀도 계산 (끝) //////////////////////////////

int main(void){
    HeapType *h = create();
    Data data[FILE_LEN];
    printf("데이터 생성\n");
    read_data_to_struct(data);
    printf("데이터 읽음\n");
    // cal_love(h->heap, data);
    calculate_love(data);
}