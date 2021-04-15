//
// Created by Kataee on 15/04/2021.
//

#ifndef SEE_HEADER_H
#define SEE_HEADER_H


#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

//megadott mennyiségű beolvasott számok összege rekurzívan
int sumOfNumbers(int, int);

//fgv -ben megadott szám fordítottja, 123 - > 321
int reverseNumber(int, int);


//egy számot generál, addig olvas be amíg nem 0
int someNumberGenerator(int);


//min,   legkisebb számot téríti vissza, annyit olvas be amekkora a /number/
int minMain(int, int);
int minimum(int, int);

//max,   legnagyobb számot térítit vissza, annyit olvas be amekkora a /number/
int maxMain(int, int);
int maximum(int, int);


//létrehozunk egy tömböt, beolvassuk az elemeit és megnézzük, hogy szimmetrikus-e
bool simmetricArrayMain();
int simmetricArray(int* array, int lengthUnMod, int length, int start, bool simmetric);

#endif //SEE_HEADER_H
