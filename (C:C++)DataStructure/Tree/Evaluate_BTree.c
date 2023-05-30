#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

//      +
//  *       +
//1   4   16   25
TreeNode n1={1, NULL, NULL};
TreeNode n2={4, NULL, NULL};
TreeNode n3={'*', &n1, &n2};
TreeNode n4={16, NULL, NULL};
TreeNode n5={25, NULL, NULL};
TreeNode n6={'+', &n4, &n5};
TreeNode n7={'+', &n3, &n6};
TreeNode *root= &n7;

// 수식 계산 함수
int evaluate(TreeNode *root){
    if(root == NULL){
        return 0;
    }
    // 자식 노드가 없는 말단 노드(== 피연산자)이면 방문.(숫자 데이터 꺼냄)
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }
    // 말단 노드가 아닌 부모노드(== 연산자) 이면 말단노드(== 피연산자)가 나올 때까지 후위 순회.
    else{
        int op1 = evaluate(root->left); // evaluate 함수의 recursion. (L)
        int op2 = evaluate(root->right);// evaluate 함수의 recursion. (R)
        printf("%d %c %d 연산 실행.\n", op1, root->data, op2);
        switch(root->data){ // L -> R 이 끝난 후 루트 노드(V)에 방문하여 연산 작업 실행. : 후위 순회
            case '+':
                return op1 + op2;
            case '-':
                return op1 - op2;
            case '*':
                return op1 * op2;
            case '/':
                return op1 / op2;   
        }
    }
    return 0;
}

int main(void){
    printf("수식의 값은 [%d] 입니다.\n", evaluate(root));
    return 0;
}