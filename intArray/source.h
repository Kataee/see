//
// Created by Kataee on 15/04/2021.
//

#ifndef INTARRAY_SOURCE_H
#define INTARRAY_SOURCE_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct {
    int size;
    int *elements;
} IntArray;

//létrehozás
IntArray* createArray(int dimension);

//beolvasás
void readArray(const char *fileName, IntArray **array);

//véletlen számokkal feltöltés
void fillArray(int* array, int dimension, int first, int last);

//a tömb kiírása a képernyőre
void printArray(IntArray* array);

//file kiírása állományba
void printArrayToFile(const char* fileName, IntArray *array);



#endif //INTARRAY_SOURCE_H
