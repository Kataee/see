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
            //inkább free() a megmaradt felhasználatlan chr[x] részeket
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

char* search(IntArray* array, char* s) {
    for (int i=0; i < array ->size; ++i) {
        if (strcmp(s, array->chr[i]) == 0) {
            printf("String found: %s, index: %i\n", array->chr[i], i);
            return array ->chr[i];
        }
    }
    printf("The searched string could not be found\n");
    return NULL;
}



int numOfElements(IntArray* array) {
    printf("Number of elements: %i\n", array->size);
    return array->size;
}

bool delete(IntArray* array, char* s) {
    int index=-1;
    if (search(array, s) != NULL) { //if true => delete

        //search the index of the element
        for (int i=0; i < array ->size; ++i) {
            if (strcmp(s, array->chr[i]) == 0) {
              index = i;
              break;
            }
        }

        //error handling
        if (index != -1) {
            for (int i=index; i < array->size-1; ++i) {
                strcpy(array->chr[i], array->chr[i+1]);
            }
            print(array);
            free((void *) array->chr[array->size - 1]); // breaks the stuff
            array->size--;

            printf("Deletetd. size: %i\n", array->size);
            print(array);
        }



    } else {
        printf("Could not delete element, because it's not there!\n");
        return false;
    }
}








