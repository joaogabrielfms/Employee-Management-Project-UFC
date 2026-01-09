#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dados.h"

int inserir_cargo(Cargo **vetor, int *tamanho, int *capacidade) {
    if (*capacidade == 0) {
        *capacidade = 4;
        *vetor = malloc(*capacidade * sizeof(Cargo));
    }
    else if (*tamanho >= *capacidade * 0.75) {
        *capacidade *= 2;
        *vetor = realloc(*vetor, *capacidade * sizeof(Cargo));
    }

    if (*vetor == NULL) {
        perror("Erro de alocacao de memoria");
        exit(1);
    }

    Cargo novo_cargo;

    printf("Digite o ID do cargo: ");
    scanf("%d", &novo_cargo.id);

    printf("Digite o Nome do cargo: ");
    scanf("%s", novo_cargo.nome);

    (*vetor)[*tamanho] = novo_cargo;
    (*tamanho)++;

    printf("Cargo inserido com sucesso!\n");
    return 1;
}

int atualizar_cargo(Cargo *vetor, int tamanho) {
    if (tamanho == 0) {
        printf("Nenhum cargo cadastrado para atualizar.\n");
        return 0;
    }

    int id_procurado;
    printf("\n--- Atualizar Cargo ---\n");
    printf("Digite o ID do cargo que deseja atualizar: ");
    scanf("%d", &id_procurado);
    
    int indice_encontrado = -1;
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i].id == id_procurado) {
            indice_encontrado = i;
            break;
        }
    }

    if (indice_encontrado != -1) {
        printf("Cargo encontrado: %s\n", vetor[indice_encontrado].nome);
        
        printf("Digite o novo nome para o cargo: ");
        scanf("%s", vetor[indice_encontrado].nome);
        
        printf("Cargo atualizado com sucesso!\n");
        return 1;
    } else {
        printf("Cargo com ID %d nao encontrado.\n", id_procurado);
        return 0;
    }
}

int excluir_cargo(Cargo **vetor, int *tamanho, int *capacidade) {
    if (*tamanho == 0) {
        printf("Nao ha cargos para excluir.\n");
        return 0;
    }

    int id_procurado;
    printf("\nDigite o ID do cargo a ser excluido: ");
    scanf("%d", &id_procurado);

    int indice_encontrado = -1;
    for (int i = 0; i < *tamanho; i++) {
        if ((*vetor)[i].id == id_procurado) {
            indice_encontrado = i;
            break;
        }
    }

    if (indice_encontrado != -1) {
        for (int j = indice_encontrado; j < *tamanho - 1; j++) {
            (*vetor)[j] = (*vetor)[j + 1];
        }
        
        (*tamanho)--;
        printf("Cargo excluido.\n");

        if (*capacidade > 4 && *tamanho < *capacidade * 0.25) {
            int nova_capacidade = *capacidade / 2;
            Cargo *temp = realloc(*vetor, nova_capacidade * sizeof(Cargo));
            if (temp != NULL) {
                *vetor = temp;
                *capacidade = nova_capacidade;
            }
        }
        return 1;
    } else {
        printf("Cargo com ID %d nao encontrado.\n", id_procurado);
        return 0;
    }
}

    void buscar_cargo(Cargo *vetor, int tamanho) {
        if (tamanho == 0) {
            printf("\nNenhum cargo cadastrado para buscar.\n");
            return;
        }

        int opc, c, vdd = 0;
        
        printf("1. Buscar cargo por id\n");
        printf("2. Buscar cargo por nome\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opc);
        while ((c = getchar()) != '\n' && c != EOF);

        if (opc == 1) {
            int id_temp;
            printf("Digite o id do cargo que pretende procurar: ");
            scanf("%d", &id_temp);

            for (int i = 0; i < tamanho; i++) {
                if (vetor[i].id == id_temp) {
                    printf("\n--- Cargo Encontrado ---\n");
                    printf("ID: %d\n", vetor[i].id);
                    printf("Nome: %s\n", vetor[i].nome);
                    vdd = 1;
                    break;
                }
            }
            if (vdd == 0) printf("Nao foi encontrado nenhum cargo com esse id.\n");
        }
        else if (opc == 2) {
            char nome_temp[50];
            printf("Digite o nome do cargo que pretende procurar: ");
            fgets(nome_temp, 50, stdin);
            nome_temp[strcspn(nome_temp, "\n")] = '\0';

            for (int i = 0; i < tamanho; i++) {
                if (strcmp(vetor[i].nome, nome_temp) == 0) {
                    printf("\n--- Cargo Encontrado ---\n");
                    printf("ID: %d\n", vetor[i].id);
                    printf("Nome: %s\n", vetor[i].nome);
                    vdd = 1;
                    break;
                }
            }
            if (vdd == 0) printf("Nao foi encontrado nenhum cargo com esse nome.\n");
        }
    }