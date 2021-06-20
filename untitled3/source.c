//
// Created by Kataee on 16/06/2021.
//
//#include "header.h"

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
    //##################################   SZIN
    newArray->szin = allocateMemory(newArray->szin, size);
    if (newArray->szin == NULL) {
        return NULL;
    }
/*
    newArray->szin = (char **) malloc(size * sizeof(char *));
    if (newArray->szin == NULL) {   //check if memory was allocated successfully
        free(newArray);
        return NULL;
    }

    for (int i = 0; i < size; ++i) {
        newArray->szin[i] = (char *) malloc(MAX_WORD_LENGTH * sizeof(char));   //allocating memory
        if (newArray->szin[i] == NULL) {   //check if memory was allocated successfully
            free(newArray->szin);
            free(newArray);
            return NULL;
        }
    }
     */
    //##################################   SZERZO
    newArray->szerzo = allocateMemory(newArray->szerzo, size);
    if (newArray->szerzo == NULL) {
        return NULL;
    }
    /*
    newArray->szerzo = (char **) malloc(size * sizeof(char *));
    if (newArray->szerzo == NULL) {   //check if memory was allocated successfully
        free(newArray);
        return NULL;
    }

    for (int i = 0; i < size; ++i) {
        newArray->szerzo[i] = (char *) malloc(MAX_WORD_LENGTH * sizeof(char));   //allocating memory
        if (newArray->szerzo[i] == NULL) {   //check if memory was allocated successfully
            free(newArray->szerzo);
            free(newArray);
            return NULL;
        }
    }

*/
    //##################################   CIM
    newArray->cim = allocateMemory(newArray->cim, size);
    if (newArray->cim == NULL) {
        return NULL;
    }
    /*
    newArray->cim = (char **) malloc(size * sizeof(char *));
    if (newArray->cim == NULL) {   //check if memory was allocated successfully
        free(newArray);
        return NULL;
    }

    for (int i = 0; i < size; ++i) {
        newArray->cim[i] = (char *) malloc(MAX_WORD_LENGTH * sizeof(char));   //allocating memory
        if (newArray->cim[i] == NULL) {   //check if memory was allocated successfully
            free(newArray->cim);
            free(newArray);
            return NULL;
        }
    }
     */

    return newArray;
}


char** allocateMemory(char** asd, int size) {
    asd = (char **) malloc(size* sizeof(char *));
    if (asd == NULL) {   //check if memory was allocated successfully
        free(asd);
        return NULL;
    }

    for (int i = 0; i < size; ++i) {
        asd[i] = (char *) malloc(MAX_WORD_LENGTH * sizeof(char));   //allocating memory
        if (asd[i] == NULL) {   //check if memory was allocated successfully
            free(asd);
            return NULL;
        }
    }
    return asd;
}

void load3(const char* fileName, wordarray_t* asd) {
    printf("start\n");

    //open file
    FILE* f;
    if ((f = fopen(fileName, "r") ) == NULL) {
        printf("Error opening file!\n");
        return;
    }

    //scan nothing, we don't need the first lines, the number in front has been dealt
    //with in the main
    int temp;
    fscanf(f, "%i", &temp);
    char c;
    char* str;
    str = (char*)calloc(150,sizeof(char));
    if (str == NULL) {
        printf("Error creating *str\n");
        return;
    }

    //if the next char is empty line, continue
    fscanf(f, "%c", &c);

    //scan the txt char by char
    int i=0;
    while (fscanf(f, "%c", &c) != EOF) {
        printf("%c", c);
        if (c == '\n') {
            continue;
        }
        str[i] = c;
        i++;

    }
    i=0;
    //print what we scanned
    printf("\n\n\nString:\n");
    printf("%s", str);

    //helper char*
    char* piece = (char*)calloc(MAX_WORD_LENGTH,sizeof(char));
    if (piece == NULL) {
        printf("Error creating piece\n");
        return;
    }

    //removing char we don't want to have
    removeChar(str, '{');
    removeChar(str, '}');
    printf("\nRemoved brackets:---------------------\n%s\n", str);

    piece = strtok(str, ",");
    strcpy(asd->szin[i], piece);

    while (piece != NULL) {
        piece = strtok(NULL, ",");
        strcpy(asd->szerzo[i], piece);

        piece = strtok(NULL, ",");
        strcpy(asd->cim[i], piece);

        piece = strtok(NULL, ",");
        if (piece == NULL) {
            break;
        }
        ++i;
        strcpy(asd->szin[i], piece);


    }



}

void removeChar(char *str, char garbage) {

    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;
    }
    *dst = '\0';
}

void print3(wordarray_t* asd) {
    printf("\nPrint from print3 function:\n");
    for (int i=0; i < asd->size; ++i) {
        printf("%s %s %s\n", asd->szin[i], asd->szerzo[i], asd->cim[i]);
    }
}

//from stackoverflow
int cmpstr(const void* a, const void* b)
{
    const char* aa = *(const char**)a;
    const char* bb = *(const char**)b;
    return strcmp(aa,bb);
}

void sortBooks(wordarray_t* asd) {
    bool sameColor = false;
    bool sameAuthor = false;
    for (int i=0; i < 3; ++i) {
        for (int j=i+1; j < 3; ++j) {
            if (strcmp(asd->szin[i], asd->szin[j]) == 0) {
                sameColor = true;
            }
            if (strcmp(asd->szerzo[i], asd->szerzo[j]) == 0) {
                //printf("szerzo: %s %s %i %i\n", asd->szerzo[i], asd->szerzo[j], i, j);
                sameAuthor = true;
            }
            if (sameColor == true && sameAuthor == true) {
                break;
            }
        }
    }
    if (sameColor == true && sameAuthor == true) {
        printf("true\n");
        qsort(asd->szin, 3, sizeof(char*), cmpstr);
        return;
    }

    qsort(asd->szerzo, 3, sizeof(char*), cmpstr);
}