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
void inc_insertion_sort(int list[], int first, int last, int gap){
    int i, j, key;
    // i : 각 부분리스트 요소의 index
    // 시작점 first 에서 gap만큼 떨어진 위치부터 gap 간격마다의 요소를 부분리스트로 설정
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
    printf("Shell Sort:\n");
    // gap이 1이 될 때까지 gap / 2해가며 진행
    for (gap = n / 2; gap > 0; gap = gap / 2){
        if(gap % 2 == 0)  // gap은 홀수인것이 좋으므로 짝수이면 + 1
            gap++;
        for (i = 0; i < gap; i++){  // 부분 리스트의 개수는 gap과 같음.
            inc_insertion_sort(list, i, n - 1, gap);
        }
    
    }
}

// 합병 정렬
int sorted[MAX_SIZE]; // 정렬 및 합병되어질 공간 생성

/* 
i 는 정렬된 왼쪽 리스트에 대한 인덱스
j 는 정렬된 오른쪽 리스트에 대한 인덱스
k 는 정렬될 리스트에 대한 인덱스
*/
void merge(int list[], int left, int mid, int right){
    int i, j, k, l;
    i = left; j = mid + 1; k = left;

    // 각 부분 리스트에 대하여 sorted 배열에 정렬
    // 두 부분 리스트 중 하나의 요소가 전부 사용될 때까지.
    while (i <= mid && j <= right){
        if(list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    // 남아 있는 요소의 일괄 복사 to sorted[]
    if(i > mid) // 오른쪽 리스트가 남아있을 시
        for(l = j; l <= right; l++)
            sorted[k++] = list[l];
    else    // 왼쪽 리스트가 남아있을 시
        for(l = i; l <= mid; l++)
            sorted[k++] = list[l];
    // 배열 sorted[] 의 요소를 배열 list[] 로 재 복사.
    for(l = left; l <= right; l++){
        list[l] = sorted[l];
    }
}

void merge_sort(int list[], int left, int right){
    int mid;
    if(left < right){
        mid = (left + right) / 2;   // 리스트의 중간 인덱스 찾기

        // 왼 부분 리스트 생성 가장 왼쪽 인덱스(0) ~ 중간 인덱스(mid) 
        merge_sort(list, left, mid);

        // 오른 부분 리스트 생성 중간 바로 다음 인덱스 (mid+1) ~ 가장 오른쪽 인덱스(right)
        merge_sort(list, mid + 1, right);

        // 부분 리스트의 정렬 및 합병
        merge(list, left, mid, right);
    }
}

// 퀵 정렬
int partition(int list[], int left, int right){
    int pivot, temp;
    int low, high;

    // left는 pivot의 위치이지만 for문 들어가며 +1 증가되어 피봇 다음 index부터 시작하게 된다.
    low = left;
    // high도 마찬가지로 for문 들어가며 -1 감소되어 시작되기 때문에 배열을 넘어서는 인덱스부터 시작.
    high = right + 1;
    // 편의를 위해 피봇을 list의 첫 인덱스로 설정.
    pivot = list[left];

    do {
        // 두 개의 do-while문
        do
            low++;
        while (list[low] < pivot);
        // low가 pivot보다 큰 (low 부분 리스트에 있으면 안되는) 요소에서 멈춤
        
        do
            high--;
        while (list[high] > pivot);
        // high가 pivot보다 작은 (high 부분 리스트에 있으면 안되는) 요소에서 멈춤

        // 위의 do while문에 의해 멈춰 있는 low / high 가 가리키고 있는 요소를 교환.
        // (부적절한 요소가 있는 위치)
        if(low < high) SWAP(list[low], list[high], temp);
    }while (low < high); // low와 high가 교차하면 종료

    // pivot(list[left])과 high의 요소를 바꾸어준다.
    SWAP(list[left], list[high], temp);
    
    return high;    // high가 가리키는 곳으로 이동한 pivot의 인덱스를 반환
}

void quick_sort(int list[], int left, int right){
    if(left < right){
        // partition() 함수의 결과로 pivot 생성 후 리스트 분할.
        int pivot = partition(list, left, right);
        // left ~ pivot 전 요소까지 퀵 정렬
        quick_sort(list, left, pivot - 1);
        // pivot 이후 요소부터 right(끝)까지 퀵 정렬.
        quick_sort(list, pivot + 1, right);
    }
}


int main(void) {
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for (i = 0; i<n; i++)      	// 난수 생성 및 출력 
		list[i] = rand() % 100; // 난수 발생 범위 0~99
    printf("Quick Sort:\n");
	merge_sort(list, 0, n - 1); // 퀵 정렬 호출
	for (i = 0; i<n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}
