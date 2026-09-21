/**
 * Run:
 * $ clang 4_list_delete_sol.c linked_list.c && ./a.out
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

/**
 * Recursive function to delete the first occurence of a value in a linked list.
 */
struct node *listDelete(struct node *n, int value) {
    if (n == NULL) {
        return n;
    }
    if (value == n->value) {
        struct node *subList = n->next;
        free(n);
        return subList;
    } else {
        n->next = listDelete(n->next, value);
        return n;
    }
}

/**
 * Takes in a container struct to a linked list and returns the same
 * container with the linked list with target values removed.
 */
struct list *listDeleteContainer(struct list *l, int value) {
    l->head = listDelete(l->head, value);
    return l;
}

int main() {
    struct node *list = listIntro();
    printf("Value to delete: ");
    int value;
    scanf("%d", &value);

    list = listDelete(list, value);
    printf("List after delete: ");
    printList(list);

    return 0;
}
