//
// Created by Kataee on 12/05/2021.
//

#include "header.h"

heap* createHeap(int max) {
    heap* h = (heap*)malloc(sizeof(heap));
    h->size = 0;
    h->maxSize = max;
    h->data = (int*)malloc(max * sizeof(int));
    return h;
}

void insert(heap* h, int Element) {
    h->size++;
    h->data[h->size] = Element;
    up(h, h->size);
}

void up(heap* h, int i) {
    int seged;
    while((i > 1) && (h->data[i/2] < h->data[i])) {
        seged = h->data[i/2];
        h->data[i/2] = h->data[i];
        h->data[i] = seged;
        i/=2;
    }
}

void down(heap* h, int i) {
    while (2*i <= h->size) {
        int j=2*i;
        if (j < h->size && h->data[j] < h->data[j+1]) {
            j++;
        }

        if (h->data[j] <= h->data[i]) {
            break;
        }
        //swap(&h->data[i], &h->data[j]);
        swap(&h->data[i], &h->data[j]);
        i=j;
    }
}



//how this
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void kupacrendez(heap* h) {
    for (int i = h->size/2; i>=1; i--) {
        down(h,i);
    }

    for (int i=1; 1 <= h->size; ++i) {
        printf("X: %i   ", torolmax(h));
        swap(&h->data[1], &h->data[h->size-i+1]);
        down(h,1);
    }
    printf("\n");
}


int max(heap* h) {
    int max = h->data[1];
    for (int i=1; i<h->size; ++i) {
        if (max < h->data[i]) {
            max = h->data[i];
        }
    }
    return max;
}

int torolmax(heap* h) {
    int seged = h->data[1];
    h->data[1] = h->data[h->size];
    h->data[h->size] = seged;
    //printf("size-- %i ", h->size-1);
    h->size--;
    return seged;
}

heap* two(heap* h1, heap* h2) {
    int size = h1->size + h2->size;
    heap* asd = createHeap(size);
    int index;
    for (int i=1; i <=  h1->size; ++i) {
        asd->data[i] = h1->data[i];
        index = i;
    }
    //next location
    index++;
    for (int i=index; )



    return asd;
}














