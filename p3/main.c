#include "intArray/intArray.h"
#include "intArray/intArray.c"
#include "hash/hash.c"
#include "hash/hash.h"

int main() {

    IntArray* arr = create(25);
    read("in.txt", arr);
    print(arr);
    char* s = "asd";
    add(arr, s);
    print(arr);
    search(arr, "prevent");
    numOfElements(arr);
    delete(arr, "prevent");
    add(arr, "dsdfsdf");
    //add(arr, "dsdfsd234f");
    //add(arr, "dsdfsdf23");
    print(arr);
    delete(arr, "choke"); //error here if we add element more than 2 times, strcpy

    print(arr);
    //printf("qqq: %s", arr->chr[10]);


    //HASHTABLE* hash = create(10);


    return 0;
}
