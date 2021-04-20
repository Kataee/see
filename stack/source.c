//
// Created by Kataee on 17/03/2021.
//

#include "header.h"


STACK createStack(int capacity) {
    STACK s;

    s.capacity = capacity+1;
    s.sp=0;
    s.elements = (int*)malloc(capacity * sizeof(int));
    if (!(s.elements)) {
        printf("Error creating s.elements");
        exit(1);
    }

    return s;

}

void push(STACK* s, int elem) {
    if ( !isFull(s)) {
        (*s).elements[(*s).sp++] = elem;
    }
    //printf("%i ", (*s).elements[(*s).sp]);


}

int pop(STACK* s) {
    if ( !isEmpty(s)) {
        int res = (*s).elements[--(*s).sp];
        return res;
    } else {
        printf("A verem ures");
        return 0;
    }
}

int top(STACK *s) {
    if (!isEmpty(s)) {
        int temp = (*s).elements[--(*s).sp];
        (*s).sp++;
        return temp;

    }
    printf("A verem ures\n");
    return 0;
}

bool isEmpty(STACK* s) {
    if ((*s).sp == 0) { return true; }
    else { return false; }

}

bool isFull(STACK *s) {
    if ( (*s).sp == (*s).capacity-1) { printf("full\n"); return true; }
    else { return false; }

}

void destroy(STACK *s) {
    free((*s).elements);
    (*s).sp=0;
    (*s).capacity=0;
}

void print(STACK s) {
    int size = s.sp-1;
    printf("size: %i\n" ,size);
    int* temp = (int*)malloc((size)*sizeof(int));
    if (!temp) {
        printf("Error creating temp\n");
        exit(1);
    }
    //printf("\n");

    for (int i = size; i>=0; --i) {
        temp[i] = pop(&s);
        printf("%d ", temp[i]);
    }
    printf("\n");

    //printf("\n%d ", temp[i]);
    for (int i=0; i < size; ++i) {
        push(&s, temp[i]);
    }
}





