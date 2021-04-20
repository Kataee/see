#include "header.h"
int main() {

    Set set, set1, set2, set3, set4, set5, set6;
    createSet(&set);


    printf("Size: %i\n", size(set));
    isEmpty(set) ? printf("isEmpty: true\n") : printf("isEmpty: false\n");

    for (int i=15; i>10; --i) {
        insert(&set, i);
        printElements(set);
    }
    erase(&set, 14);
    printElements(set);

    erasePos(&set, 2);
    printElements(set);

    find(set, 16);
    lowerBound(set, 13);
    upperBound(set, 12);


    //unite
    createSet(&set1);
    createSet(&set2);
    createSet(&set3);
    createSet(&set4);
    createSet(&set5);
    createSet(&set6);
    printf("check\n");

    for (int i=1; i<11; i++) {
        insert(&set1, i);
        insert(&set2, i+4);

    }
    printElements(set1);
    printElements(set2);
    uniteSet(&set1, &set2, &set3);
    printf("A ket halmaz egyesitve: ");
    printElements(set3);
    printf("\n");

    //cross Section
    crossSection(&set1, &set2, &set4);
    printf("A ket halmaz metszete: ");
    printElements(set4);
    printf("\n");

    //substraction
    substraction(&set1, &set2, &set5);
    printf("A ket halmaz kulombsege: ");
    printElements(set5);
    printf("\n");

    //subset
    subset(&set1, &set6, -234,7);
    printf("A reszhalmaz: ");
    printElements(set6);
    printf("\n");

    return 0;
}
