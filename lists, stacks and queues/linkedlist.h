#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

typedef struct link{
    int element;
    struct link *next;
}Link;

typedef struct{
    Link *head;
    Link *tail;
    Link *curr;
    int cnt;
}List;

Link *create_link(int it, Link *nextval);
List create_list();
void insert(List *l, int it);
void moveToStart(List *l);
void prev(List *l);
void next(List *l);
int remove_item(List *l);

#endif
