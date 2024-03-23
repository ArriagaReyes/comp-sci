struct ListNode {
    int value;
    struct ListNode* next;
};

struct ListNode* createNode(int);
void append(struct ListNode*, int);
struct ListNode* prepend(struct ListNode*, int);
void insert(struct ListNode*, struct ListNode*, int);
void printList(struct ListNode*);
