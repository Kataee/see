//
// Created by Kataee on 01/06/2021.
//
//Hozzáadás
//Törlés
//Keresés
//Elemek számának lekérdezése

//create
//read
//print
//add
//search
//search //return boolean
//num of elements
//delete element

#ifndef P3_INTARRAY_H
#define P3_INTARRAY_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int size;
    char **chr;
} IntArray;

IntArray* create();
void read(const char *fileName, IntArray *array);
void print(IntArray *array);
void add(IntArray*, char*);

#endif
