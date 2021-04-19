#include "source.h"
int main() {
    IntArray* array1 = createArray(7);
/*
    char fileName[20];
    printf("Ird be a file nevet.\n");
    scanf("%s", fileName);
*/
    char fileName[]="in.txt";
    readArray(fileName, &array1);
    printArray(array1);

    IntArray* array2 = createArray(5);
    fillArray(array2->elements, array2->size, 0, 50);
    printArray(array2);
/*
    char outFile[20];
    printf("Ird be a kimeno file nevet.\n");
    scanf("%s", outFile);
  */
    char outFile[] = "out.txt";


    printArrayToFile(outFile, array2);


    return 0;
}
