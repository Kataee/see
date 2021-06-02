//
// Created by Kataee on 19/05/2021.
//
#include "header.h"

HASHTABLE create(int capacity) {
    HASHTABLE newHashTable;

    newHashTable.capacity = capacity;
    newHashTable.elements=0;

    newHashTable.table = (int*)malloc(capacity * sizeof(int));
    if (!newHashTable.table) {
        printf("Error creating hashtable.table");
        exit(1);
    }

    for (int i=0; i<newHashTable.capacity; ++i) {
        newHashTable.table[i] = -1;
    }

    return newHashTable;
}


void insert(HASHTABLE* h, int element) {
    int i=0,j;

    do {
        j = (element + i) % h->capacity;
        if (h->table[j] == -1) {
            h->table[j] = element;
            return;
        } else {
            i++;
        }
    }

    while (i!=h->capacity);
    printf("Tulcsordulas\n");
    return;
}
/*
void delete(HASHTABLE* h, int element) {
    for (int i=0; i<h->capacity; ++i) {
        if (h->table[i] == element) {
            printf("Deleting %i\n", h->table[i]);
            h->table[i] = -1;
        }
    }
}
 */

void delete(HASHTABLE* h, int element) {
    int i = 0,j;

    do {
        j=(element+i) % h->capacity;
        if (h->table[j] == element) {
            printf("Deleting %i\n", h->table[j]);
            h->table[j] = -1;
            break;
        } else {
            i++;
        }

    }
    while (( h->table[j] != -1) && (i != h->capacity));
    if (i != h->capacity) {
        printf("Hianyzo elem??\n");
    }
}

int search (HASHTABLE h, int element) {
    int i=0,j=0;

    do {
        j=(element+i) % h.capacity;
        if (h.table[j] == element) {
            return j;
        } else {}
        i++;
    }
    while ((h.table[j] != -1) && (1 != h.capacity));
    return -1; //ha nincs meg a keresett elem
}


void print(HASHTABLE h) {
    printf("Print hash: ");
    for (int i=0; i<h.capacity; ++i) {
        printf("%i ", h.table[i]);
    }
    printf("\n");
}

void destroy(HASHTABLE h) {
    h.elements = 0;
    h.capacity = 0;
    free(h.table);

}


void fel2() {
    int length, temp, causes = 0;
    FILE *f;
    //open file and check if ok
    if ((f=fopen("in.txt",  "r")) == NULL) {
        printf("Error opening file");
        exit(2);
    }
    //read length
    fscanf(f, "%i", &length);
    //length++;
    printf("File length: %i\n", length);

    //create hash
    HASHTABLE a = create(length);
    int* arr = (int*)malloc((length+1) * sizeof(int));
    if (!arr) {
        printf("Error creating arr pointer\n");
        exit(3);
    }


    //read input and put in hash
    for (int i=0; i<length; ++i) {
        fscanf(f, "%i", &temp);
        insert(&a,temp);
        arr[i+1] = temp;
    }

    //print hash
    printf("Sajnos nem az input szerinti sorrendbe kerulnek be az elemek\n emiatt nem jo az eredmeny sem hash eseten, vagyis az A[j]-A[i]\n\n");
    print(a);

    printf("We found %i matches in hash\n\n", calc(length, a));

    //print array
    printArr(length, arr);
    printf("We found %i matches in simple array\n", calcArr(length+1, arr));
}

int calc(int length, HASHTABLE a) {
    int causes =0;
    for (int i=0; i<length; ++i) {
        for (int j=i+1; j<length; ++j) {
            printf("%i :: %i\n",a.table[j]-a.table[i], (i+1)*(i+1)+(j+1)*(j+1) );
            if (a.table[j]-a.table[i] == (i+1)*(i+1)+(j+1)*(j+1)) {
                printf("Element: %i :: %i\n", a.table[i], a.table[j]);
                causes++;
            }
        }
    }
    return causes;
}

int calcArr(int length, int* arr) {
    int causes =0;
    for (int i=1; i<length; ++i) {
        for (int j=i+1; j<length; ++j) {
            printf("%i :: %i\n",arr[j]-arr[i], i*i+j*j );
            if (arr[j]-arr[i] == (i*i+j*j)) {
                printf("Element: %i :: %i\n", arr[i], arr[j]);
                causes++;
            }
        }
    }
    return causes;
}

void printArr(int length, int *arr) {
    printf("Print array: ");
    for (int i=1; i<length; ++i) {
        printf("%i ", arr[i]);
    }
    printf("\n");
}

/*
 for (int i=0; i<length; ++i) {
        for (int j=i+1; j<length; ++j) {
            printf("%i :: %i\n",a.table[j]-a.table[i], i*i+j*j );
            if (a.table[j]-a.table[i] == (i*i+j*j)) {
                printf("Element: %i :: %i\n", a.table[i], a.table[j]);
                causes++;
            }
        }
    }
 */