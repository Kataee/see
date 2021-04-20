#include "header.h"

int main() {
    STACK s = createStack(17);
    isEmpty(&s) ? printf("empty\n") : printf("NOT empty");

    for (int i=0; i<17; ++i) {
        push(&s, i);
    }
    printf("\n");

    print(s);
    pop(&s);
    print(s);
    push(&s,33);
    print(s);push(&s,33);
    print(s);

    printf("top: %i\n", top(&s));


    return 0;
}
