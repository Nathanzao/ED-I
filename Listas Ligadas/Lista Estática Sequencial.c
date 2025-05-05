#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
É o uso de struct como um vetor. Veja que caso a gente deseje colocar algum elemento
*/

struct vetor
{
  int vet[10];
  int nelem;
};

void InserirVetor(struct vetor *L, int k){
    if(k == 10){
        return;
    }
    L->vet[k] = k; /* Ou você poderia colocar um printf aqui, para inserir o elemento. */
    L->nelem++;
    InserirVetor(L, k+1);
}

void ImprimirVetor(struct vetor L, int tamanho, int i){
    if(i == tamanho){
        return;
    }
    printf("%d", L.vet[i]);
    ImprimirVetor(L, tamanho, i+1);
} // Eu queria imprimir até a quantidade de elementos, do nelem. Como?

// E de trás pra frente?

int main (){
setlocale(LC_ALL, "Portuguese");
    struct vetor Vet;

    InserirVetor(&Vet, 0);
    ImprimirVetor(Vet, 10, 0);

return 0;
}