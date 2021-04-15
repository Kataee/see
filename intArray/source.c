//
// Created by Kataee on 15/04/2021.
//

#include "source.h"

IntArray* createArray(int dimension) {
    IntArray* newArray = (IntArray*)malloc(sizeof(IntArray));
    if (!newArray) {
        exit(1);
    }
    newArray->size = dimension;
    newArray->elements = (int*)malloc(dimension * sizeof(int));
    if (!newArray->elements) {
        exit(2);
    }
    printf("Array created\n");
}
