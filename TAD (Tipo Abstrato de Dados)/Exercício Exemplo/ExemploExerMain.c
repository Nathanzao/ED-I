#include <stdio.h>
#include <stdlib.h>
#include "ExemploExer.c"

int main (){

    ContaBancaria primeiraConta;
    Inicializa(&primeiraConta, 1111, 10000);
    Imprime(&primeiraConta);

    printf("\n\n");

    Deposito(&primeiraConta, 10);
    Imprime(&primeiraConta);

    printf("\n\n");

    Saque(&primeiraConta, 10);
    Imprime(&primeiraConta);

    printf("\n\n");


return 0;
}