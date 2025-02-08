#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>


Link *create_link(int it, Link *nextval){
    Link *n = (Link *)malloc(sizeof(Link));
    n->element = it;
    n->next = nextval;
    return n;
}

List create_list(){
    List l;
    l.curr = l.tail = l.head = (Link *)malloc(sizeof(Link));
    l.curr->next = l.tail->next = l.head->next = NULL;
    l.cnt = 0; 
    return l;
}
void insert(List *l, int it){
    l->curr->next = create_link1(it, l->curr->next);
    if(l->tail == l->curr)
        l->tail = l->curr->next;
    l->cnt++;
}
void moveToStart(List *l){
    l->curr = l->head;
}
void prev(List *l){
    if(l->curr == l->head)
        return;
    else{
        Link *temp = l->head;
        while(temp->next != l->curr)
            temp = temp->next;
        l->curr = temp;
    }
}
void next(List *l){
    if(l->curr != l->tail){
        l->curr = l->curr->next;
    }
}
int remove_item(List *l){
    if(l->curr->next == NULL)
        return -1;
    int it = l->curr->next->element;
    if(l->tail == l->curr->next){
        l->tail = l->curr;
    }
    l->curr->next = l->curr->next->next;
    l->cnt--;
    return it;
}
