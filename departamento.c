#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dados.h"

int inserir_departamento(Departamento **vetor, int *tamanho, int *capacidade) {
    // Verifica e ajusta a capacidade do vetor
    if (*capacidade == 0) {
        *capacidade = 4;
        *vetor = malloc(*capacidade * sizeof(Departamento));
    }
    else if (*tamanho >= *capacidade) {
        *capacidade *= 2;
        *vetor = realloc(*vetor, *capacidade * sizeof(Departamento));
    }

    // Verifica se a alocação foi bem-sucedida
    if (*vetor == NULL) {
        perror("Erro de alocação de memória");
        exit(1);
    }

    Departamento novo_depto;
    int c; // Variável para limpeza do buffer

    printf("\n--- Inserir Novo Departamento ---\n");
    
    printf("Digite o ID: ");
    scanf("%d", &novo_depto.id);
    
    // Limpa o buffer de entrada
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Digite o Nome: ");
    fgets(novo_depto.nome, 100, stdin);
    novo_depto.nome[strcspn(novo_depto.nome, "\n")] = '\0'; // Remove a quebra de linha

    // Adiciona o novo departamento ao vetor
    (*vetor)[*tamanho] = novo_depto;
    (*tamanho)++;

    printf("Departamento inserido com sucesso!\n");
    return 1;
}

int atualizar_departamento(Departamento *vetor, int tamanho) {
    if (tamanho == 0) {
        printf("Nenhum departamento cadastrado para atualizar.\n");
        return 0;
    }

    int id_procurado;
    printf("\n--- Atualizar Departamento ---\n");
    printf("Digite o ID do departamento que deseja atualizar: ");
    scanf("%d", &id_procurado);
    
    int indice_encontrado = -1;
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i].id == id_procurado) {
            indice_encontrado = i;
            break;
        }
    }

    if (indice_encontrado != -1) {
        printf("Departamento encontrado: %s\n", vetor[indice_encontrado].nome);
        
        printf("Digite o novo nome para o departamento: ");
        scanf("%s", vetor[indice_encontrado].nome);
        
        printf("Departamento atualizado com sucesso!\n");
        return 1;
    } else {
        printf("Departamento com ID %d nao encontrado.\n", id_procurado);
        return 0;
    }
}

int excluir_departamento(Departamento **vetor, int *tamanho, int *capacidade) {
    if (*tamanho == 0) {
        printf("Nao ha departamentos para excluir.\n");
        return 0;
    }

    int id_procurado;
    printf("\nDigite o ID do departamento a ser excluido: ");
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
        printf("Departamento excluido.\n");

        if (*capacidade > 4 && *tamanho < *capacidade * 0.25) {
            int nova_capacidade = *capacidade / 2;
            Departamento *temp = realloc(*vetor, nova_capacidade * sizeof(Departamento));
            if (temp != NULL) {
                *vetor = temp;
                *capacidade = nova_capacidade;
            }
        }
        return 1;
    } else {
        printf("Departamento com ID %d nao encontrado.\n", id_procurado);
        return 0;
    }
}

void buscar_departamento(Departamento *vetor, int tamanho) {
     if (tamanho == 0) {
        printf("\nNenhum departamento cadastrado para buscar.\n");
        return;
    }

    int opc, c, vdd = 0;
    
    printf("1. Buscar departamento por id\n");
    printf("2. Buscar departamento por nome\n");
    printf("Digite sua opcao: ");
    scanf("%d", &opc);
    while ((c = getchar()) != '\n' && c != EOF);

    if (opc == 1) {
        int id_temp;
        printf("Digite o id do departamento que pretende procurar: ");
        scanf("%d", &id_temp);

        for (int i = 0; i < tamanho; i++) {
            if (vetor[i].id == id_temp) {
                printf("\n--- Departamento Encontrado ---\n");
                printf("ID: %d\n", vetor[i].id);
                printf("Nome: %s\n", vetor[i].nome);
                vdd = 1;
                break;
            }
        }
        if (vdd == 0) printf("Nao foi encontrado nenhum departamento com esse id.\n");
    }
    else if (opc == 2) {
        char nome_temp[100];
        printf("Digite o nome do departamento que pretende procurar: ");
        fgets(nome_temp, 100, stdin);
        nome_temp[strcspn(nome_temp, "\n")] = '\0';

        for (int i = 0; i < tamanho; i++) {
            if (strcmp(vetor[i].nome, nome_temp) == 0) {
                printf("\n--- Departamento Encontrado ---\n");
                printf("ID: %d\n", vetor[i].id);
                printf("Nome: %s\n", vetor[i].nome);
                vdd = 1;
                break;
            }
        }
        if (vdd == 0) printf("Nao foi encontrado nenhum departamento com esse nome.\n");
    }
}