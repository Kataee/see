#include <stdio.h>
#include "source.h"

int main() {
    STACKNODE *topPtr;
    create(&topPtr);
    for (int i=0; i<5; ++i) {
        push(&topPtr,i);
    }
    printStack(topPtr);

    printf("top: %i \n", top(topPtr));
    printStack(topPtr);
    pop(&topPtr);
    //printf("pop: %i \n", pop(&topPtr));
    printStack(topPtr);

    return 0;
}
