#include "arraylist.h"
#include <stdio.h>
#include <stdlib.h>

List *create_list(int size){
    List *l = (List *)malloc(sizeof(List));
    l->maxSize = size;
    l->listSize = l->curr = 0;
    l->listArray = (int *)malloc(size * sizeof(int));
    return l;
}
void clear(List *l){
    free(l->listArray);
    free(l);
}
void insert(List *l, int item){
    if(l->listSize >= l->maxSize){
        printf("Error inserting item\n");
    }
    else{
        int i = l->listSize;
        while(i > l->curr){
            l->listArray[i] = l->listArray[i-1];
            i--;
        }
        l->listArray[l->curr] = item;
        l->listSize++;
    }
}
void append(List *l, int item){
    if(l->listSize < l->maxSize){
        l->listArray[l->listSize++] = item;
    }
}
int removeItem(List *l){
    if(l->curr < 0 || l->curr >= l->listSize)
        return -1;
    else{
        int item = l->listArray[l->curr]; 
        int i = l->curr;
        while(i < l->listSize-1){
            l->listArray[i] = l->listArray[i+1];
            i++;
        }
        l->listSize--;
        return item;
    }
}
void moveToStart(List *l){
    l->curr = 0;
}
void moveToEnd(List *l){
    l->curr = l->listSize;
}
void prev(List *l){
    if(l->curr != 0)
        l->curr--;
}
void next(List *l){
    if(l->curr < l->listSize)
        l->curr++;
}
int length(List *l){
    return l->listSize;
}
int currPos(List *l){
    return l->curr;
}
void moveToPos(List *l, int pos){
    if(pos > l->listSize || pos < 0){
        printf("Error moving position\n");
    }
    else{
        l->curr = pos;
    }
}
int getValue(List *l){
    if(l->curr >= 0 && l->curr < l->listSize)
        return l->listArray[l->curr];
    else
        return -1;
}