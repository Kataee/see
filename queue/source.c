//
// Created by Kataee on 21/04/2021.
//

#include "source.h"


//
// Created by Kataee on 24/03/2021.
//

#include "source.h"
#include  <stdlib.h>
#include  <stdio.h>

//should be done
bool isEmptyQueue(QUEUENODE* first0, QUEUENODE* last0) {
    if (first0 == NULL && last0 == NULL) {
        return true;
    }
    return false;
}

void createQueue(QUEUENODE** myQueue) {
    (*myQueue) = (QUEUENODE *)malloc(1*sizeof(QUEUENODE));
    if ((*myQueue)==0) {
        return;
    }
    (*myQueue)->next = NULL;
}

void insertQueue(QUEUENODE* first, QUEUENODE* last, int info) {
    QUEUENODE* newQueue;
    createQueue(&newQueue);
    newQueue->info=info;

    if( isEmptyQueue(first, last) ) {
        first = newQueue;
        last = newQueue;
    } else {
        last->next = (struct NodeType *) newQueue;
        last = newQueue;
    }
}

int deleteQueue(QUEUENODE* first, QUEUENODE* last) {
    QUEUENODE* auxNode;
    if ( !isEmptyQueue(first, last) ) {
        auxNode = first;
        int auxInfo = first->info;
        first = first->next;
        free(auxNode);
        return auxInfo;
    } else {
        return INT_MIN;
    }
}

void printQueue(QUEUENODE * asd) {
    if (asd->next != NULL) {
        printf("%d", asd -> info);
        printQueue((QUEUENODE *) asd->next);
    }
}
