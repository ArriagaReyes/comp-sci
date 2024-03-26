struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct Tree {
    struct TreeNode* root;
};

void insertIntoBST(struct TreeNode**, int);
int nodesInTree(struct TreeNode*);
void deleteTree(struct TreeNode**);
int getMin(struct TreeNode*);
int getMax(struct TreeNode*);
void printInOrder(struct TreeNode*);
struct TreeNode* createTreeNode(int);
struct Tree* createTree(int[], int);
