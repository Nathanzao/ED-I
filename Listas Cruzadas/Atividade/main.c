#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "ME.c"

/*

*/

int main (){
setlocale(LC_ALL, "Portuguese");

    struct matriz p;
    inicializar(&p);

    for(int i = 0; i < LINHA; i++){
        for(int j = 0; j < COLUNA; j++){
            insere(&p, i, j, (i + j));
        }
    }

    removerElemento(&p, 2, 2);
    removerElemento(&p, 2, 1);
    removerElemento(&p, 2, 3);

    imprime(&p);

    somarNaLinha(&p, 3, 3);

    imprime(&p);

return 0;
}