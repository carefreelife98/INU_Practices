#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 이진 탐색 트리를 그리는 함수
void drawBinarySearchTree(TreeNode* root, int space) {
    if (root == NULL) {
        return;
    }

    space += 5;

    drawBinarySearchTree(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    drawBinarySearchTree(root->left, space);
}

int main(void) {
    
    // 노드 세개 생성
    TreeNode *n1; 
    TreeNode *n2;
    TreeNode *n3;
    
    n1 = (TreeNode*)malloc(sizeof(TreeNode));
    n2 = (TreeNode*)malloc(sizeof(TreeNode));
    n3 = (TreeNode*)malloc(sizeof(TreeNode));

    // 첫번째 노드 n1을 설정
    n1->data = 10;
    n1->left = n2;
    n1->right = n3;

    // 두번째 노드 n2을 설정
    n2->data = 20;
    n2->left = NULL; // 자식노드가 없다 == leaf 노드
    n2->right = NULL;

    // 세번째 노드 n3을 설정
    n3->data = 30;
    n3->left = NULL; // 자식노드가 없다 == leaf 노드
    n3->right = NULL;

    drawBinarySearchTree(n1, 0);

    // 동적 할당 메모리 반환
    free(n1);
    free(n2);
    free(n3);
    
    return 0;
}