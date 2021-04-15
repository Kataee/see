#include "source.h"
int main() {
    IntArray* array1 = createArray(7);

    char fileName[20];
    printf("Ird be a file nevet.\n");
    scanf("%s", fileName);
/*
    FILE *f;

    if ((f= fopen(fileName, "r")) == NULL) {
        printf("Error opening file");
        return 0;
    }
    printf("%ixxx", (*array1).size);

    for (int i=0; i< (*array1).size;++i) {
        fscanf(f, "%i", &(*array1).elements[i]);
        printf("%i ", (*array1).elements[i]);
    }
*/

    readArray(fileName, &array1);


    return 0;
}
