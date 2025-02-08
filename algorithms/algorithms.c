#include "algorithms.h"
#include <stdio.h>


void swap(INT *a, INT *b){
    INT temp = *a;
    *a = *b;
    *b = temp;
}
void merge(INT *vet, int l, int r, INT *temp){
    for(int i = 0; i <= r; i++)
        temp[i] = vet[i];
    int m = (l+r)/2;
    int i1 = l, i2 = m+1;
    for(int curr = l; curr <= r; curr++){
        if(i1 == m+1){
            vet[curr] = temp[i2];
            i2++;
        }
        else if(i2 > r){
            vet[curr] = temp[i1];
            i1++;
        }
        else if(temp[i1] <= temp[i2]){
            vet[curr] = temp[i1];
            i1++;
        }
        else{
            vet[curr] = temp[i2];
            i2++;
        }
    }
}
void mergesort(INT *vet, int l, int r, INT *temp){
    if(l < r){
        int m = (l+r)/2;
        mergesort(vet, l, m, temp);
        mergesort(vet, m+1,r,temp);
        merge(vet,l,r,temp);
    }
}
int hoarepartition(INT *vet, int l, int r){
    int p = vet[l];
    int i = l;
    int j = r+1;
    do{
        do{
            i++;
        }while(vet[i] < p && i < r);
        do{
            j++;
        }while(vet[j] > p);
        swap(vet[i], vet[j]);
    }while(i < j);
    swap(vet[i],vet[j]);
    swap(vet[l],vet[j]);
    return j;
}
void quicksort(INT *vet, int l, int r){
    int m = hoarepartiton(vet,l,r);
    quicksort(vet,l, m-1);
    quicksort(vet, m+1,r);
}
int bs(INT *vet, int n, int K){
    int l = 0; int r = n-1;
    while(l <= r){
        int m = (l+r)/2;
        if(K == vet[m])
            return m;
        else if(K < vet[m])
            r = m-1;
        else
            l = m+1;
    }
}