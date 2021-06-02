//
// Created by Kataee on 02/06/2021.
//

#include "hash.h"

HASHTABLE* createH(int capacity) {
    //allocating memory
    HASHTABLE* newHashTable = (HASHTABLE*)malloc(sizeof(HASHTABLE));

    if (!newHashTable) {    //check if memory was allocated successfully
        printf("Error creating HashTable\n");
        exit(11);
    }

    newHashTable->capacity = capacity;
    newHashTable->elements=0;

    //allocating memory
    newHashTable->table = (char**)malloc(capacity*sizeof(char*));
    if (!newHashTable->table) {   //check if memory was allocated successfully
        printf("Error creating chr**\n");
        exit(12);
    }

    for (int i=0; i<capacity; ++i) {
        newHashTable->table[i] = (char*)malloc(30*sizeof(char));   //allocating memory
        if (!newHashTable->table[i]) {   //check if memory was allocated successfully
            printf("Error creating char[%i]\n", i);
            exit(13);
        }
        //printf("char: %s\n", newArray->chr[i]);
    }
    printf("Array created.\n");

    return newHashTable;
}


void addH(HASHTABLE* array, char* s) {
    array->elements++; //increasing element count
    int size = array->elements; //segédváltozó

    array->table = (char**)realloc(array->table, size*sizeof(char*));

    if (!array->table) {   //check if memory was allocated successfully
        printf("Error creating chr**\n");
        exit(13);
    }

    array->table[size] = (char*)malloc(30*sizeof(char));  //allocating memory
    if (!array->table[size]) {   //check if memory was allocated successfully
        printf("Error creating char[%i]\n", size);
        exit(15);
    }
    array->table[size-1] = s;   //copy the given string into array


}
