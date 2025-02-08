#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct link{
    int element;
    struct link *next;
}Link;

typedef struct{
    Link *top;
    int size;
}Stack;

Link *create_link(Link *nextval, int it){
    Link *n = (Link *)malloc(sizeof(Link));
    n->element = it;
    n->next = nextval;
    return n;
}

Stack create_stack(){
    Stack s;
    s.top = NULL;
    s.size = 0;
}

void push(Stack *s, int element){
    s->top = create_link(s->top, element);
    s->size++; 
}

int pop(Stack *s){
    int c = s->top->element;
    Link *temp = s->top->next;
    s->top = s->top->next;
    //free(s->top->next);
    s->size--;
    return c;
}

int main(){

    char str[1000];
    Stack s;
    while(strcmp(str, "EOF") != 0){

        scanf(" %s", str);
        if(strcmp(str, "END") != 0){
            
            if(strcmp(str, "+") == 0){
                int v1 = pop(&s), v2 = pop(&s);
                push(&s, v1+v2);
            }
            else if(strcmp(str, "*") == 0){
                int v1 = pop(&s), v2 = pop(&s);
                push(&s, v1*v2);
            }
            else if(strcmp(str, "-") == 0){
                int v1 = pop(&s), v2 = pop(&s);
                push(&s, v2-v1);
            }
            else{
                push(&s, atoi(str));
            }
            
        }
        else if(strcmp(str, "EOF") != 0 && strcmp(str, "END") == 0)
            printf("%d\n", pop(&s));
    } 

    return 0;
}