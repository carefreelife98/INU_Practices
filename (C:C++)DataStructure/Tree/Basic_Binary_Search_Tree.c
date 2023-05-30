#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct TreeNode{
    element key;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

// 순환적인 탐색 함수
TreeNode* search(TreeNode* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(key == root->key){
        return root;
    }
    else if(key < root->key){
        return search(root->left, key);
    }
    else {
        return search(root->right, key);
    }
}

//새 노드 생성 함수
TreeNode* new_node(int key){
    TreeNode* new = (TreeNode*)malloc(sizeof(TreeNode));

    new->key = key;
    new->left = new->right = NULL;

    return new;
}

// 노드 삽입 함수
TreeNode* insert_node(TreeNode* root, int key){
    // 말단 노드까지 탐색 후 주어진 key를 가진 노드가 존재 하지 않으면 새 노드 생성하여 반환.
    if(root == NULL){
        return new_node(key);
    }
    // 말단 노드까지 탐색하여 내려간다.
    if(key < root->key){
        root->left = insert_node(root->left, key);
    }
    else if(key > root->key){
        root->right = insert_node(root->right, key);
    }
    return root;
}

// 가장 작은 key값을 가진 노드 찾기
TreeNode* min_value_node(TreeNode* root){
    TreeNode* current = root;
    // 가장 왼쪽 노드를 찾으러 내려간다. (이진 탐색 트리에서 가장 작은 key 값을 가진 노드는 가장 왼쪽에 있다.)
    while(current->left != NULL){
        current = current->left;
    }
    return current;
}

// 이진 탐색 트리와 키가 주어지면, 해당 키를 가진 노드를 삭제, 새로운 루트 노드 반환
TreeNode* delete_node(TreeNode* root, int key){
    // 탐색 실패. 해당 키를 가진 노드가 없어 삭제 불가 - NULL 반환.
    if(root == NULL){
        return NULL;
    }
    // 탐색 실패가 아니면 해당 노드를 찾아 내려간다.
    if(key < root->key){
        return delete_node(root->left, key);
    }
    else if(key > root->key){
        return delete_node(root->right, key);
    }
    // 탐색에 성공하면 3가지 경우에 따라 노드 삭제를 수행.
    else {
        // 삭제 대상 노드가 말단 노드인 경우 or 오직 하나의 서브 트리만 가지고 있는 경우.
        if(root->left == NULL){
            TreeNode* temp;
            temp = root;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            TreeNode* temp;
            temp = root;
            free(root);
            return temp;
        }
        // 삭제 대상 노드가 두 개의 서브트리 모두 가지고 있는 경우.
        // 삭제 대상 노드와 가장 근접한 key를 가진 노드를 찾는다.
        // == 왼쪽 서브트리의 가장 오른쪽 노드 or 오른쪽 서브트리의 가장 왼쪽 노드.
        TreeNode* temp = min_value_node(root->right);
        // 삭제 대상 노드에 key값을 복사.
        root->key = temp->key;
        // key값을 복사해온 노드를 삭제한다.
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}

void inorder(TreeNode* root){
    // 노드가 존재하면 실행.
    if(root){
        inorder(root->left);
        printf("[%d] ", root->key);
        inorder(root->right);
    }
}

int main(void) {
	TreeNode * root = NULL;
	TreeNode * tmp = NULL;

	root = insert_node(root, 80);
	root = insert_node(root, 20);
	root = insert_node(root, 40);
	root = insert_node(root, 30);
	root = insert_node(root, 60);
	root = insert_node(root, 70);

	printf("이진 탐색 트리 중위 순회 결과 \n");
	inorder(root);
	printf("\n\n");
	if (search(root, 30) != NULL)
		printf("이진 탐색 트리에서 30을 발견함 \n");
	else
		printf("이진 탐색 트리에서 30을 발견못함 \n");
	return 0;
}
