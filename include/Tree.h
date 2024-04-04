typedef struct BSTNode {
    struct BSTNode* left;
    struct BSTNode* right;
    void* value;
} BSTNode;

typedef struct BST {
    BSTNode* root;
} BST;

BST* BST_Create();
void BST_Destroy(BST**);
void BST_Insert(BST*, void*);
void BST_Print(BST*);
int BST_Size(BST*);
void* BST_Min(BST*);
void* BST_Max(BST*);
