//
// Created by Kataee on 01/06/2021.
//
//Hozzáadás
//Törlés
//Keresés
//Elemek számának lekérdezése

//create
//read
//print
//add
//search
//search //return boolean
//num of elements
//delete element

#ifndef P3_INTARRAY_H
#define P3_INTARRAY_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    int size;
    char **chr;
} IntArray;

IntArray* create();
void read(const char *fileName, IntArray *array); //read strings from file into char* 2dimension array
void print(IntArray *array); //print the strings to the console
void add(IntArray*, char*);     //add new string to the end
char* search(IntArray*, char*);     //search a string and return it
int numOfElements(IntArray*);       //return the number of strings
bool delete(IntArray*, char*);      //delete a string

#endif
