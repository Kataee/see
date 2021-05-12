#include "header.h"
#include "source.c"


int main() {
    heap *h = createHeap(32);


    FILE *f = fopen("input.txt", "r");
    int buffer;
    while (fscanf(f, "%i", &buffer) != EOF) {
        insert(h, buffer);
    }

    printf("Print as it is:\n");
    for (int i=1; i <= h->size; ++i) {
        printf("%i ", h->data[i]);
    }

    printf("\nmax: %i\n", max(h));

    printf("\nsize before sort: %i\n", h->size);



    kupacrendez(h);
    printf("size after sort: %i\n", h->size);
    printf("Print after sorting\n");
    for (int i=1; i <= h->size; ++i) {
        printf("%i ", h->data[i]);
    }
    /*
    printf("%i ", h->data[1]);
    printf("%i ", h->data[2]);
    printf("%i ", h->data[3]);
    printf("%i ", h->data[9]);
*/
    fclose(f);

    return 0;
}
