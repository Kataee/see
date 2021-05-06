#include "header.h"

int main() {

    Node* asd =NULL;

    //27, 14, 35, 10, 19, 31, 42
    insert(&asd, 27);
    insert(&asd, 14);
    insert(&asd, 35);
    insert(&asd, 10);
    insert(&asd, 19);
    insert(&asd, 31);
    insert(&asd, 42);

    printf("inorder ");
    inorder(asd);
    printf("\n");
    printf("preorder ");
    preorder(asd);
    printf("\n");
    printf("postorder ");
    postorder(asd);
    printf("\n");
    find(asd, 7) ? printf("True\n") : printf("False\n");

    //deleteNode(asd, 8);
    inorder(asd);
    printf("Max: %i \n", maxValueNode(asd)->info);
    printf("Min: %i \n", minValueNode(asd)->info);
    nextNode(asd) ? printf("Next: %i \n", asd->right->info) : printf("Nincsz\n");
    printf("Min: %i \n", minValueNode(asd)->info);

    //struct Node* temp = parent(asd,5);
    //printf("parent: %i\n", temp->info);


    fel2();
    //haha ez a B sequence nem clean code + még
    // lehetne fÜggvényesíteni is, de sokat gondolkodtam rajta
    //mire egészen összeállt az egész, ezért hagytam benne mindenféle kiírást is
    //hogy lássék benne a munkám, nem mindenkinek megy ám olyan könnyen, hiába
    //easy level a feladat #kellazátmenő

    return 0;
}
