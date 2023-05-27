#include<stdio.h>
#include<stdlib.h>

#define FILE_LEN 959
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L
#define MAX_GROUP 20

#pragma warning(disable:4996)

//////////////////////////////// 구조체, 정의 시작 //////////////////////////////

// FILE로 읽은 데이터
typedef struct {
    int me;
    int you;
    float love;
    int check;
} Data;

typedef struct {
	Data heap[FILE_LEN];
	int heap_size;
} HeapType;

//////////////////////////////// 구조체, 정의 끝 //////////////////////////////

//////////////////////////////// priority queue (힙 정렬) 시작 //////////////////////////////

// // 동적 메모리 할당
// HeapType* create(){
//     return (HeapType*)malloc(sizeof(HeapType));
// }

// void init_heap(HeapType *h){
//     h->heap_size = 0;
// }

// // void print_heap_data(Data data[]){
// //     printf("heap_data 출력\n");
// //     // heap 은 index : [0]을 사용하지 않으므로 heap[1]부터 시작
// //     for(int i = 0; i < FILE_LEN; i++){
// //         printf("me: [%d], you : [%d], love : [%f]   ", h->heap[i].me, h->heap[i].you, h->heap[i].love);
// //         if (i % 3 == 0) {
// //             printf("\n");
// //         }
// //     }
// // }

void print_data(Data* data){
    printf("Data data[FILE_len] 출력\n");
    for(int i = 0; i < FILE_LEN; i++){
        printf("data[%d] me:[%d] you:[%d] love:[%f]\n", i, data[i].me, data[i].you, data[i].love);
        // if(i % 3 == 0){
        //     printf("\n");
        // }
    }
}

// // heap 삽입
// void insert_love_max_heap(HeapType* h, Data item){
//     // i = 현재 heap의 요소 개수
//     int i;
//     i = ++(h->heap_size);
//     // 트리를 거슬러 올라가며 부모 노드와 비교
//     // item.love (자식 노드 = 현재 노드) > h->heap[i / 2].love (부모 노드)
//     // heap 에서 (자식 노드 / 2) 는 부모노드의 인덱스이다.
//     while((i != 1) && (item.love > h->heap[i / 2].love)) {
//         h->heap[i] = h->heap[i / 2];
//         i /= 2;
//     }
//     h->heap[i] = item;
// }

// // heap 삭제
// Data delete_love_max_heap(HeapType* h){
//     int parent, child;
//     Data item, temp; 
//     item = h->heap[1]; // 루트 노드(최대 love값)의 반환을 위하여 item변수에 옮김
//     temp = h->heap[(h->heap_size)--]; 
//     parent = 1; // 루트노드의 인덱스는 항상 1
//     child = 2; // 루트 노드의 왼쪽 자식부터 비교 시작. (루트노드의 왼쪽 자식의 인덱스는 항상 2)
//     printf("heap size: [%d]", h->heap_size);
//     // 히프트리를 벗어나지 않은 범위 이면,
//     while(child <= h->heap_size) {
//         // 현재 노드의 자식노드 중 더 큰 노드 찾기
//         // 오른쪽 자식이 더 크다면 
//         if((child < h->heap_size) && (h->heap[child].love) < h->heap[child + 1].love){
//             child++;
//         }
//         if(temp.love >= h->heap[child].love) break;
//         // 한 단계 아래 이동
//         h->heap[parent] = h->heap[child];
//         parent = child;
//         child *= 2;
//     }
//     h->heap[parent] = temp;
//     return item;
// }

// void heap_sort(Data data[], int n){
//     int i;
//     HeapType* h;
//     h = create();
//     init_heap(h);
//     printf("------------------------ insert max heap ------------------------\n");
//     for (i = 0; i < n; i++){
//         insert_love_max_heap(h, data[i]);
//         // printf("insert: me[%d] you[%d] love[%f]    ", data[i].me, data[i].you, data[i].love);
//         // if (i % 3 == 0) {
//         //     printf("\n");
//         // }
//     }
//     // printf("------------------------ print heap data ------------------------\n");
//     // print_data(data);
//     printf("------------------------ delete max heap ------------------------\n");
//     for(i = (n-1); i >= 0; i--){
//         data[i] = delete_love_max_heap(h);
//         // printf("delete: me[%d] you[%d] love[%f]    ", data[i].me, data[i].you, data[i].love);
//         // if (i % 3 == 0) {
//         //     printf("\n");
//         // }
//     }
//     free(h);
// }

//////////////////////////////// priority queue (힙 정렬) 끝 //////////////////////////////
////////////test
// 배열 요소를 교환하는 함수
void swap(Data* a, Data* b) {
    Data temp = *a;
    *a = *b;
    *b = temp;
}

// 최대 힙 구조를 유지하는 함수
void heapify(Data arr[], int n, int i) {
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
void heapSort(Data arr[], int n) {
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
////////////test end
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

// 아니면 각 학생들의 count를 세서 가장 높은 count를 가진 top 5 학생을 기준으로 5개의 그룹 짜기?
void groupingV2(Data data[]){
    Data main_student[5];
    int result = 0;
    float love_result = 300.0;

    for(int i = 0; i < FILE_LEN; i++){
        int total = 0;
        float love_sum = 0.0;
        for(int j = 0; j < FILE_LEN; j++){
            if(data[i].me == data[j].me){
                love_sum += data[j].love;
                total++;
            }
            if(data[i].me == data[j].you){
                love_sum += data[j].love;
                total++;
            }

        }
        if(total >= result && love_sum <= love_result){
            result = total;
            love_result = love_sum;
        }
        printf("[%d] 학생의 언급 수 : [%d], 총 love : [%f]  ", data[i].me, total, love_sum);
        if(i % 2 == 0){
            printf("\n");
        }
    }
    printf("total = [%d], love = [%f] \n", result, love_result);
}


void groupingV1(Data data[], Data group[], int check[], int group_num){
    // check[] : 0 ~ 99 까지의 학생의 소속이 있는지 확인하는 배열
    // check 배열을 탐색하여 인덱스에 대응하는 데이터(group_num)가 존재하면 해당 인덱스와 같은 학생은 소속이 이미 있는 것.

    int index = 0;
    for(int i = 0; i < FILE_LEN; i++){
        // 오름차순으로 정렬된 데이터의 me, you 값과 check 배열의 인덱스(0~99)를 통해
        // 기존에 그룹화 된 학생인지 판별.
        if(check[data[i].me] == 0 && check[data[i].you] == 0){
            // if(index == MAX_GROUP - 1){
            //     printf("그룹[%d]에 인원이 꽉 찼으므로 종료합니다: [%d]명\n", group_num, index + 1);
            //     break;
            // }
            // 아직 소속이 없는 학생이라면 그룹에 추가.
            group[index] = data[i];
            printf("그룹[%d] %d번째 멤버 추가: [%d] <---love:[%f]---> [%d]\n", group_num, index, data[i].me, data[i].love, data[i].you);
            // check 배열에 그룹의 번호를 check
            check[data[i].me] = group_num;
            check[data[i].you] = group_num;
            index++;
        }
    }
    for(int i = 0; i < MAX_VERTICES; i++){
        if(check[i] == 0){
            for(int j = 0; j < FILE_LEN; j++){
                if((data[j].me == i || data[j].you == i) && check[data[j].me] == 0 && check[data[j].you == 0]){
                    group[index] = data[i];
                    printf("그룹[%d] %d번째 멤버 추가: [%d] <---love:[%f]---> [%d]\n", group_num, index, data[j].me, data[j].love, data[j].you);
                    check[data[j].me] = group_num;
                    check[data[j].you] = group_num;
                    // if(index == 49){
                    //     printf("그룹[%d]에 인원이 꽉 찼으므로 종료합니다: [%d]명\n", group_num, index + 1);
                    //     return;
                    // }
                    index++;
                }
            }
        }
    }
}

//////////////////////////////// 5개 그룹화 (끝) //////////////////////////////

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
        // printf("me: %d, you: %d, love: %f ", data[i].me, data[i].you, data[i].love);
        // if(i % 2 == 0){
        //     printf("\n");
        // }
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

    int n = sizeof(data) / sizeof(data[0]);
    heapSort(data, n);

    // heap_sort(data, FILE_LEN);
    print_data(data);

    // 5개 그룹화
    int check[MAX_VERTICES];
    check_init(check);

    Data Group1[FILE_LEN];
    groupingV1(data, Group1, check, 1);
    // groupingV2(data);
    print_not_checked(check);
    // Data Group2[MAX_GROUP];
    // Data Group3[MAX_GROUP];
    // Data Group4[MAX_GROUP];
    // Data Group5[MAX_GROUP];
    return 0;
}