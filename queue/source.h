//
// Created by Kataee on 21/04/2021.
//

#ifndef QUEUE_SOURCE_H
#define QUEUE_SOURCE_H


#include  <stdlib.h>
#include  <stdio.h>
#include <stdbool.h>



typedef struct {
    int info, maxSize;
    int front, rear;
    int* items;
    bool firstItem;
}QUEUENODE;

//QUEUENODE* first;
//QUEUENODE* last;

void createQueue(QUEUENODE**, int);
bool isEmptyQueue(QUEUENODE*);
bool isFullQueue(QUEUENODE*);
void insertQueue(QUEUENODE*, int);
int removeFirstItemQueue(QUEUENODE*);
int topItemQueue(QUEUENODE*);
void printQueue(QUEUENODE*);
void fillQueue(QUEUENODE*);


#endif //QUEUE_SOURCE_H
