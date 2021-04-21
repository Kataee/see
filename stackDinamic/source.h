
#ifndef STACKDINAMIC_SOURCE_H
#define STACKDINAMIC_SOURCE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int info;
    struct NodeType *next;
}STACKNODE;

void create(STACKNODE**);
void push(STACKNODE**, int);
int top(STACKNODE*);
int pop(STACKNODE** );
bool isEmpty(STACKNODE *);
void printStack(STACKNODE*);


#endif //STACKDINAMIC_SOURCE_H
