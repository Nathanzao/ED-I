#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 50
/*

*/

enum UnidadesServicoTipo{
    ambulancia = 1, /* Tempo 3 de registro. Tempo 4 de processamento. */
    bombeiro, /* 2 */ /* Tempo 7. Tempo 2 de processamento. */
    policia /* 3 */ /* Tempo 9. Tempo 5 de processamento. */
};

struct Bairro{
    int id;
    char nomeBairro[50]; /* Tamanho máximo de 50 caracteres para o bairro. */
    struct Bairro *prox;
}; /* Será usado na tabela Hash. */

struct Cidadao{
    char CPF[20];
    char nomePessoa[30];
    char email[30];
    char endereco[30];
    char bairro[30];
    struct Cidadao *prox;
};

struct UnidadeServico{
    int id;
    enum UnidadesServicoTipo tipoUnidade;
    char nomeServico[50];
    char endereco[50];
    char bairro[30];
    struct UnidadeServico *prox;
}; /* Será usada na fila. */

struct Ocorrencia{
    int id;
    char cpfCidadao[20];
    int gravidade; /* 0 à 5 */
    enum UnidadesServicoTipo tipo;
    int IdDoBairro;
    struct Ocorrencia *prox;
}; /* Será usado na fila com prioridade. A prioridade é de 0 à 5 na gravidade. */

struct Ocorrencia *filaOcorrencias; /* Fila com prioridade das ocorrências. */
struct Cidadao *listaCidadoes;
struct UnidadeServico *listaDeServicos; /* Lista de serviços cadastrados. */
struct Bairro *tabelaHashing[MAX]; /* Tabela Hashing dos bairros. */

void cadastrarBairro(int id, char *nome);
void cadastrarCidadao(char *cpf, char *nome, char *email, char *endereco, char *bairro);
void cadastrarServico(int idDesejado, int tipo, char *nome, char *endereco, char *bairro);
void registrarOcorrencia(int idDaOcorrencia, char *cpfCidadaoSolicitante, int prioridade, int tipoDaOcorrencia, int idDoBairroAlvo);

void processarOcorrencia(); /* Apenas para aparecer os dados da ocorrência mais importante antes de ser removida. */
void exibirOcorrencias();
int funcaoHashing(int id); /* Para cadastro dos bairros */
void inicializaTabela(); /* Inicialização da tabela hashing. */




/* ESTRUTURAS DE EXIBICAO */

void exibirServicosRegistrados();
void exibirBairrosRegistrados();
void exibirCidadoesRegistrados();
void exibirTudo();


void simulacao();
void tempo(); /* Será usada como métrica de tempo. Toda vez que uma ocorrência for inserida ou processada, irá aumentar 1. */
int tempoAtual; /* Será usado no tempo. */
int simulacoes = 1;
void limparTudo(); /* Tirar todas as memórias do MALLOC. */

/* Aleatoriedade de dados: */

#define MAX_DADOS 100 /* Máximo de linhas para cada tipo aleatorio. */

char nomes[MAX_DADOS][50];
char cpfs[MAX_DADOS][50];
char emails[MAX_DADOS][50];
char bairros[MAX_DADOS][50];
char nomeServicos[MAX_DADOS][50];
char enderecos[MAX_DADOS][50];

int totalNome = 0, totalCPF = 0, totalEmail = 0, totalBairro = 0, nomeServicoss = 0, enderecoss = 0; /* Armazenar o total de linhas de cada tipo. */
int carregarArquivo(char *nomeArquivo, char dados[][50], int maxLinhas); /* Armazena os tipos nesse vetor. */
void carregarDados();
