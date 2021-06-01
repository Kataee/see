#include "intArray/intArray.h"
#include "intArray/intArray.c"

int main() {
    IntArray* arr = create(15);
    read("in.txt", arr);
    print(arr);
    char* s = "asd";
    add(arr, s);
    add(arr, s);
    print(arr);
    return 0;
}
