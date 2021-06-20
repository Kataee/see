#include "header.h"
#include "source.c"

int main() {
    FILE* f;
    if ((f = fopen("in.txt", "r")) == NULL) {
        printf("Error opening file in Main\n");
        return 0;
    }
    int size;
    fscanf(f, "%d", &size);
    fclose(f);
    wordarray_t * asd = wordarray_create(size);
    if (asd == NULL) {
        printf("Main: asd == NULL, return\n");
        return 0;
    }
    load3("in.txt", asd);
    print3(asd);

    sortBooks(asd);
    print3(asd);

    int* stat = (int*)calloc(26, sizeof(int));
    if (stat == NULL) {
        printf("Cannot create stat\n");
        return 0;
    }
    for (int i=0; i < 3; ++i) {
        //printf("%c ", asd->cim[0][1]);
        //int a = asd->cim[i][1];
        //printf("a: %d", a);
        stat[(asd->cim[i][1]-97)]++;
    }
    printf("\n");
    for (int i=0; i < 26; ++i) {
        printf("%i ", stat[i]);
    }
    printf("\n");



    return 0;
}

/*
  for (int i=0; i < asd->size; ++i) {
        printf("%s ", asd->szerzo[i]);
    }
 */