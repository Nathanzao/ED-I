#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
Implementação da Lista Generalizada.
*/

enum elem_tipo{
    tipo_int,
    tipo_char,
    tipo_sublista
};

struct No{
    enum elem_tipo tipo;
    union {
        int atomo;
        char c;
        struct No *sublista;
    } info;
    struct No *prox;
};

void CriaNoInteiro(struct No *n, int valor){
    struct No *novoNo = malloc(sizeof(No));
    novoNo->atomo = valor;
    novoNo->tipo = tipo_int;
    n->prox = novoNo;
    novoNo->prox = NULL;;
}

void CriaNoCaractere(struct No *n, char valor){
    struct No *novoNo = malloc(sizeof(No));
    novoNo->c = valor;
    novoNo->tipo = tipo_char;
    n->prox = novoNo;
    novoNo->prox = NULL;
}

void CriaNoSublista(struct No *n, struct No *sublista){
    struct No *novoNo = malloc(sizeof(No));
    novoNo->tipo = tipo_sublista;
    novoNo->info.sublista = sublista;
    n->prox = novoNo;
    novoNo->prox = NULL;
}

void imprime_lista(No* lista) {
    while (lista != NULL) {
        switch (lista->tipo) {
            case tipo_int:
                printf("Inteiro: %d\n", lista->info.atomo);
                break;
            case tipo_char:
                printf("Caractere: %c\n", lista->info.c);
                break;
            case tipo_sublista:
                printf("Sublista:\n");
                imprime_lista(lista->info.sublista);  // Recursão para imprimir a sublista
                break;
        }
        lista = lista->prox;
    }
}

int main (){
setlocale(LC_ALL, "Portuguese");
    No lista = NULL;
    No sub1 = NULL;

    CriaNoInteiro(&lista, 5);
    CriaNoCaractere(&lista, "a");
    CriaNoSublista(&lista, &sub1);

    imprime_lista(&lista);


return 0;
}
