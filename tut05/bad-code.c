#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

void myFunc();
struct node *appendToList(struct node *myNode, int data);
void freeList(struct node *head);

int main() {
  struct node *head = NULL;
  head = appendToList(head, 1);
  head = appendToList(head, 2);
  head = appendToList(head, 3);
  head = appendToList(head, 4);
  printList(head);
  freeList(head);
  return 0;
}

/**
 * Appends a new node to the linked list
 */
struct node *appendToList(struct node *myNode, int data) {
  // malloc the node
  struct node *newNode = malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;
  if (myNode == NULL) {
    myNode = newNode;
  } else {
    struct node *lastNode = myNode;
    while (lastNode->next != NULL) {
      lastNode = lastNode->next;
    }
    lastNode->next = newNode;
  }

  myFunc();
  return myNode;
}

/**
 * creates a variable
 */
void myFunc() { int fdsjakfl = 3242; }

void printList(struct node *node) {
  while (node->next != NULL) {
    printf("%d -> ", node->data);
    node = node->next;
  }
  printf("%d\n", node->data);
  return;
}

/**
 * Frees the entire list
 */
void freeList(struct node *head) {
  if (head == NULL) {
    return;
  }
  // Frees the list by iterating through the list, using a temporary element and
  // freeing the elements by using free (hopefully this comment is useful and
  // helps out)
  struct node *temporaryVariable = head;
  while (head != NULL) {
    temporaryVariable = head;
    head = head->next;
    free(temporaryVariable);
  }
}