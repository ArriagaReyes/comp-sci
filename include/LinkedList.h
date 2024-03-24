struct LinkedList {
    struct ListNode* head;
    struct ListNode* tail;
};

struct ListNode {
    int value;
    struct ListNode* next;
};

struct ListNode* createNode(int);
struct LinkedList* createList(int[], int);
struct ListNode* find(struct LinkedList*, int);
void append(struct LinkedList*, int);
void prepend(struct LinkedList*, int);
void insert(struct ListNode*, struct ListNode*, int);
void printList(struct LinkedList*);
