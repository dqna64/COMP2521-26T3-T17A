struct node {
    int value;
    struct node *next;
};

struct list {
    struct node *head; // 0x642
    int length;
    struct node *tail;
    //...
};

struct node *readList(int size);
struct node *createList();
void printList(struct node *l);
void printListContainer(struct list *linkedList);
struct node *createNode(int val);
struct node *appendVal(struct node *head, int val);
void appendValContainer(struct list *linkedList, int val);