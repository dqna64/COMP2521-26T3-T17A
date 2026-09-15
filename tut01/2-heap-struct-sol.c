#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

void stack_struct() {
    struct node n;
    n.value = 42;
    n.next = NULL;

    // do smthn with the node
}

struct node* heap_struct() {
    struct node* n = malloc(sizeof(struct node));
    // (*n).value = 42;
    n->value = 42;
    n->next = NULL;

    // do smthn with the node

    return n;  // 0x389
}

int main(void) {
    stack_struct();
    struct node* pointer_to_heap_mem = heap_struct();  // 0x389
    // do smthn
    free(pointer_to_heap_mem);

    return 0;
}