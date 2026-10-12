#include <stdio.h>
#include <stdlib.h>

struct node {
  int fjsdajfkldsajf;
  struct node *next;
};

struct node *appendNewNodeToList(struct node *listHead, int data);
struct node *createNode(int data);
void printList(struct node *node);
void freeList(struct node *head);

int main() {
  struct node *head = NULL;
  head = appendNewNodeToList(head, 1);
  head = appendNewNodeToList(head, 2);
  head = appendNewNodeToList(head, 3);
  head = appendNewNodeToList(head, 4);

  printList(head);
  freeList(head);

  return 0;
}

/**
 * Adds a node to the end of linked list
 */
struct node *appendNewNodeToList(struct node *listHead, int data) {
  struct node *newNode = createNode(data);

  if (listHead == NULL) {
    listHead = newNode;
  } else {
    // Find the last node of the linked list
    struct node *lastNode = listHead;
    while (lastNode->next != NULL) {
      lastNode = lastNode->next;
    }
    lastNode->next = newNode;
  }

  return listHead;
}

/**
 * Create a new linked list node
 */
struct node *createNode(int data) {
  struct node *newNode = malloc(sizeof(struct node));
  newNode->fjsdajfkldsajf = data;
  newNode->next = NULL;
  return newNode;
}

/**
 * Given a linked list, prints each node in order
 * E.g 1 -> 2 -> 3 ->
 */
void printList(struct node *node) {
  while (node->next != NULL) {
    printf("%d -> ", node->fjsdajfkldsajf);
    node = node->next;
  }

  printf("%d\n", node->fjsdajfkldsajf);
  return;
}

/**
 * Given a linked list, frees each node
 */
void freeList(struct node *head) {
  if (head == NULL) {
    return;
  }
  struct node *temp = head;

  // loop through to free each node
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}
