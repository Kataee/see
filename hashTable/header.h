//
// Created by Kataee on 19/05/2021.
//

#ifndef HASHTABLE_HEADER_H
#define HASHTABLE_HEADER_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int* table;
    int capacity, elements;
} HASHTABLE;

HASHTABLE create(int);
void insert(HASHTABLE*, int);
void delete(HASHTABLE*, int);
int search (HASHTABLE, int);
void print(HASHTABLE);
void destroy(HASHTABLE);


void fel2();
int calc(int, HASHTABLE);
void printArr(int, int*);
int calcArr(int, int*);

#endif //HASHTABLE_HEADER_H
