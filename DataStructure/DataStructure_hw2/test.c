#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *rlink;
} TreeNode;

TreeNode *new_node(int key) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->rlink = NULL;
    return node;
}

TreeNode *insert(TreeNode *node, int key) {
    if (node == NULL)
        return new_node(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

void inorder(TreeNode *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void inorder_linked_list(TreeNode *root, TreeNode **prev) {
    if (root == NULL)
        return;
    inorder_linked_list(root->left, prev);
    (*prev)->rlink = root;
    (*prev) = root;
    inorder_linked_list(root->right, prev);
}

void print_list(TreeNode *node) {
    while (node != NULL) {
        printf("%d ", node->key);
        node = node->rlink;
    }
    printf("\n");
}

void linked_list_from_bst(TreeNode *root) {
    TreeNode *prev = NULL;
    inorder_linked_list(root, &prev);
}


// main test


int main() {
    TreeNode *root = NULL;

    // 테스트용 이진 탐색 트리 생성
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // 중위 순회 결과 출력
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    // 연결 리스트 생성 및 출력
    linked_list_from_bst(root);
    printf("Linked List: ");
    print_list(root);

    return 0;
}
