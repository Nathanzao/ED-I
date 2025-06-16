#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "Estruturas.h"
/*

*/

struct Ocorrencia *filaOcorrencias = NULL;
struct Bairro *tabelaHashing[MAX];
struct UnidadeServico *listaDeServicos = NULL;
struct Cidadao *listaCidadoes = NULL;

int funcaoHashing(int id){
    return id % MAX;
}

void inicializaTabela(){
    for(int i = 0; i < MAX; i++){
        tabelaHashing[i] = NULL;
    }
}

void cadastrarBairro(int id, char *nome){
    int indice = funcaoHashing(id);

    struct Bairro *novo = malloc(sizeof(struct Bairro));

    novo->id = id;
    strcpy(novo->nomeBairro, nome);
    novo->prox = NULL;

    if(tabelaHashing[indice] != NULL){ /* Primeira posição já tem alguém. Iniciaremos o tratamento de colisão. */
        struct Bairro *atual = tabelaHashing[indice];;
        while(atual->prox != NULL){ /* Fica percorrendo até que o próximo seja NULL. */
            atual = atual->prox; 
        }
        atual->prox = novo;
        novo->prox = NULL;
    }else{
        tabelaHashing[indice] = novo;
    }
}

void cadastrarCidadao(char *cpf, char *nome, char *email, char *endereco, char *bairro){
    struct Cidadao *novo = malloc(sizeof(struct Cidadao));

    strcpy(novo->CPF, cpf);
    strcpy(novo->nomePessoa, nome);
    strcpy(novo->email, email);
    strcpy(novo->endereco, endereco);
    strcpy(novo->bairro, bairro);
    novo->prox = NULL;

    novo->prox = listaCidadoes;
    listaCidadoes = novo;
    
}

void cadastrarServico(int idDesejado, int tipo, char *nome, char *endereco, char *bairro){
    struct UnidadeServico *unidadeNova = malloc(sizeof(struct UnidadeServico));

    unidadeNova->id = idDesejado;
    unidadeNova->tipoUnidade = tipo;
    strcpy(unidadeNova->nomeServico, nome);
    strcpy(unidadeNova->endereco, endereco);
    strcpy(unidadeNova->bairro, bairro);

    unidadeNova->prox = listaDeServicos; /* Inserindo na lista de serviços. */
    listaDeServicos = unidadeNova;
    
}

void exibirBairrosRegistrados(){
    int indice;

    for(indice = 0; indice < MAX; indice++){
        struct Bairro *p = tabelaHashing[indice];
        
        while(p != NULL){
            printf("Nome: %s\n", p->nomeBairro);
            printf("Id: %d\n", p->id);

            p = p->prox;
            printf("\n\n\n");
        }
        
    }
}

void exibirServicosRegistrados(){
    struct UnidadeServico *p = listaDeServicos;
    int i = 1;

    if(p == NULL){
        printf("\nNenhum servico foi registrado ate agora.\n");
    }else{
        while(p != NULL){
            
            printf("\n        Servico %d:\n\n", i);

            printf("Nome: %s\n", p->nomeServico);
            printf("Endereco: %s\n", p->endereco);
            printf("Bairro: %s\n", p->bairro);
            printf("ID: %d\n", p->id);
            printf("Tipo de Servico: %d\n", p->tipoUnidade);

            p = p->prox;
            i++;
        }
    }
}

void exibirCidadoesRegistrados(){
    struct Cidadao *p = listaCidadoes;
    int i = 1;

    if(p == NULL){
        printf("\nNenhuma pessoa foi registrada até agora.\n");
    }else{
        while(p != NULL){
            
            printf("\n        Pessoa %d:\n\n", i);

            printf("Nome: %s\n", p->nomePessoa);
            printf("Endereco: %s\n", p->endereco);
            printf("Bairro: %s\n", p->bairro);
            printf("CPF: %s\n", p->CPF);
            printf("Email: %s\n", p->email);

            p = p->prox;
            i++;
        }
    }
}

void registrarOcorrencia(int idDaOcorrencia, char *cpfCidadaoSolicitante, int prioridade, int tipoDaOcorrencia, int idDoBairroAlvo){
    struct Ocorrencia *novo = malloc(sizeof(struct Ocorrencia));
    

    strcpy(novo->cpfCidadao, cpfCidadaoSolicitante);
    novo->id = idDaOcorrencia;
    novo->gravidade = prioridade;
    novo->tipo = tipoDaOcorrencia;
    novo->IdDoBairro = idDoBairroAlvo;
    novo->prox = NULL;

    int j = 0;

    switch (tipoDaOcorrencia)
    {
    case 1:
        tempo(); /* Aumentar o tempo. */
        tempo(); /* Aumentar o tempo. */
        tempo(); /* Aumentar o tempo. */
        break;
    
    case 2:
        j = 0;
        while(j < 7){
            tempo(); /* Aumentar tempo 7 vezes. */
            j++;
        }
        break;
    
    case 3:
        j = 0;
        while(j < 9){
            tempo(); /* Aumentar tempo 9 vezes. */
            j++;
        }
        break;
    
    default:
        break;
    }

    if(filaOcorrencias == NULL || novo->gravidade > filaOcorrencias->gravidade){
        novo->prox = filaOcorrencias; /* Mesmo que seja o primeiro caso, só irá apontar para NULL. */
        filaOcorrencias = novo;
    }else{
        struct Ocorrencia *p = filaOcorrencias;
        struct Ocorrencia *ant = NULL;
        
        while(p != NULL && p->gravidade >= novo->gravidade){ /* Percorrendo até chegar ao fim ou achar alguma ocorrência com prioridade menor. */
            ant = p;
            p = p->prox;
        }

        if(p == NULL){ /* Caso tenha chegado ao final e não tenha encontrado nenhuma prioridade menor. */
            ant->prox = novo;
        }else{ /* Caso encontrou uma prioridade menor antes de chegar ao final. */
            ant->prox = novo;
            novo->prox = p;
        }

    }
}

void processarOcorrencia(){ 
    if(filaOcorrencias == NULL){
        printf("\n\nFila de ocorrencias esta vazia.\n");
        return;
    }
    

    struct Ocorrencia *ocorrenciaAtual = filaOcorrencias;
    filaOcorrencias = filaOcorrencias->prox;
    int j;

    switch (ocorrenciaAtual->tipo) /* Tempos diferentes de processamento para cada  */
    {
    case 1:
        tempo(); /* Aumentar o tempo. */
        tempo(); /* Aumentar o tempo. */
        tempo(); /* Aumentar o tempo. */
        tempo(); /* Aumentar o tempo. */
        break;
    
    case 2:
        tempo();
        tempo();
        break;
    
    case 3:
        j = 0;
        while(j < 5){
            tempo(); /* Aumentar tempo 5 vezes. */
            j++;
        }
        break;
    
    default:
        break;
    }

     printf("Processando ocorrencia ID %d do cidadao %s (gravidade %d, tipo %d, bairro ID %d)\n",
        ocorrenciaAtual->id,
        ocorrenciaAtual->cpfCidadao,
        ocorrenciaAtual->gravidade,
        ocorrenciaAtual->tipo,
        ocorrenciaAtual->IdDoBairro);

    free(ocorrenciaAtual);
}

void exibirOcorrencias(){
    struct Ocorrencia *ocorrenciaAtual = filaOcorrencias;

    while(ocorrenciaAtual != NULL){
        printf("Ocorrencia ID %d do cidadao %s (gravidade %d, tipo %d, bairro ID %d)\n",
        ocorrenciaAtual->id,
        ocorrenciaAtual->cpfCidadao,
        ocorrenciaAtual->gravidade,
        ocorrenciaAtual->tipo,
        ocorrenciaAtual->IdDoBairro);

        ocorrenciaAtual = ocorrenciaAtual->prox;
    }
}

int tempoAtual = 0;

void tempo() {
    tempoAtual++;
}

void limparTudo(){
    struct Ocorrencia *oco = filaOcorrencias;
    struct Ocorrencia *ant = NULL;

    while(oco != NULL){
        ant = oco;
        oco = oco->prox;
        free(ant);
    }

    struct UnidadeServico *uni = listaDeServicos;
    struct UnidadeServico *antUni = NULL;

    while(uni != NULL){
        antUni = uni;
        uni = uni->prox;
        free(antUni);
    }

    struct Cidadao *cid = listaCidadoes;
    struct Cidadao *antC = NULL;

    while(cid != NULL){
        antC = cid;
        cid = cid->prox;
        free(antC);
    }

    int indice;

    for(indice = 0; indice < 50; indice++){
        struct Bairro *bai = tabelaHashing[indice];
        struct Bairro *antBai = NULL;

        while(bai != NULL){
            antBai = bai;
            bai = bai->prox;
            free(antBai);
        }
    }
}

int carregarArquivo(char *nomeArquivo, char dados[][50], int maxLinhas) {
    FILE *f = fopen(nomeArquivo, "r");

    if (f == NULL) {
        printf("Arquivo nao abriu corretamente.\n");
        return -1;
    }

    int i = 0;
    while (i < maxLinhas && fgets(dados[i], 50, f) != NULL) {
        int len = strlen(dados[i]);
        if (len > 0 && dados[i][len - 1] == '\n') {
            dados[i][len - 1] = '\0';
        }
        i++;
    }

    fclose(f);
    return i; /* Retorna a quantidade de linhas lido. */
}

void carregarDados(){ /* Faz a leitura dos .txt de cada tipo, armazena e diz o total. */
    totalNome = carregarArquivo("nomes.txt", nomes, MAX_DADOS);
    totalCPF = carregarArquivo("cpfs.txt", cpfs, MAX_DADOS);
    totalEmail = carregarArquivo("emails.txt", emails, MAX_DADOS);
    totalBairro = carregarArquivo("bairros.txt", bairros, MAX_DADOS);
    nomeServicoss = carregarArquivo("servicosNome.txt", nomeServicos, MAX_DADOS);
    enderecoss = carregarArquivo("enderecos.txt", enderecos, MAX_DADOS);
}

void exibirTudo(){
    printf("\nExibindo todos bairros registrados: \n");
    exibirBairrosRegistrados();
    printf("\nExibindo todos cidadoes registrados: \n");
    exibirCidadoesRegistrados();
    printf("\nExibindo todas ocorrencias registradas: \n");
    exibirOcorrencias();
    printf("\nExibindo todos servicos registrados: \n");
    exibirServicosRegistrados();
    printf("\n\n");
}

    
    void simulacao(){ /* Vamos criar determinadas situações conforme o valor cair em coisas diferentes. */
        srand(time(NULL));
        carregarDados();
        int contadores[6];

        int idsBairros = 1;
        int idsServicos = 1;
        int idsOcorrencias = 1;

        for(int i = 0; i < 6; i++){ /* Zerando os contadores. */
            contadores[i] = 0;
        }

        

        /* Conteudos padrões independente da situação: */

        cadastrarBairro(123, "Jardim das Rosas"); 
        cadastrarCidadao("432131", "Nathan Alves", "nathansilveira2104@gmail.com", "Felipe Carnevale", "Jardim das Rosas");
        cadastrarServico(0, 2, "Unidades de Bombeiro Carnevale", "Jardim das Rosas, 537", "Jardim das Rosas");
        
        int cont = 0;

        while (cont < 10) {
        int prioridade = rand() % 6;
        int tipoOcorrencia = (rand() % 3) + 1;
        int numeroAle = rand() % 100;

        if (numeroAle < 10){ /* 10 possibilidades diferentes. */
            printf("\nTempo: %d. Cadastro completo. \n", tempoAtual);
            char *bairro = bairros[contadores[3]++];
            cadastrarBairro(idsBairros++, bairro);

            char *cpf = cpfs[contadores[1]++];
            char *nome = nomes[contadores[0]++];
            char *email = emails[contadores[2]++];
            char *endereco = enderecos[contadores[5]++];
            cadastrarCidadao(cpf, nome, email, endereco, bairro);

            char *nomeServico = nomeServicos[contadores[4]++];
            endereco = enderecos[contadores[5]++];
            cadastrarServico(idsServicos++, tipoOcorrencia, nomeServico, endereco, bairro);

        }
        else if (numeroAle < 20) {
            printf("\nTempo: %d. Cadastro de cidadao. \n", tempoAtual);
            char *cpf = cpfs[contadores[1]++];
            char *nome = nomes[contadores[0]++];
            char *email = emails[contadores[2]++];
            char *endereco = enderecos[contadores[5]++];
            char *bairro = bairros[contadores[3]++];
            cadastrarCidadao(cpf, nome, email, endereco, bairro);
        }
        else if (numeroAle < 30) {
            printf("\nTempo: %d. Cadastro completo, com servico fixo. \n", tempoAtual);
            char *bairro = bairros[contadores[3]++];
            cadastrarBairro(idsBairros++, bairro);

            char *cpf = cpfs[contadores[1]++];
            char *nome = nomes[contadores[0]++];
            char *email = emails[contadores[2]++];
            char *endereco = enderecos[contadores[5]++];
            cadastrarCidadao(cpf, nome, email, endereco, bairro);

            
            char *nomeServico = nomeServicos[contadores[4]++];
            cadastrarServico(idsServicos++, 2, nomeServico, endereco, bairro);

        }
        else if (numeroAle < 40) {
            printf("\nTempo: %d. Processando ocorrencia e cadastrando cidadao. \n", tempoAtual);
            processarOcorrencia();
            
            char *cpf = cpfs[contadores[1]++];
            char *nome = nomes[contadores[0]++];
            char *email = emails[contadores[2]++];
            char *endereco = enderecos[contadores[5]++];
            char *bairro = bairros[contadores[3]++];
            cadastrarCidadao(cpf, nome, email, endereco, bairro);
        }
        else if (numeroAle < 50) {
            printf("\nTempo: %d. Processando ocorrencia e registrando uma nova. \n", tempoAtual);
            processarOcorrencia();
            
            char *cpf = cpfs[contadores[1]++];
            int idBairro = idsBairros;
            registrarOcorrencia(idsOcorrencias++, cpf, prioridade, tipoOcorrencia, idBairro);
        }
        else if (numeroAle < 60) {
            printf("\nTempo: %d. Registrando ocorrencia medica. \n", tempoAtual);
            char *cpf = cpfs[contadores[1]++];
            int idBairro = idsBairros;
            registrarOcorrencia(idsOcorrencias++, cpf, prioridade, 1, idBairro);
        }
        else if (numeroAle < 70) {
            printf("\nTempo: %d. Registrando ocorrencia policial. \n", tempoAtual);
            char *cpf = cpfs[contadores[1]++];
            int idBairro = idsBairros;
            registrarOcorrencia(idsOcorrencias++, cpf, prioridade, 3, idBairro);
        }
        else if (numeroAle < 80) {
            printf("\nTempo: %d. Processando ocorrencia e cadastro completo. \n", tempoAtual);
            processarOcorrencia();
            
            char *bairro = bairros[contadores[3]++];
            cadastrarBairro(idsBairros++, bairro);

            char *cpf = cpfs[contadores[1]++];
            char *nome = nomes[contadores[0]++];
            char *email = emails[contadores[2]++];
            char *endereco = enderecos[contadores[5]++];
            cadastrarCidadao(cpf, nome, email, endereco, bairro);

            char *nomeServico = nomeServicos[contadores[4]++];
            endereco = enderecos[contadores[5]++];
            cadastrarServico(idsServicos++, tipoOcorrencia, nomeServico, endereco, bairro);


        }
        else if (numeroAle < 90) {
            printf("\nTempo: %d. Processando ocorrencia e cadastrando cidadao. \n", tempoAtual);
            processarOcorrencia();
            
            char *cpf = cpfs[contadores[1]++];
            char *nome = nomes[contadores[0]++];
            char *email = emails[contadores[2]++];
            char *endereco = enderecos[contadores[5]++];
            char *bairro = bairros[contadores[3]++];
            cadastrarCidadao(cpf, nome, email, endereco, bairro);
        }
        else {
            printf("\nTempo: %d. Cadastrando equipe medica e registrando ocorrencia. \n", tempoAtual);
            char *cpf = cpfs[contadores[1]++];
            int idBairro = idsBairros;
            registrarOcorrencia(idsOcorrencias++, cpf, prioridade, 1, idBairro);
        }

        cont++;
    }
    printf("\n\n\n======================================================\n");
    printf("Exibindo os resultados da simulacao %d: \n", simulacoes);
    printf("======================================================\n\n\n");
    exibirTudo();
    simulacoes++;
}


/* cadastrarServico(int idDesejado, int tipo, char *nome, char *endereco, char *bairro){ */
/* registrarOcorrencia(int idDaOcorrencia, char *cpfCidadaoSolicitante, int prioridade, int tipoDaOcorrencia, int idDoBairroAlvo){ */