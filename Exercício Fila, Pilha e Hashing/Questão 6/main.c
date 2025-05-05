#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "TAD.c"

/*

*/

int main() {
    setlocale(LC_ALL, "Portuguese");

    struct Fila f;
    criarFila(&f);

    enfileirar(&f, 10);
    enfileirar(&f, 20);
    enfileirar(&f, 30);

    imprimir(&f);

    int removido;
    if (desenfileirar(&f, &removido)) {
        printf("Removido: %d\n", removido);
    }

    imprimir(&f);

    int primeiro;
    if (primeiroElemento(&f, &primeiro)) {
        printf("Primeiro elemento: %d\n", primeiro);
    }

    return 0;
}
