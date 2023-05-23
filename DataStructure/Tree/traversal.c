#include<stdio.h>
#include<stdlib.h>
#include<memory.h>


// ================ 원형큐 코드 시작 =================
#define MAX_QUEUE_SIZE 100

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef TreeNode * element;

typedef struct { // 큐 타입
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

// 오류 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 공백 상태 검출 함수
void init_queue(QueueType *q)
{
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 삽입 함수
void enqueue(QueueType *q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// 레벨 순회
void level_order(TreeNode* ptr)
{
	QueueType q;

	init_queue(&q);	 // 큐 초기화

	if (ptr == NULL) return;
	enqueue(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		printf(" [%d] ", ptr->data);
		if (ptr->left)
			enqueue(&q, ptr->left);
		if (ptr->right)
			enqueue(&q, ptr->right);
	}
}



void preorder(TreeNode* root) {
    if (root != NULL){
        printf("[%d]", root->data); // 노드 방문 및 작업 수행
        preorder(root->left); // 왼쪽 서브트리 순회
        preorder(root->right); //오른쪽 서브트리 순회
    }
}

void inorder(TreeNode* root){
    if(root != NULL){
        inorder(root->left); // 왼쪽 서브트리 순회
        printf("[%d]", root->data); // 노드 방문 및 작업 수행
        inorder(root->right); //오른쪽 서브트리 순회
    }
}

void postorder(TreeNode* root) {
    if(root != NULL){
        postorder(root->left); // 왼쪽 서브트리 순회
        postorder(root->right); //오른쪽 서브트리 순회
        printf("[%d]", root->data); // 노드 방문 및 작업 수행
    }
}

//		 15
//	 4		 20
// 	1	   16  25
TreeNode n1={1, NULL, NULL};
TreeNode n2={4, &n1, NULL};
TreeNode n3={16, NULL, NULL};
TreeNode n4={25, NULL, NULL};
TreeNode n5={20, &n3, &n4};
TreeNode n6={15, &n2, &n5};
TreeNode *root= &n6;

int main(void) {
	// printf("중위 순회=");
	// inorder(root);
	// printf("\n");

	// printf("전위 순회=");
	// preorder(root);
	// printf("\n");

	// printf("후위 순회=");
	// postorder(root);
	// printf("\n");

    // 큐를 사용하는 레벨 순회 추가
	printf("레벨 순회=");
	level_order(root);
	printf("\n");
	return 0;
}
