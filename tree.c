#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

TreeNode* createNode(int value){
    TreeNode * node = (TreeNode *)malloc(sizeof(TreeNode));
    if(node == NULL) return NULL;
    node->left = node->right = NULL;
    node->value = value;
    return node;
}

void insertNode(TreeNode **root, int value){
    if(*root == NULL)
    {
        *root = createNode(value);
        return;
    }
    else if(value > *root->value)
        insertNode(&(*root)->left, value);
    else
        insertNode(&(*root)->right, value);
}

TreeNode* maxValueNode(TreeNode* root){
    TreeNode* cur = root;
    while(cur != NULL)
        cur = cur->right;
    return cur;
}

TreeNode* minValueNode(TreeNode* root){
    TreeNode* cur = root;
    while(cur != NULL)
        cur = cur->left;
    return cur;
}

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int TreeHeight(TreeNode *root) {
    // 終止條件：如果走到 NULL，代表這條路徑高度為 0
    if (root == NULL) {
        return 0;
    }

    // 遞迴計算左右子樹高度
    int leftH = TreeHeight(root->left);
    int rightH = TreeHeight(root->right);

    // 回傳 1 (自己這一層) + 左右最高的那邊
    return 1 + MAX(leftH, rightH);
}

void freeTree(TreeNode* root){
    if(root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void mirrorTree(TreeNode* root) {
    if (root == NULL) return;

    // 交換左右子樹
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // 遞迴鏡像左右子樹
    mirrorTree(root->left);
    mirrorTree(root->right);
}

TreeNode* searchNode(TreeNode* root, int value){
    if(root == NULL) return;
    if(root->value == value) return root;
    else if(value > root->value)
        return searchNode(root->left, value);
    else
        return searchNode(root->right, value);
}

void inorder(TreeNode* root){
    if(root == NULL)return;
    inorder(root->left);
    printf("%d ,"root->value);
    inorder(root->right);
}

void preorder(TreeNode* root){
    if(root==NULL) return null;
    printf("%d ",root->value);
    preorder(root->left);
    preorder(root->right);
}
void postorder(TreeNode* root){
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->value);
}