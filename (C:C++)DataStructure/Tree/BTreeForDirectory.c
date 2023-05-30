#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

int cal_dir_size(TreeNode* root){
    int left_size, right_size = 0;
    if(root == NULL){
        return 0;
    }
    left_size = cal_dir_size(root->left);
    right_size = cal_dir_size(root->right);

    return root->data + left_size + right_size;
}

int main (void){
    TreeNode n4 = { 700, NULL, NULL };
	TreeNode n5 = { 300, NULL, NULL };
	TreeNode n3 = { 130, &n4, &n5 };
	TreeNode n2 = { 20, NULL, NULL };
	TreeNode n1 = { 0, &n2, &n3 };

	printf("디렉토리의 크기=%d\n", cal_dir_size(&n1));
    return 0;
}