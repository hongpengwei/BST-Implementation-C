#ifndef TREE_H
#define TREE_H
#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};
TreeNode* createNode(int value);
void insertNode(TreeNode** root, int value);
void deleteNode(TreeNode** root, int value);
TreeNode* searchNode(TreeNode* root, int value);
void inorder(TreeNode* root);
void preorder(TreeNode* root);
void postorder(TreeNode* root);
TreeNode *minValueNode(TreeNode* root);
TreeNode *maxValueNode(TreeNode* root);
int TreeHeight(TreeNode *root);
void freeTree(TreeNode* root);
void mirrorTree(TreeNode* root); 
#endif // TREE_H