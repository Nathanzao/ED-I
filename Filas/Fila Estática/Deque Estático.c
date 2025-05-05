#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
Deque estático. Final sempre aponta para a próxima posição vaga. O inicio não.
*/

struct Aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

struct deque{
    int inicio;
    int final;
    int quantidade;
    struct Aluno dados[5];
};

void criaDeque(struct deque *q){
    q->quantidade = 0;
    q->final = 0;
    q->inicio = 0;
}

void insereInicio(struct deque *q, struct Aluno al){
    if(q->quantidade == 5){
        printf("\n\nNao ha mais espaco para inserir nada.\n\n");
        return;
    }
    
    
    q->inicio--;
    if(q->inicio < 0){
        q->inicio = 5 - 1; /* Ultima posição é quatro. Veja que 3 % 5 = 3, logo não muda nada ter o máximo, só para a última posição. */
    }
    q->dados[q->inicio] = al;
    q->quantidade++;
}

void insereFinal(struct deque *q, struct Aluno al){
    if(q->quantidade == 5){
        printf("\n\nNao ha mais espaco para inserir nada.\n\n");
        return;
    }

    q->dados[q->final] = al;
    q->final = (q->final + 1) % 5; /* Veja que caso seja o último elemento o final, vai ir para zero.  */
    q->quantidade++;
}

void removeInicio(struct deque *q){
    if(q->quantidade == 0){
        printf("\n\nNao ha como remover mais nada.\n\n");
        return;
    }

    q->inicio = (q->inicio + 1) % 5; /* Vai pular 1 elemento para frente. */
    q->quantidade--;
}

void removeFinal(struct deque *q){
    if(q->quantidade == 0){
        printf("\n\nNao ha como remover mais nada.\n\n");
        return;
    }

    q->final--;
    if(q->final < 0){
        q->final = 4;
    }
    q->quantidade--;

}

void imprime(struct deque *q){
    for(int i = 0; i < q->quantidade; i++){
        int idx = (q->inicio + i) % 5;
        printf("Matricula: %d.\n", q->dados[idx].matricula);
        printf("N1: %f.\n", q->dados[idx].n1);
        printf("N2: %f.\n", q->dados[idx].n2);
        printf("N3: %f.\n", q->dados[idx].n3);
        printf("Nome: %s.\n", q->dados[idx].nome);
        printf("\n\n");
    }
}

void liberaDeque(struct deque *q){
    free(q);
}

int main (){
setlocale(LC_ALL, "Portuguese");

    struct deque *dq = malloc(sizeof(struct deque));
    struct Aluno al;

    criaDeque(dq);

    // Aluno 1
    al.matricula = 123;
    al.n1 = 2;
    al.n2 = 6;
    al.n3 = 7;
    strcpy(al.nome, "Nathan");
    insereInicio(dq, al);

    // Aluno 2
    al.matricula = 222;
    al.n1 = 5;
    al.n2 = 7;
    al.n3 = 9;
    strcpy(al.nome, "Pedro");
    insereFinal(dq, al);

    // Aluno 3
    al.matricula = 333;
    al.n1 = 8;
    al.n2 = 9;
    al.n3 = 10;
    strcpy(al.nome, "Joao");
    insereFinal(dq, al);

    printf("Deque apos insercoes:\n");
    imprime(dq);

    printf("\nRemovendo do final...\n");
    removeFinal(dq);

    printf("\nDeque apos remocao:\n");
    imprime(dq);

    liberaDeque(dq);
    return 0;
}