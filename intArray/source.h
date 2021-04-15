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

IntArray* createArray(int dimension);


#endif //INTARRAY_SOURCE_H
