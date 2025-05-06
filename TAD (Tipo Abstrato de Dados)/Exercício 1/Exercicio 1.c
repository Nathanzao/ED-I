#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Exercicio 1.h"


/* 

1) Deseja-se cadastrar os candidatos que estão sendo entrevistados para uma vaga de
garçom. Este cadastro deve conter os seguintes campos:
● RG: que será usado como chave de busca. Não podem existir dois candidatos com
mesmo número de RG (string 15);
● Nome: nome do candidato (string 50);
● Telefone: telefone para contato (string 14 – o formato é livre, mas o tamanho do campo
deve ser grande o suficiente para conter números do tipo: (999) 999-9999);
● Endereço: endereço para contato. Em caso de convocação, este endereço será
utilizado para enviar correspondências (string 60).
Os dados devem ser mantidos em um vetor em memória com no máximo N (N=200) posições.



O programa deve conter as seguintes operações:

● Pesquisa: dado o RG de um candidato, esta operação deve retornar o valor (-1) caso o
mesmo não esteja cadastrado, ou a posição no vetor onde se encontra;
● Inserção: os candidatos são inseridos no vetor de forma não ordenada, sempre na
última posição do mesmo, até que seja atingido o seu tamanho máximo ou que não
haja outros candidatos. Não será permitido o cadastramento de dois candidatos com o
mesmo RG (duplicação de chaves). A operação Inserção deve usar a operação
Pesquisa para verificar se não há ou não duplicação de candidatos.
● Remoção: dado um RG, é feita uma pesquisa no vetor através da operação Pesquisa
para verificar se existe ou não um candidato com este RG. Caso exista, o último
candidato é sobreposto ao que esta sendo removido, fazendo-se a seguir os demais
ajustes necessários à remoção de um registro. Antes de ser feita a remoção, os dados
detalhados do candidato a ser removido devem ser apresentados ao usuário e em
seguida ser confirmada a sua remoção.
● Alteração: dado um RG, é feita uma pesquisa no vetor através da operação Pesquisa
para verificar se existe ou não um candidato com este RG. Caso exista, os dados
atuais deste candidato são mostrados ao usuário, solicitando em seguida os dados
para alteração. O RG não pode ser alterado! O usuário deve ter a oportunidade de
manter um ou mais campos inalterados. */

int Pesquisa(Garcom* cadastro, int RG){
    int i = 0;
    
    for(i = 0; i < 15; i++){
        if(cadastro->RG[i] == RG){
            return i;
        }
    }
    return -1;
}



void Insercao(Garcom* cadastro, int RG, char *nome, double telefone, char *endereco, int tamanho){
    if(Pesquisa(cadastro, RG) == -1){
        if(tamanho < 15){
            cadastro->endereco
        }
    }
}




void Remocao(Garcom* cadastro, int RG, char *nome, double telefone, char *endereco);
void Alteracao(Garcom* cadastro, int RG, char *nome, double telefone, char *endereco);