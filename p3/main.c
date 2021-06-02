#include "intArray/intArray.h"
#include "intArray/intArray.c"

int main() {
    IntArray* arr = create(15);
    read("in.txt", arr);
    print(arr);
    char* s = "asd";
    add(arr, s);
    print(arr);
    search(arr, "prevent");
    numOfElements(arr);
    delete(arr, "prevent");
    //printf("qqq: %s", arr->chr[10]);
    return 0;
}
