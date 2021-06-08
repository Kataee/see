#include "source.h"

int main() {
    printf("asd");


    QUEUENODE *asd;
    createQueue(&asd, 10);
    isEmptyQueue(asd) ? printf("A queue ures\n") : printf("A queue nem ures\n");
    isFullQueue(asd) ? printf("A queue tele\n") : printf("A queue nincs tele\n");
    insertQueue(asd, 365);
    printQueue(asd);
    printf("Remove first item: %i\n", removeFirstItemQueue(asd));
    fillQueue(asd);
    printQueue(asd);
    topItemQueue(asd);
    printf("Remove first item: %i\n", removeFirstItemQueue(asd));
    printf("Remove first item: %i\n", removeFirstItemQueue(asd));
    printf("Remove first item: %i\n", removeFirstItemQueue(asd));
    insertQueue(asd, 9);
    printQueue(asd);



    return 0;
}
