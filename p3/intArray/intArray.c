//
// Created by Kataee on 01/06/2021.
//

#include "intArray.h"

IntArray* create(int size){
    IntArray* newArray = (IntArray*)malloc(sizeof(IntArray));
    if (!newArray) {
        printf("Error creating IntArray\n");
        exit(1);
    }

    newArray->size = size;
    newArray->chr = (char**)malloc(size*sizeof(char*));
    if (!newArray->chr) {
        printf("Error creating chr**\n");
        exit(2);
    }

    for (int i=0; i<size; ++i) {
        newArray->chr[i] = (char*)malloc(30*sizeof(char));
        if (!newArray->chr[i]) {
            printf("Error creating char[%i]\n", i);
            exit(3);
        }
    }
    printf("Array created.\n");

    return newArray;
}

void read(const char* fileName, IntArray **array) {
    FILE *f; //file stream

    // check if file can be opened
    if ((f = fopen(fileName, "r")) == NULL) {
        printf("Error opening file"); exit(4);
    }
    printf("size %i\n", &(*array)->size);
    //read
    for (int i=0; i < &(*array)->size; ++i) {
        if (feof(f)) {
            printf("End of file\n");
            //realloc((*array)->chr,i);
            //(*array)->size = i;
            //printf("Reallocated, size %i\n", &(*array)->size);
            fclose(f);
            return;
        }
        //fgets( (*array)->chr[i], 30, f);

        char s[30];
        fscanf(f, "%s", s);
        printf("%s ", s);
        //printf("%c ", s[1]);
        //printf("len: %i ", strlen(s));
        //while (fscanf(f, "%c", ))
        //printf("%s ", (*array)->chr[i]);
        //strcpy((*array)->chr[][i] ,s);
        //break;
        (*array)->chr[0] = 'c';
    }
}












