/**
 * Run:
 * $ clang main.c stack.c queue.c && ./a.out
 */

#include <stdio.h>

#include "queue.h"

int main() {
    Queue q = QueueNew();
    
    QueueEnqueue(q, 1);
    QueueEnqueue(q, 2);
    QueueEnqueue(q, 3);

    printf("Dequeued %d\n", QueueDequeue(q));  // 1
    
    QueueEnqueue(q, 4);
    
    printf("Dequeued %d\n", QueueDequeue(q));  // 2

    QueueEnqueue(q, 5);
    QueueEnqueue(q, 6);

    printf("Dequeued %d\n", QueueDequeue(q));  // 3
    printf("Dequeued %d\n", QueueDequeue(q));  // 4
    printf("Dequeued %d\n", QueueDequeue(q));  // 5
    printf("Dequeued %d\n", QueueDequeue(q));  // 6

    QueueFree(q);
}