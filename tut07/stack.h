#include <stdbool.h>

typedef int Item;

typedef struct stack {
    Item *items;
    int top;
    int capacity;
} *Stack;

Stack StackNew();
void StackFree(Stack s);
void StackPush(Stack s, Item item);
Item StachPop(Stack s);
bool StackIsEmpty(Stack s);
