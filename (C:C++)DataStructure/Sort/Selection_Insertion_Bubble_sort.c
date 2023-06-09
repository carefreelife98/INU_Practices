#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int list[MAX_SIZE];
int n;

// 선택 정렬
void selection_sort(int list[], int n){
    int i, j, least, temp;
    for(i = 0; i < n - 1; i++){ // n - 2 까지만 정렬!!
        least = i;
        // 리스트 내 최소값 탐색
        for(j = i; j < n; j++){
            if(list[j] < list[least]) least = j;
        }
        // 탐색하여 찾은 최소값과 현재 단계의 값을 교환.
        SWAP(list[i], list[least], temp);
    }
}

// 삽입 정렬
void insertion_sort(int list[], int n){
    int i, j, key;
    printf("Insertion Sort:\n");
    for(i = 1; i < n; i++){
        key = list[i];
        for(j = i - 1; j >= 0 && key < list[j]; j = j - 1){
            list[j+1] = list[j]; // 레코드의 오른쪽 이동
        }
        // 내부 for문이 끝나면 list[j]는 key보다 작은 값.
        // 따라서 key가 삽입될 곳은 list[j+1]이 된다.
        list[j+1] = key;
    }
}

// 버블 정렬
void bubble_sort(int list[], int n){
    int i, j, temp;
    printf("Bubble Sort:\n");
    for(i = n - 1; i > 0; i--){
        for(j = 0; j < i; j++){
            if(list[j] > list[j+1]){
                SWAP(list[j], list[j+1], temp);
            }
        }
    }
}

// 쉘 정렬
// gap 만큼 떨어진 요소들을 삽입 정렬
// 정렬의 범위는 first에서 last
inc_insertion_sort(int list[], int first, int last, int gap){
    int i, j, key;

    for(i = first + gap; i <= last; i = i + gap){
        key = list[i];
        for(j = i - gap; j >= first && key < list[j]; j = j - gap){
            list[j + gap] = list[j];
        }
        list[j + gap] = key;
    }
}

void shell_sort(int list[], int n){ // n = size
    int i, gap;
    for (gap = n / 2; gap > 0; gap = gap / 2){
        if(gap % 2 == 0)
            gap++;
        for (i = 0; i < gap; i++){  // 부분 리스트의 개수는 gap과 같음.
            inc_insertion_sort(list, i, n - 1, gap);
        }

    }
}

int main(void) {
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for (i = 0; i<n; i++)      	// 난수 생성 및 출력 
		list[i] = rand() % 100; // 난수 발생 범위 0~99

	bubble_sort(list, n); // 버블정렬 호출
	for (i = 0; i<n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}
