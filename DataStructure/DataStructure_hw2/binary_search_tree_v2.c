#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#pragma warning(disable:4996)


#define MAX_ROW 20
#define MAX_COLUMN 20

int key = 0;
int birth[20];


typedef struct {
    int birth;
    char name;
    int grade;
} Data;

typedef struct TreeNode {
    struct TreeNode *left;
    Data data;
    struct TreeNode *right;
    struct TreeNode *rlink;
}TreeNode;


///////////////////////////////// students.txt 읽기 /////////////////////////////////

void read_data(Data *data) {
    FILE *fp;
    fp = fopen("students.txt", "r"); // 읽기 모드로 파일을 연다.

    // 첫 번째 행을 버린다.
    while (fgetc(fp) != '\n');

    // 파일에서 데이터를 읽어와 구조체에 저장.
    char buf[MAX_COLUMN];
    int i = 0;
    while (fgets(buf, MAX_COLUMN, fp) != NULL) {
        // 각 열의 데이터를 구조체에 저장
        sscanf(buf, "%8d %c %2d", &data[i].birth, &data[i].name, &data[i].grade);
        i++;
    }
    
    // 파일 닫기.
    fclose(fp);
}
void print_students_data(Data* data) {
    printf("\n ------------------파일 읽기 시작-------------------- \n");
    // printf("생일\t이름\t성적\n");
    for (int i = 0; i < MAX_ROW; i++) {
        printf("%d\t%c\t%d\n", data[i].birth, data[i].name, data[i].grade);
    }
    printf(" ------------------파일 읽기 끝-------------------- \n\n");
}

///////////////////////////////// students.txt 읽기 끝 /////////////////////////////////



///////////////////////////////// 이진 탐색 트리 /////////////////////////////////

// data 삽입된 노드 생성
TreeNode* new_node(Data item){
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->data = item;
    temp->left = temp->right = temp->rlink = NULL;
    return temp;
}


// insert
// 1. 삽입할 키 값을 루트 노드와 비교해 같다면 오류를 발생한다( 중복 값 허용 X )
// 2. 삽입할 키 값이 루트 노드의 키보다 작다면 왼쪽 서브 트리를 탐색해서 비어있다면 추가하고, 비어있지 않다면 다시 값을 비교한다.
// 3. 삽입할 키 값이 루트노드의 키보다 크다면 오른쪽 서브트리를 탐색해서 비어있다면 추가하고, 비어있지 않다면 다시 값을 비교한다.
TreeNode* insert(TreeNode *node, Data new_data) {
    
    // 현재 위치가 비어 있으면 새로운 노드를 생성하여 반환.
    if (node == NULL) {
        // printf("\n현재 위치가 비어 있어 새로운 노드를 추가 합니다."); 
        // printf("\nbirth: %d, name: %c, grade: %d \n", new_data.birth, new_data.name, new_data.grade);
        return new_node(new_data);
    }
    // birth가 root의 birth 보다 작으면 root 노드의 왼쪽 자식 노드 확인.
    if (new_data.birth < node->data.birth){
        // printf("new birth: %d < root birth: %d 이므로 왼쪽 노드 확인.\n", new_data.birth, node->data.birth);
        node->left = insert(node->left, new_data);
    }
    // birth가 root의 birth 보다 크면 root 노드의 오른쪽 자식 노드 확인.
    else if(new_data.birth > node->data.birth) {
        // printf("new birth: %d > root birth: %d 이므로 오른쪽 노드 확인.\n", new_data.birth, node->data.birth);
        node->right = insert(node->right, new_data);
    }
    // 변경된 루트 포인터를 반환.
    return node;
}

// 중위 순회 - birth 출력
void inorder_print(TreeNode *root){
    if(root){
        inorder_print(root->left);
        printf("[%d]\n", root->data.birth);
        inorder_print(root->right);
    }
}

// 후위 순회 및 이름 출력
void postorder_print(TreeNode *root){
    if(root){
        postorder_print(root->left);
        postorder_print(root->right);
        printf("[%c]\n", root->data.name);
    }
}

// search : 탐색 이진 트리 에서는 삽입 전 탐색부터 실행해야 하며, 탐색 실패 시 해당 자리에 노드를 삽입한다.
TreeNode *search(TreeNode *node, int birth){
    if(node == NULL) return NULL;
    if(birth == node->data.birth) {
        // printf("\nnode 탐색 완료 : %d\n", node->data.birth);
        return node;
    }
    else if (birth < node->data.birth){
        return search(node->left, birth);
    }else {
        return search(node->right, birth);
    }
}

TreeNode *min_value_node(TreeNode *node){
    TreeNode *current = node;

    // 가장 왼쪽 노드를 찾으러 왼쪽으로 내려간다.
    while(current->left !=NULL){
        current = current->left;
    }

    return current;
}

// 삭제할 노드의 연결리스트 연결 선 처리.
// 메모리 반환이 아닌 연결리스트의 연결만 갱신.
void delete_rlink_tree_list(TreeNode* node, TreeNode* min, int hasChild){
   
    for(; min != NULL; min = min->rlink){
        // 후계자 노드의 삭제로 인해 매개변수인 node 가 root 대신 root->right 으로 들어온 경우 hasChild == 1 이므로 미실행.
        if(hasChild == 0) {
            if(min->rlink->data.birth == node->data.birth){
                // printf("\npre 노드 발견 : %d\npre 노드의 현재 rlink : %d == 현재 노드 : %d\n", min->data.birth, min->rlink->data.birth, node->data.birth);
                // node가 마지막 노드인경우 min->rlink을 NULL로 설정.
                if(node->rlink == NULL) {
                    printf("\n마지막 노드를 삭제 합니다.\n");
                    min->rlink = NULL;
                    return;
                }
                min->rlink = node->rlink;
                printf("\npre 노드의 rlink 갱신 후 pre 노드의 rlink : %d\n", min->rlink->data.birth);
                return;
            }
        }
        // hasChild 가 1인 경우, 삭제될 후계자 노드를 가리키고 있는 node의 rlink를 다음 노드로 연결시켜주어야 한다.
        // node = node->right 으로 넘어오는것 잊지 말자.
        else {
            // 후계자 노드가 min의 rlink일 때 부모 노드는 min이 된다. min의 rlink를 후계자 노드의 rlink로 연결시켜주자.
            // 앞전에 함수 밖에서 후계 노드의 값을 부모 노드로 복사 했기 때문에 둘의 값이 같아야 정상이다.
            if(node == min->rlink){
                printf("\n부모 노드 : %d == 후계자 노드 : %d\n", min->data.birth, node->data.birth);
                min->rlink = node->rlink;
                printf("부모 노드의 rlink를 후계자노드의 rlink 로 갱신 후 부모 노드의 rlink : %d\n", min->rlink->data.birth);
                return;
            }
        }
    }
}

// 이진 탐색 트리와 키가 주어지면 키와 같은 값의 노드를 삭제하고 새로운 루트 노드를 반환한다. 
TreeNode* delete_node_in_tree_linkedlist(TreeNode* root, int birth, TreeNode* min, int hasChild){
    if(root == NULL) {
        return root;
    }
    // birth 값을 루트노드와 비교해서 작으면 왼쪽 서브트리 탐색.
    if(birth < root->data.birth) {
        root->left = delete_node_in_tree_linkedlist(root->left, birth, min, hasChild);
    }
    // birth 값을 루트노드와 비교해서 크면 오른쪽 서브트리 탐색.
    else if(birth > root->data.birth) {
        root->right = delete_node_in_tree_linkedlist(root->right, birth, min, hasChild);
    }
    // birth 값을 노드와 비교해서 같으면 해당 노드를 삭제. - 3개의 case 존재.
    // 만약 삭제 대상 노드에게 자식이 존재한다면, 삭제 위치에 자식을 올려 삭제 대상 노드의 부모에게 연결 해주어야 함.
    else {
        // case 1,2 : 자식이 없거나 하나만 존재 하는 경우.

        // case 1.
        // 삭제할 노드의 왼쪽 자식이 없으면 오른쪽 자식을 temp에 복사 후 오른쪽 자식을 삭제.
        // 이후 삭제된 노드의 복사값(temp) / case 3 였던 경우엔 NULL 반환.
        if(root->left == NULL){
            // printf("\n---------연결리스트에서 해당 노드의 연결이 끊어집니다.---------\n");
            delete_rlink_tree_list(root, min, hasChild);
            // printf("\n---------연결리스트에서 해당 노드의 연결이 끊어졌습니다.---------\n\n");
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } 
        // case 2.
        // 삭제할 노드의 오른쪽 자식이 없으면 왼쪽 자식을 temp에 복사 후 왼쪽 자식을 삭제.
        // 이후 삭제된 노드의 복사값(temp) 를 반환.
        else if(root->right == NULL){
            // free()를 통해 메모리 반환 하기 전에 삭제 대상 노드 및 해당 prev 노드의 (linked list) rlink 수정.
            // printf("\n---------연결리스트에서 해당 노드의 연결이 끊어집니다.---------\n");
            delete_rlink_tree_list(root, min, hasChild);
            // printf("\n---------연결리스트에서 해당 노드의 연결이 끊어졌습니다.---------\n\n");
            // linked list 수정 끝
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        // case 3. : 자식이 두 개 존재하는 경우.
        printf("\n삭제 대상 노드의 자식이 두 개 모두 존재.\n");
        TreeNode* temp = min_value_node(root->right);
        printf("\n후계자 노드 : %d\n", temp->data.birth);

        // 후계 노드를 부모 노드 위치에 복사
        root->data = temp->data;

        // 후계 노드를 삭제
        // 후계 노드의 값이 부모 노드에 복사 되어 있기 때문에 case 3. 의 경우 연결리스트는 변동 사항이 없다. 
        // hasChild 변수를 1로 바꾸어 연결리스트 갱신 함수인 delete_rlink_tree_list() 의 작동을 무시한다.
        root->right = delete_node_in_tree_linkedlist(root->right , temp->data.birth, min, 1);
        hasChild = 0;
    }
    return root;
}

TreeNode* search_delete_print(TreeNode *root, int b , TreeNode* min){
    
    // 검색 대상 학생의 정보 출력
    TreeNode *temp = search(root, b);
    printf("\n이름 : %c\n생년월일 : %d\n학점 : %d\n", temp->data.name, temp->data.birth, temp->data.grade);

    // 이진 탐색 트리에서의 삭제 / 연결 리스트에서의 삭제
    return delete_node_in_tree_linkedlist(root, b, min, 0);
}

/////////////////////////////////// 연결리스트 구현 ///////////////////////////////////////////

void inorder_linked_list(TreeNode *root) {
    // 노드가 존재하면 실행
    if(root){
        inorder_linked_list(root->left);
        birth[key++] = root->data.birth;
        inorder_linked_list(root->right);
    }
}

void gen_linked_list(TreeNode *root, int* birth){

    // root를 가장 작은 키값의 노드로 설정
    TreeNode *node = search(root, birth[0]);
    
    for(int i = 1; i<20; i++){
        if(node == NULL){
            printf("노드가 비었습니다.");
            return;
        }
        // printf("시작 i = %d\n", i);
        // printf("다음 birth 값 탐색 후 오른쪽 노드에 연결.\n");
        // printf("현재 노드의 birth 값: %d\n", node->data.birth);
        // printf("다음 노드의 birth 값: %d\n", birth[i]);
        node->rlink = search(root, birth[i]);
        // printf("연결된 노드의 값: %d\n", node->rlink->data.birth);
        node = node->rlink;
        // printf("노드 이동. 현재 노드의 값: %d\n", node->data.birth);
        // printf("ok\n");
    }
}

void print_list(TreeNode *node){
    for(; node != NULL; node = node->rlink){
        printf("[%d] -> ", node->data.birth);
    }
    printf("NULL\n\n");
}

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
    printf("%d\n", root->data.birth);

    drawBinarySearchTree(root->left, space);
}

// 이진 탐색 트리의 모든 노드를 반환하는 함수
    void freeBinarySearchTree(TreeNode* root){
        if (root == NULL) {
            return;
        }

        freeBinarySearchTree(root->left);
        freeBinarySearchTree(root->right);
        printf("\n노드 : [%c] 반환!", root->data.name);
        free(root);
    }

/////////////////////////////////// 메인 함수 ///////////////////////////////////////////

// main
int main(void) {
    TreeNode *root = NULL;
    Data data[MAX_ROW];
    read_data(data);
    print_students_data(data);

    printf("\n ------------------------이진 탐색 트리 생성 시작------------------------ \n");
    for(int i = 0; i < MAX_ROW; i++){
        root = insert(root, data[i]);
    }
    printf("\n ------------------------이진 탐색 트리 생성 끝------------------------ \n");

    printf("\n ------------------------중위 순회 결과------------------------ \n");
    inorder_print(root);
    
    // 각 노드를 중위 순회하여 key값을 오름차순으로 birth 배열에 저장.
    inorder_linked_list(root);

    // 연결리스트의 시작점을 알기 위해 min_value_node 미리 알아두기.
    TreeNode* min = min_value_node(root);

    printf("\n ------------------------linked list 생성 시작------------------------ \n");
    gen_linked_list(root, birth);

    printf("\n\n ------------------------연결리스트를 출력합니다.------------------------ \n");
    print_list(min);

    // 이진 탐색 트리 및 연결 리스트에서의 노드 삭제
    int b;
    for(int i = 0; i < 5; i++){
        printf("\n\n검색하여 삭제할 학생 다섯 명의 생년월일을 한 명씩 입력하시오: ");
        scanf("%d", &b);
        root = search_delete_print(root, b, min);
        print_list(min);
    }

    // printf("\n-----------------------현재 이진 탐색 트리를 출력합니다.-----------------------\n");
    // drawBinarySearchTree(root, 0);

    printf("\n-----------------------현재 이진 탐색 트리를 후위 순회 하며 이름을 출력합니다.-----------------------\n");
    postorder_print(root);

    freeBinarySearchTree(root);

    printf("\n\n@@@@@   201702797 채승민 자료구조 HW_2 2023.05.19   @@@@@\n");




    return 0;
}