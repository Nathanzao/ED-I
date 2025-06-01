#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "EstruturasCodigos.c"
/*
Teste de verificação.
*/

void menu() {
    printf("\nMenu\n\n");
    printf("1- Registrar o bairro.\n");
    printf("2- Registrar pessoa.\n");
    printf("3- Registrar servico.\n");
    printf("4- Registrar ocorrencia.\n");
    printf("5- Remover ocorrencia.\n");
    printf("6- Ver bairros.\n");
    printf("7- Ver pessoas.\n");
    printf("8- Ver servicos.\n");
    printf("9- Ver fila de ocorrencias.\n");
    printf("0- Sair.\n");
    printf("Tempo atual: %d.\n", tempoAtual);

    printf("\nDigite a opcao desejada: ");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    inicializaTabela();
    int opcao;

    do {
        menu();
        scanf("%d", &opcao);
        getchar(); // Limpar buffer

        switch (opcao) {
            case 1: {
                int id;
                char nome[30];

                printf("Digite o ID do bairro: ");
                scanf("%d", &id);
                getchar();

                printf("Digite o nome do bairro: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                cadastrarBairro(id, nome);
                break;
            }

            case 2: {
                char CPF[10], nome[30], email[30], endereco[30], bairro[30];

                printf("Digite o CPF: ");
                fgets(CPF, sizeof(CPF), stdin);
                CPF[strcspn(CPF, "\n")] = '\0';

                printf("Digite o nome: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("Digite o email: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = '\0';

                printf("Digite o endereco: ");
                fgets(endereco, sizeof(endereco), stdin);
                endereco[strcspn(endereco, "\n")] = '\0';

                printf("Digite o bairro: ");
                fgets(bairro, sizeof(bairro), stdin);
                bairro[strcspn(bairro, "\n")] = '\0';

                cadastrarCidadao(CPF, nome, email, endereco, bairro);
                break;
            }

            case 3: {
                int id, tipo;
                char nome[50], endereco[50], bairro[30];

                printf("Digite o ID do servico: ");
                scanf("%d", &id);
                getchar();

                printf("Digite o tipo de servico (1 = ambulancia, 2 = bombeiro, 3 = policia): ");
                scanf("%d", &tipo);
                getchar();

                printf("Digite o nome da unidade: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("Digite o endereco da unidade: ");
                fgets(endereco, sizeof(endereco), stdin);
                endereco[strcspn(endereco, "\n")] = '\0';

                printf("Digite bairro da unidade: ");
                fgets(bairro, sizeof(bairro), stdin);
                bairro[strcspn(bairro, "\n")] = '\0';

                cadastrarServico(id, tipo, nome, endereco, bairro);
                break;
            }

            case 4: {
                int idOcorrencia, prioridade, tipo, bairroId;
                char cpf[15];

                printf("Digite o ID da ocorrencia: ");
                scanf("%d", &idOcorrencia);
                getchar();

                printf("Digite o CPF do cidadao solicitante: ");
                fgets(cpf, sizeof(cpf), stdin);
                cpf[strcspn(cpf, "\n")] = '\0';

                printf("Digite o nivel de gravidade (0 a 5): ");
                scanf("%d", &prioridade);
                getchar();

                printf("Digite o tipo da ocorrencia (1 = ambulancia, 2 = bombeiro, 3 = policia): ");
                scanf("%d", &tipo);
                getchar();

                printf("Digite o ID do bairro alvo: ");
                scanf("%d", &bairroId);
                getchar();

                registrarOcorrencia(idOcorrencia, cpf, prioridade, tipo, bairroId);
                break;
            }

            case 5: {
                processarOcorrencia(); // Remove a ocorrência de maior prioridade
                break;
            }

            case 6: {
                exibirBairrosRegistrados();
                break;
            }

            case 7: {
                exibirCidadoesRegistrados();
                break;
            }

            case 8: {
                exibirServicosRegistrados();
                break;
            }

            case 9: {
                exibirOcorrencias();
                break;
            }

            case 0: {
                printf("\n\nPrograma encerrado.\n\n");
                limparTudo();
                break;
            }

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}