#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*

*/

typedef struct
{
    int numero;
    double saldo;
} ContaBancaria;


void Inicializa(ContaBancaria* conta, int numero, double saldo);
void Deposito (ContaBancaria* conta, double valor);
void Saque (ContaBancaria* conta, double valor);
void Imprime (ContaBancaria *conta);


/* Não ponha mains, tanto no .c quanto no .h */
