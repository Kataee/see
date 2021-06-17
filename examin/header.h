//
// Created by Kataee on 10/06/2021.
//

#ifndef EXAMIN_HEADER_H
#define EXAMIN_HEADER_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_WORD_LENGTH = 30;

typedef struct wordarray {
    int size, rear;
    char **szin;
    char **szerzo;
    char **kotet;
} wordarray_t;

wordarray_t *wordarray_create();
void wordarray_load(const char *fileName, wordarray_t *array); //read strings from file into char* 2dimension array
void wordarray_print(wordarray_t *array); //print the strings to the console


void wordarray_sort(wordarray_t *array);




#endif //EXAMIN_HEADER_H
