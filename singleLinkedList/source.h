//
// Created by Kataee on 20/04/2021.
//

#ifndef SINGLELINKEDLIST_SOURCE_H
#define SINGLELINKEDLIST_SOURCE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct NodeType{
    int info;
    struct NodeType *next;
}NodeType;

extern NodeType *front, *p;

void inicializalas();
NodeType Create(NodeType **);
void ListaBejaras();
void ElemBeszurasElore(int num);
void ElemBeszurasVegere(int num);
void BeszurasMegadottHelyre(int num, int poz);
void TorlesElsoElem();
void TorlesUtolsoElem();
void ListabolTorles(int torlendo);
void ListaTeljesTorlese();
bool ListabanKereses(int n);

#endif //SINGLELINKEDLIST_SOURCE_H
