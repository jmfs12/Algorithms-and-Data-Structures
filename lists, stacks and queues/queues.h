#ifndef _QUEUES_H
#define _QUEUES_H

#include "linkedlist.h"

typedef struct{
    Link *front;
    Link *rear;
    int size;
}Queue;

Queue create_queue();
void clear(Queue *q);
void enqueue(Queue *q, int item);
int dequeue(Queue *q);
int frontValue(Queue q);
int length(Queue q); 



#endif