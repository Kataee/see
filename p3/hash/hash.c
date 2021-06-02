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
    newHashTable->table = (char**)calloc(capacity,sizeof(char*));
    if (!newHashTable->table) {   //check if memory was allocated successfully
        printf("Error creating chr**\n");
        exit(12);
    }

    for (int i=0; i<capacity; ++i) {
        newHashTable->table[i] = (char*)calloc(30,sizeof(char));   //allocating memory
        if (!newHashTable->table[i]) {   //check if memory was allocated successfully
            printf("Error creating char[%i]\n", i);
            exit(13);
        }
        //printf("char: %s\n", newArray->chr[i]);
    }
    printf("Hash created.\n");

    return newHashTable;
}


void addH(HASHTABLE* array, char* s) {
    array->elements++; //increasing element count
    int size = array->elements; //segédváltozó

    if (!array->table) {   //check if memory was allocated successfully
        printf("Error creating chr**\n");
        exit(13);
    }

    //printf("Length of %s: %i   ", s, strlen(s));
    int element=0;
    for (int i=0; i < strlen(s); ++i) {
        element += s[i];
    }

    int i=0,j;

    do {
        j = (element + i) % array->capacity;
        if (strcmp(array->table[j], "") == 0) {
            array->table[j] = s;
            printf("added: %s\n", array->table[j]);
            return;
        } else {
            i++;
        }
    }

    while (i!=array->capacity);
    printf("Tulcsordulas\n");
    return;



}

void printH(HASHTABLE* array) {
    printf("Print: ");
    for (int i=0; i < array->capacity; ++i) {
        if (strcmp(array->table[i], "") == 0) {
            printf("x ");
            continue;
        }
        printf("%s ", array->table[i]);
    }
}


