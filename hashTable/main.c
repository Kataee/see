#include "header.h"
#include "source.c"

int main() {

    HASHTABLE h = create(10);
    print(h);
    insert(&h,4);
    insert(&h,33);
    print(h);

    delete(&h,4);
    print(h);
    insert(&h,33);
    print(h);
    printf("Keres. index: %i\n", search(h,33));
    printf("\n2.feladat\n");

    fel2();


    return 0;
}
