#include "intArray/intArray.h"
#include "intArray/intArray.c"

int main() {
    IntArray* arr = create(15);
    read("in.txt", arr);

    return 0;
}
