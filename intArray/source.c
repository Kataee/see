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
            return;
        }
        fscanf(f, "%i", &(*array)->elements[i]);
        printf("%i ", (*array)->elements[i]);
    }
}
