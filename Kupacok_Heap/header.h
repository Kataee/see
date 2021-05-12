//
// Created by Kataee on 12/05/2021.
//

#ifndef KUPACOK_HEAP_HEADER_H
#define KUPACOK_HEAP_HEADER_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


typedef struct heap {
    int* data;
    int size;
    int maxSize;
}heap;

heap *createHeap(int max);
void insert(heap* h, int Element);
void up (heap* h, int i);
void down(heap*, int);
void down2(heap*, int);
void kupacrendez(heap* h);
void kupacrendezNoDelete(heap* h);

int torolmax (heap *h);

void swap(int*, int*);

heap* two(heap*, heap*);



#endif //KUPACOK_HEAP_HEADER_H
