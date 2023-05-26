#include<stdio.h>
#include<stdlib.h>

#define FILE_LEN 959
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

#pragma warning(disable:4996)

//////////////////////////////// 구조체, 정의 시작 //////////////////////////////

// 파일에서 읽은 데이터
typedef struct {
    int me;
    int you;
    float love;
} Data;


typedef struct {
	Data heap[FILE_LEN];
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

// heap 삽입
void insert_love_max_heap(HeapType* h, Data item){
    // i = 현재 heap의 요소 개수
    int i;
    i = ++(h->heap_size);

    // 트리를 거슬러 올라가며 부모 노드와 비교
    // item.love (자식 노드 = 현재 노드) > h->heap[i / 2].love (부모 노드)
    // heap 에서 (자식 노드 / 2) 는 부모노드의 인덱스이다.
    while((i != 1) && (item.love > h->heap[i / 2].love)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}

// heap 삭제
Data delete_love_max_heap(HeapType* h){
    int parent, child;
    Data item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while(child <= h->heap_size) {
        // 현재 노드의 자식노드 중 더 큰 노드 찾기
        if((child < h->heap_size) && (h->heap[child].love) < h->heap[child + 1].love){
            child++;
        }
        if(temp.love >= h->heap[child].love) break;

        // 한 단계 아래 이동
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

void heap_sort(Data data[], int n){
    int i;
    HeapType* h;
    h = create();

    init_heap(h);

    for (i = 0; i < n; i++){
        insert_love_max_heap(h, data[i]);
        printf("insert: me[%d] you[%d] love[%f]\n", data[i].me, data[i].you, data[i].love);
    }
    for(i = (n-1); i >= 0; i--){
        data[i] = delete_love_max_heap(h);
        printf("delete: me[%d] you[%d] love[%f]\n", data[i].me, data[i].you, data[i].love);
    }
    free(h);
}

//////////////////////////////// priority queue (힙 정렬) 끝 //////////////////////////////

//////////////////////////////// 친밀도 계산 시작 //////////////////////////////

void delete_data(Data* data, int* size, int index){
    if (index < 0 || index >= *size) {
        printf("유효하지 않은 인덱스입니다.\n");
        return;
    }

    // 삭제할 요소 이후의 요소들을 한 칸씩 앞으로 당김
    for (int i = index; i < (*size - 1); i++) {
        data[i] = data[i + 1];
    }

    // 배열의 크기를 1 감소시킴
    (*size)--;
}

void calculate_love(Data* data){
    int total = 0;
    for(int i = 0; i < FILE_LEN; i++){
        for(int j = 0; j < FILE_LEN; j++){
            // j_you가 데이터를 처음부터 읽으며 i_me와 같은 데이터를 찾는다.(양 방향 love 찾기)
            if (data[i].me == data[j].you && data[i].you == data[j].me){
                float love = (data[i].love + data[j].love) / 2;
                // 둘의 평균으로 love 변경.
                data[i].love = love; 
                data[j].love = love;
                printf("양방향 love [%d] <-[love: %f]-> [%d]\n", data[i].me, love, data[i].you);
                total++;
            }
            // // 단 방향 love
            // else if (data[i].me == data[j].you && data[i].you != data[j].me){
            //     float love = (data[i].love + 11) / 2;
            //     printf("단방향 love [%d] [love: %f]-> [%d]\n", data[i].me, love, data[i].you);
            //     total++;
            // }
        }
    }
    printf("total = [%d]\n", total);
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
        // printf("me: %d, you: %d, love: %f\n", data[i].me, data[i].you, data[i].love);
        i++;
    }
    printf("FILE legth: [%d]\n", i);
    
    // 파일 닫기.
    fclose(fp);
}


// void cal_love(Data* heap, Data* data){
//     for(int i = 0; i < FILE_LEN; i++){
//         int jump = 0;
//         for(int j = i; j < FILE_LEN; j++){
//             // 같은 me 인 경우를 0~99 까지의 heap에 삽입.
//             if(data[i].me == data[j].me){
//                 //heap의 인덱스는 me로 설정 (me : 학생 0~99)
//                 heap[data[i].me].me = data[i].me;
//                 heap[data[i].me].you[j] = data[j].you;
//                 heap[data[i].me].love[j] = data[j].love;
//                 // printf("i, j = [%d, %d] heap[%d] 에 데이터 추가: me[%d], you[%d], love[%f]\n", i, j, data[i].me, heap[data[i].me].me, heap[data[i].me].you[j], heap[data[i].me].love[j]);
//                 jump += 1;
//             }
//             else if(data[i].me != data[j].me){
//                 // printf("data[i].me [%d] != data[j].me [%d]\n", data[i].me, data[j].me);
//                 // printf("jump[%d]\n\n", jump);
//                 i = i + jump - 1;
//                 break;
//             }
//         }
//     }
// }

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
    // printf("------------변경후 data----------");
    heap_sort(data, FILE_LEN);
    // for(int i = 0; i < FILE_LEN; i++){
    //     printf("%f ", data[i].love);
    // }
    return 0;
    // print_data(data);
}