#ifndef _ALGORITHMS_H
#define _ALGORITHMS_H

typedef long long int INT;

void swap(INT *a, INT *b);
void merge(INT *vet, int l, int r, INT *temp);
void mergesort(INT *vet, int l, int r, INT *temp);
int hoarepartition(INT *vet, int l, int r);
void quicksort(INT *vet, int l, int r);
void bs(INT *vet, int l, int K);

#endif
