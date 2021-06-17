//
// Created by Kataee on 10/06/2021.
//
#include "header.h"




wordarray_t *wordarray_create(int size) {
    //allocating memory
    wordarray_t *newArray = (wordarray_t *) malloc(sizeof(wordarray_t));

    if (newArray == NULL) {    //check if memory was allocated successfully
        return NULL;
    }

    //setting size, maximum number of strings
    newArray->size = size;
    newArray->rear = 0;

    //allocating memory
    //#######################111111111111111
    newArray->szin = (char **) malloc(size * sizeof(char *));
    if (newArray->szin == NULL) {   //check if memory was allocated successfully
        free(newArray);
        return NULL;
    }

    for (int i = 0; i < size; ++i) {
        newArray->szin[i] = (char *) malloc(30 * sizeof(char));   //allocating memory
        if (newArray->szin[i] == NULL) {   //check if memory was allocated successfully
            free(newArray->szin);
            free(newArray);
            return NULL;
        }
    }
    //############################2222222222222222
    newArray->szerzo = (char **) malloc(size * sizeof(char *));
    if (newArray->szerzo == NULL) {   //check if memory was allocated successfully
        free(newArray);
        return NULL;
    }

    for (int i = 0; i < size; ++i) {
        newArray->szerzo[i] = (char *) malloc(30 * sizeof(char));   //allocating memory
        if (newArray->szerzo[i] == NULL) {   //check if memory was allocated successfully
            free(newArray->szerzo);
            free(newArray);
            return NULL;
        }
    }
    //############################33333333333333333
    newArray->kotet = (char **) malloc(size * sizeof(char *));
    if (newArray->kotet == NULL) {   //check if memory was allocated successfully
        free(newArray);
        return NULL;
    }

    for (int i = 0; i < size; ++i) {
        newArray->kotet[i] = (char *) malloc(30 * sizeof(char));   //allocating memory
        if (newArray->kotet[i] == NULL) {   //check if memory was allocated successfully
            free(newArray->kotet);
            free(newArray);
            return NULL;
        }
    }
    printf("Wordarray created!\n");
    return newArray;
}

void wordarray_load(const char* fileName, wordarray_t *array) {
    FILE *f; //file stream

    // check if file can be opened
    if ((f = fopen(fileName, "r")) == NULL) {
        printf("Error opening file"); exit(4);
    }

    char c;
    //printf("size %i\n", array->size);
    //read
    //printf("zxc ");

    while (fscanf(f, "%c", &c) || 1) {
        printf("End e\n");
        if (feof(f)) {
            printf("End of file\n");
            fclose(f);
            return;
        }
        printf("asd ");
        printf("%c", c);
    }
    printf("asd ");

}

//print the strings to the console
void wordarray_print(wordarray_t *array) {
    for (int i = 0; i < array->size; ++i) {
        printf("%d: ",i);
        printf("%s ", array->szin[i]);
        printf("%s ", array->szerzo[i]);
        printf("%s ", array->kotet[i]);
        printf("\n");
    }

    printf("\n");
}

void wordarray_sort(wordarray_t *asd) {
    bool konyvekSzine = true;
    bool konyvekIroja = true;

    char* tempString;
    tempString = (char*)malloc(30*sizeof(char));
    if (tempString == NULL) {
        printf("Error creating tempString\n");
        return;
    }
    for (int i=0; i < asd->size; ++i) {
        tempString = asd->szin[i];
        printf("temp: %s ", tempString);
    }

    for (int i=0; i < asd->size-1; ++i) {
        for (int j=i+1; j < asd->size; ++j) {
            if (strcmp(asd->szin[i], asd->szin[j]) == 0) {
                printf("\nA konyvek szine hasonlo\n");
                konyvekSzine = false;
            }if (strcmp(asd->kotet[i], asd->kotet[j]) == 0) {
                konyvekIroja = false;
            }
        }

    }
    printf("\n");

    if (konyvekSzine) {
        printf("sorting by szin..\n");
        for(int i=0; i<asd->size-1;i++) {
            for (int j = i + 1; j < asd->size; j++) {
                if (strcmp(asd->szin[i], asd->szin[j]) > 0) {
                    strcpy(tempString, asd->szin[i]);
                    strcpy(asd->szin[i], asd->szin[j]);
                    strcpy(asd->szin[j], tempString);
                }
            }
        }
        return;
    }


    if (konyvekIroja ) {
        printf("sorting by kotet..\n");

        for (int i=0; i < asd->size-1; ++i) {
            for (int j=0; j < asd->size; ++j) {
                if (strcmp(asd->kotet[i], asd->kotet[j]) > 0) {
                    strcpy(tempString, asd->kotet[i]);
                    strcpy(asd->kotet[i], asd->kotet[j]);
                    strcpy(asd->kotet[j], tempString);
                }

            }
        }
    }

}

