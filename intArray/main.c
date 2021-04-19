#include "source.h"
int main() {
    IntArray* array1 = createArray(7);

    char fileName[20];
    printf("Ird be a file nevet.\n");
    scanf("%s", fileName);
    readArray(fileName, &array1);
    printArray(array1);

    IntArray* array2 = createArray(5);
    fillArray(array2->elements, array2->size, 0, 50);
    printArray(array2);


    return 0;
}
