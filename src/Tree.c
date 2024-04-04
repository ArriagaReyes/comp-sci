#include "../include/Tree.h"
#include <stdlib.h>
#include <stdio.h>

static BSTNode* BSTNode_Create(void* value) {
    BSTNode* node = (BSTNode*) malloc(sizeof(BSTNode));
    if(!node) return NULL;

    node->right = NULL;
    node->left = NULL;
    node->value = value;

    return node;
}

static void BSTNode_Destroy(BSTNode** nodeptr) {
    (*nodeptr)->left = NULL;
    (*nodeptr)->right = NULL;
    (*nodeptr)->value = NULL;
    free(*nodeptr);
    (*nodeptr) = NULL;
}

static void BSTNode_DestroyRecursively(BSTNode** nodeptr) {
    BSTNode* parent = (*nodeptr);
    if(!parent) return;

    if(parent->left)
        BSTNode_DestroyRecursively(&parent->left);
    if(parent->right)
        BSTNode_DestroyRecursively(&parent->right);

    printf("Destroying %d\n", *(int*)parent->value);
    BSTNode_Destroy(nodeptr);
}

static void BSTNode_Insert(BSTNode** nodeptr, void* value) {
    BSTNode* parent = *nodeptr;

    // Is the parent empty?
    if(!parent) {
        (*nodeptr) = BSTNode_Create(value);
        return;
    }

    // Can we place the node under this parent?
    if(!parent->right && *(int*)value > *(int*)parent->value) {
        parent->right = BSTNode_Create(value);
        return;
    } else if (!parent->left && *(int*)value < *(int*)parent->value) {
        parent->left = BSTNode_Create(value);
        return;
    }

    // We can't? Can we place the node under one of the children?
    if(*(int*)value > *(int*)parent->value)
        BSTNode_Insert(&parent->right, value);
    else if(*(int*)value < *(int*)parent->value)
        BSTNode_Insert(&parent->left, value);
}

static int BSTNode_Count(BSTNode* parent) {
    if(!parent) return 0;
    return 1 + BSTNode_Count(parent->left) + BSTNode_Count(parent->right);
}

static void BSTNode_PrintInOrder(BSTNode* parent) {
    if(!parent) return;

    BSTNode_PrintInOrder(parent->left);
    printf(" %d ", *(int*)parent->value);
    BSTNode_PrintInOrder(parent->right);
}

static void* BSTNode_Min(BSTNode* parent) {
    if(!parent) return NULL;
    if(!parent->left) return parent->value;

    return BSTNode_Min(parent->left);
}

static void* BSTNode_Max(BSTNode* parent) {
    if(!parent) return NULL;
    if(!parent->right) return parent->value;

    return BSTNode_Max(parent->right);
}

BST* BST_Create() {
    BST* tree = (BST*) malloc(sizeof(BST));
    if(!tree) return NULL;

    tree->root = NULL;
    return tree;
}

void BST_Destroy(BST** treeptr) {
    BST* tree = *treeptr;
    BSTNode_DestroyRecursively(&tree->root);

    printf("Destroying tree\n");
    free(*treeptr);
    (*treeptr) = NULL;
}

void BST_Insert(BST* tree, void* value) {
    BSTNode_Insert(&tree->root, value);
}

void BST_Print(BST* tree) {
    printf("[");
    BSTNode_PrintInOrder(tree->root);
    printf("]\n");
}

int BST_Size(BST* tree) {
    return BSTNode_Count(tree->root);
}

void* BST_Min(BST* tree) {
    return BSTNode_Min(tree->root);
}

void* BST_Max(BST* tree) {
    return BSTNode_Max(tree->root);
}
