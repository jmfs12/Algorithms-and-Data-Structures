#ifndef _STACKS_H
#define _STACKS_H


#include "linkedlist.h"

typedef struct{
    Link *top;
    int size;
}Stack;

Stack create_stack();
void clear(Stack *s);
void push(Stack *s, int item);
int pop(Stack *s);
int topValue(Stack s);
int length(Stack s);


#endif