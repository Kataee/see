#include "source.h"

int main() {
    QUEUENODE* first;
    QUEUENODE* last;

    first = NULL;
    last = NULL;

    QUEUENODE *asd;
    createQueue(&asd);

    for (int i=0; i<3; ++i) {
        insertQueue(first, last, i);
    }
    printQueue(asd);




    return 0;
}
