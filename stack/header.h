//
// Created by Kataee on 17/03/2021.
//

#ifndef LAB5_SOURCE_H
#define LAB5_SOURCE_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct STACK{
    int capacity, sp;
    int *elements;
    //int sp; //stack pointer - veremmutató

}STACK;

STACK createStack(int); //létrehoz egy vermet
void push(STACK*, int); //betesz a verem tetejére
int pop(STACK*); //kiveszi a veremből a legfelső elemet
int top(STACK*); //megnézi a verem legfelső elemét
bool isEmpty(STACK*); //ellenőrzi, hogy üres-e a verem
bool isFull(STACK*); //ellenőrzi, hogy tele van-e a verem
void destroy(STACK*); //felszabadít
void print(STACK); //kiírja a teljes verem tartalmát (segédfüggvény, nem tartozik az adatszerkezet definíciójához)


#endif //LAB5_SOURCE_H
