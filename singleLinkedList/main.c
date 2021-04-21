

#include "source.h"
int main() {
    NodeType **asd = NULL;
    inicializalas();
    Create(&asd);
    ListaBejaras();
    ElemBeszurasElore(1);
    ElemBeszurasElore(2);
    ElemBeszurasElore(3);
    ElemBeszurasElore(4);
    ListaBejaras();
    ElemBeszurasVegere(9);
    ListaBejaras();

    BeszurasMegadottHelyre(99,3);
    ListaBejaras();

    TorlesElsoElem();
    ListaBejaras();

    TorlesUtolsoElem();
    ListaBejaras();

    ListabolTorles(2);
    ListaBejaras();

    ListabanKereses(99) ? printf("VAN\n") : printf ("nincs\n");

    ListaTeljesTorlese();
    ListaBejaras();
    return 0;
}
