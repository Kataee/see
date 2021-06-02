//
// Created by Kataee on 02/06/2021.
//

#ifndef P3_HASH_H
#define P3_HASH_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
/*
 * HASHTABLE create(int);
void insert(HASHTABLE*, int);
void delete(HASHTABLE*, int);
int search (HASHTABLE, int);
void print(HASHTABLE);
void destroy(HASHTABLE);
 */

typedef struct {
    char** table;
    int capacity, elements;
} HASHTABLE;

HASHTABLE* createH(int);
void addH(HASHTABLE* hash, char* s);



#endif //P3_HASH_H
