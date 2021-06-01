//
// Created by Kataee on 01/06/2021.
//

IntArray* create(int size){
    IntArray* newArray = (IntArray*)malloc(sizeof(IntArray));
    if (!newArray) {
        printf("Error creating IntArray\n");
        exit(1);
    }

    newArray->size = size;
    newArray->chr = (char**)malloc(size*sizeof(char*));
    if (!newArray->chr) {
        printf("Error creating chr**\n");
        exit(2);
    }

    for (int i=0; i<size; ++i) {
        newArray->chr[i] = (char*)malloc(30*sizeof(char));
        if (!newArray->chr[i]) {
            printf("Error creating char[%i]\n", i);
            exit(3);
        }
        //printf("char: %s\n", newArray->chr[i]);
    }
    printf("Array created.\n");

    return newArray;
}

void read(const char* fileName, IntArray *array) {
    FILE *f; //file stream

    // check if file can be opened
    if ((f = fopen(fileName, "r")) == NULL) {
        printf("Error opening file"); exit(4);
    }
    printf("size %i\n", array->size);
    //read
    for (int i=0; i < array->size; ++i) {
        if (feof(f)) {
            printf("End of file\n");
            //realloc(array->chr,i); //breaks the stuff
            array->size = i;
            printf("Reallocated, size %i\n", array->size);
            fclose(f);
            return;
        }
        fscanf(f, "%s", array->chr[i]);
        //printf("len: %i ", strlen(s));
        //strcpy(array->chr[i] ,s);
        //printf("chr %i: %s\n",i, array->chr[i]);
    }
}


void print(IntArray *array) {
    //printf("%i: %s ",4, array->chr[4]);
    for (int i=0; i < array->size; ++i) {
        printf("%i: %s ",i, array->chr[i]);
    }
    printf("\n");
}

void add(IntArray* array, char* s) {
    array->size++;
    int size = array->size;
    array->chr[size] = (char*)malloc(30*sizeof(char));
    if (!array->chr[size]) {
        printf("Error creating char[%i]\n", size);
        exit(5);
    }
    array->chr[size-1] = s;


}








