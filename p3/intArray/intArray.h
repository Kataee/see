//
// Created by Kataee on 01/06/2021.
//
//Hozzáadás
//Törlés
//Keresés
//Elemek számának lekérdezése

#ifndef P3_INTARRAY_H
#define P3_INTARRAY_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct {
    int size;
    char **chr;
} IntArray;

IntArray* create();
void read(const char *fileName, IntArray **array);

#endif
