//
// Created by Kataee on 01/06/2021.
//

IntArray* create(int size){
    //allocating memory
    IntArray* newArray = (IntArray*)malloc(sizeof(IntArray));

    if (!newArray) {    //check if memory was allocated successfully
        printf("Error creating IntArray\n");
        exit(1);
    }

    //setting size, maximum number of strings
    newArray->size = size;

    //allocating memory
    newArray->chr = (char**)malloc(size*sizeof(char*));
    if (!newArray->chr) {   //check if memory was allocated successfully
        printf("Error creating chr**\n");
        exit(2);
    }

    for (int i=0; i<size; ++i) {
        newArray->chr[i] = (char*)malloc(30*sizeof(char));   //allocating memory
        if (!newArray->chr[i]) {   //check if memory was allocated successfully
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
        if (feof(f)) {  //if end of file == true
            printf("End of file\n");
            //realloc(array->chr,i); //breaks the stuff
            //inkább free() a megmaradt felhasználatlan chr[x] részeket
            array->size = i; //adjusting size
            printf("Reallocated, size %i\n", array->size);
            fclose(f);  //closeing file
            return;
        }
        fscanf(f, "%s", array->chr[i]); //read a string from file and put into array
    }
}

//print the strings to the console
void print(IntArray *array) {
    //printf("%i: %s ",4, array->chr[4]);
    for (int i=0; i < array->size; ++i) {
        printf("%i: %s ",i, array->chr[i]);
    }
    printf("\n");
}


void add(IntArray* array, char* s) {
    array->size++; //increasing size
    int size = array->size;
    array->chr[size] = (char*)malloc(30*sizeof(char));  //allocating memory
    if (!array->chr[size]) {   //check if memory was allocated successfully
        printf("Error creating char[%i]\n", size);
        exit(5);
    }
    array->chr[size-1] = s;   //copy the given string into array


}

char* search(IntArray* array, char* s) {
    for (int i=0; i < array ->size; ++i) {
        if (strcmp(s, array->chr[i]) == 0) { //compare strings
            printf("String found: %s, index: %i\n", array->chr[i], i);
            return array ->chr[i]; //return found string
        }
    }
    printf("The searched string could not be found\n");
    return NULL; //return NULL if not found
}


//return array->size
int numOfElements(IntArray* array) {
    printf("Number of elements: %i\n", array->size);
    return array->size;
}

bool delete(IntArray* array, char* s) {
    int index=-1; //-1 for error handling
    if (search(array, s) != NULL) { //if true => delete

        //search the index of the element
        for (int i=0; i < array ->size; ++i) {
            if (strcmp(s, array->chr[i]) == 0) {
              index = i;
              break;
            }
        }

        //-1 for error handling
        if (index != -1) {
            for (int i=index; i < array->size-1; ++i) {
                strcpy(array->chr[i], array->chr[i+1]); //moving - copying elements
            }
            print(array);
            //free((void *) array->chr[array->size - 1]); // breaks the stuff
            array->size--; //decreasing size

            printf("Deletetd. size: %i\n", array->size);
            print(array);
        }



    } else { //if couldn't delete
        printf("Could not delete element, because it's not there!\n");
        return false;
    }
}