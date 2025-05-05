#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
O hashing é dar uma chave e ela indicar um endereço em certo armazenamento: mostra o indice de alguma informação.
Tipos:
    Encadeamento interno: uma parte do vetor (a mais para o final), é dedicada apenas para armazenar as colisões (com um limite).
    Encadeamento interno aberto (linear): só ver as próximas instruções, e colocar as colisões onde haver -1.
    Encadeamento externo: em cada posição do vetor há um ponteiro para uma lista encadeada. Essa lista encadeada contém os elementos
que tem colisão encadeados.
*/

int main (){
setlocale(LC_ALL, "Portuguese");

return 0;
}