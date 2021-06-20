//
// Created by Kataee on 16/06/2021.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_WORD_LENGTH 30

typedef struct wordarray {
    int size, rear;
    char **szin;
    char **szerzo;
    char **cim;
} wordarray_t;

wordarray_t *wordarray_create(int);
char** allocateMemory(char** asd, int size);
void print3(wordarray_t*);
void load3(const char*, wordarray_t*);
void removeChar(char *, char);
int cmpstr(void const *, void const *);
void sortBooks(wordarray_t*);

#ifndef UNTITLED3_HEADER_H
#define UNTITLED3_HEADER_H

#endif //UNTITLED3_HEADER_H
