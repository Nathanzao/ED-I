/* 
#include <stdio.h>
struct vetor
{
  int vet[10];
  int nelem;
};
	
	
int main() {
 struct vetor x, x1, x2, xn;
	  x.vet[0] = 10;
	  x.nelem = 1;
	  printf("%d",x.vet[0]);
	  return 0;



for(int i = 0; i < 10; i++){
        L->vet[i] = 
    }
 */

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct vetor
{
  int vet[10];
  int nelem;
};

void InserirVetor(struct vetor *L, int k){
    if(k == 10){
        return;
    }
    L->vet[k] = k;
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