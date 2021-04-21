//
// Created by Kataee on 21/04/2021.
//
#include "source.h"

void create(STACKNODE** myNode) {
    (*myNode) = (STACKNODE*)malloc(1*sizeof(STACKNODE));
    if ((*myNode)==0) {
        return;
    }
    (*myNode)->next = NULL;
}

//should be done
void push(STACKNODE** topPtr, int info) {
    STACKNODE *newNode;
    create(&newNode);
    newNode->info = info;
    newNode->next = (*topPtr);
    *topPtr=newNode;
}

//should be done
int top(STACKNODE* topPtr) {
    if (isEmpty(topPtr)) {
        return topPtr->info;
    }
}

//should be done
int pop(STACKNODE** topPtr) {
    if (!isEmpty(*topPtr)) {
        return -1;
    }
    STACKNODE *aux;
    int auxinfo;
    aux = *topPtr;
    (*topPtr) = aux->next;
    auxinfo = aux->info;
    free(aux);
    return auxinfo;
}


//print working
void printStack(STACKNODE* topPtr) {
    if (topPtr->next != NULL) {
        printf("%d ", topPtr -> info);
        printStack(topPtr->next);
    }
}

bool isEmpty(STACKNODE* topPtr) {
    return topPtr != NULL;
}