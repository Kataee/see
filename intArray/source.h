//
// Created by Kataee on 15/04/2021.
//

#ifndef INTARRAY_SOURCE_H
#define INTARRAY_SOURCE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int size;
    int *elements;
} IntArray;

//létrehozás
IntArray* createArray(int dimension);

//beolvasás
void readArray(const char *fileName, IntArray **array);


#endif //INTARRAY_SOURCE_H
