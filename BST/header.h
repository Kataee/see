//
// Created by Kataee on 28/04/2021.
//

#ifndef UNTITLED1_HEADER_H
#define UNTITLED1_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node {
    int info;
    struct Node *left, *right;
} Node;

Node* create();
Node* insert (Node**, int);
void inorder(Node*);
void preorder(Node*);
void postorder(Node*);

bool find(struct Node* , int);
struct Node* deleteNode(struct Node*, int);
Node* delete(Node**, int);
struct Node* minValueNode(struct Node* );
struct Node* maxValueNode(struct Node* );

struct Node* nextNode(struct Node*);
struct Node* parent (struct Node*, int);


void fel2();
int findMax(int*, int);
int hasValue(int*, int, int);
void print(int*, int);

#endif //UNTITLED1_HEADER_H
