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
    wordarray_t * asd = wordarray_create3(size);
    if (asd == NULL) {
        printf("Main: asd == NULL, return\n");
        return 0;
    }
    load3("in.txt", asd);
    print3(asd);

    sortBooks3(asd);
    print3(asd);

    int* stat3 = createStat3(asd);
    printStat3(stat3);




    return 0;
}

/*
  for (int i=0; i < asd->size; ++i) {
        printf("%s ", asd->szerzo[i]);
    }
 */