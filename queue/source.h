//
// Created by Kataee on 21/04/2021.
//

#ifndef QUEUE_SOURCE_H
#define QUEUE_SOURCE_H


#include  <stdlib.h>
#include  <stdio.h>
#include <stdbool.h>

typedef struct {
    int info;
    struct NodeType *next;
}QUEUENODE;


bool isEmptyQueue(QUEUENODE*, QUEUENODE*);
void createQueue(QUEUENODE**);
void insertQueue(QUEUENODE*, QUEUENODE*, int);
int deleteQueue(QUEUENODE*, QUEUENODE*);
void printQueue(QUEUENODE*);


#endif //QUEUE_SOURCE_H
