#include "linkedlist.h"
#include "stacks.h"
#include <stdio.h>
#include <stdlib.h>

Stack create_stack(){
    Stack s;
    s.top = NULL;
    s.size = 0;
    return s;
}
void clear(Stack *s){
    free(s->top);
    s->size = 0;
}
void push(Stack *s, int item){
    s->top = create_link(item, s->top);
    s->size++;
}
int pop(Stack *s){
    if(s->top == NULL)
        return -1;
    else{
        int item = s->top->element;
        s->top = s->top->next;
        s->size--;
        return item;
    }
}
int topValue(Stack s){
    if(s.top != NULL)
        return s.top->element;
}
int length(Stack s){
    if(s.size > 0)
        return s.size;
}