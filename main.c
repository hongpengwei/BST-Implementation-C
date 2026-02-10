#include "tree.c";
#include <stdio.h>
#include <stdlib.h>

int main() {
    Node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    inorder(root);
    printf("\n");

    return 0;
}