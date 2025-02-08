#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H

typedef struct{

    int maxSize;
    int listSize;
    int curr;
    int* listArray;

} List;

List *create_list(int size);
void clear(List *l);
void insert(List *l, int item);
void append(List *l, int item);
int removeItem(List *l);
void moveToStart(List *l);
void moveToEnd(List *l);
void prev(List *l);
void next(List *l);
int length(List *l);
int currPos(List *l);
void moveToPos(List *l, int pos);
int getValue(List *l);



#endif
