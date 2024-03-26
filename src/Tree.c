#include "../include/Tree.h"
#include <stdlib.h>
#include <stdio.h>

struct TreeNode* createTreeNode(int value) {
    struct TreeNode* node =
        (struct TreeNode*) malloc(sizeof(struct TreeNode));
    if(node == NULL)
        return NULL;

    node->right = NULL;
    node->left = NULL;
    node->value = value;

    return node;
}

struct Tree* createTree(int array[], int size) {
    struct Tree* tree = (struct Tree*) malloc(sizeof(struct Tree));

    int i = 0;
    while(i < size) {
        insertIntoBST(&tree->root, array[i]);
        ++i;
    }

    return tree;
}

void printInOrder(struct TreeNode* parent) {
    if(!parent) return; 

    printInOrder(parent->left);
    printf("%d\n", parent->value);
    printInOrder(parent->right);
}

void insertIntoBST(struct TreeNode** nodeptr, int value) {
    struct TreeNode* parent = *nodeptr;
    if(!parent) {
        (*nodeptr) = createTreeNode(value);
        return;
    }

    struct TreeNode* child;
    if(!parent->right && value > parent->value) {
        child = createTreeNode(value);
        parent->right = child;
        return;
    } else if(!parent->left && value < parent->value) {
        child = createTreeNode(value);
        parent->left = child;
        return;
    }

    if(value > parent->value)
        insertIntoBST(&parent->right, value);
    else if(value < parent->value)
        insertIntoBST(&parent->left, value);
}

int nodesInTree(struct TreeNode* parent) {
    int count;

    if(!parent)
        return 0;
    count = 1 + nodesInTree(parent->left) + nodesInTree(parent->right);
    return count;
}

void deleteNode(struct TreeNode **nodeptr) {
    struct TreeNode* parent = *nodeptr;

    if(parent->left)
        deleteNode(&parent->left);
    if(parent->right)
        deleteNode(&parent->right);

    printf("Deleting %d\n", parent->value);
    (*nodeptr)->left = NULL;
    (*nodeptr)->right = NULL;
    free(*nodeptr);
}

void deleteTree(struct TreeNode** nodeptr) {
    struct TreeNode* root = *nodeptr;
    deleteNode(nodeptr);

    (*nodeptr) = NULL;
}

int getMin(struct TreeNode* parent) {
    if(!parent) return -1;
    if(!parent->left) return parent->value;

    return getMin(parent->left);
}

int getMax(struct TreeNode* parent) {
    if(!parent) return -1;
    if(!parent->right) return parent->value;

    return getMax(parent->right);
}
