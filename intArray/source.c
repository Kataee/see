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
    printf("Array created, size %i\n", newArray->size);
    return newArray;
}

void readArray(const char *fileName, IntArray **array) {

    FILE *f;  //file stream

    //check if file can be opened
    if ((f= fopen(fileName, "r")) == NULL) {
        printf("Error opening file");
        exit(3);
    }

    //read
    for (int i=0; i < (*array)->size; ++i) {
        //if end of file, return
        if (feof(f)) {
            printf("End of file\n");
            realloc((*array)->elements, i);
            (*array)->size = i;
            printf("Array reallocated, size %i\n", (*array)->size);
            return;
        }
        fscanf(f, "%i", &(*array)->elements[i]);
        printf("%i ", (*array)->elements[i]);
    }
    fclose(f);
}

void fillArray(int* array, int dimension, int first, int last) {
    srand(time(0));
    for (int i=0; i<dimension; ++i) {
        array[i] = rand() % (last - first) + first;
    }
}

void printArray(IntArray* array) {
    for (int i=0; i< array->size; ++i) {
        printf("%i ", (*array).elements[i]);
    }
    printf("\n");
}


void printArrayToFile(const char* fileName, IntArray *array) {
    FILE *f;  //file stream

    //check if file can be opened
    if ((f= fopen(fileName, "w")) == NULL) {
        printf("Error opening file");
        exit(7);
    }
    for (int i=0; i<array->size; ++i) {
        fprintf(f, "%i ", array->elements[i]);
    }
    printf("success\n");
    fclose(f);
}

void sortArray(IntArray *array) {
    qsort(array->elements, array->size, sizeof(int), compareFunc); //rendezes
}
int compareFunc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findElement(IntArray *array, int element) {
    for (int i=0; i < array->size; ++i) {
        if (array->elements[i] == element) {
            return i;
        }
    }
    return -1;
}
