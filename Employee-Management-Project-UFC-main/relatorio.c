
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dados.h"

void relatorioPorDepartamento(Funcionario *funcionarios, int quant_funcionarios, Departamento *departamentos, int quant_departamentos) {
    if (quant_departamentos == 0) {
        printf("\nNenhum departamento cadastrado para gerar relatorio.\n");
        return;
    }
    printf("\n--- Lista de Departamentos ---\n");
    for (int i = 0; i < quant_departamentos; i++) {
        printf("ID: %d | Nome: %s\n", departamentos[i].id, departamentos[i].nome);
    }
    int id_depto_busca;
    printf("\nDigite o ID do departamento para ver os funcionarios: ");
    scanf("%d", &id_depto_busca);
    printf("\n--- Funcionarios do Departamento ID %d ---\n", id_depto_busca);
    int funcionarios_encontrados = 0;
    for (int i = 0; i < quant_funcionarios; i++) {
        if (funcionarios[i].id_departamento == id_depto_busca) {
            printf("ID: %d | Nome: %s | Salario: R$%.2f\n", funcionarios[i].id, funcionarios[i].nome, funcionarios[i].salario);
            funcionarios_encontrados++;
        }
    }
    if (funcionarios_encontrados == 0) {
        printf("Nenhum funcionario encontrado neste departamento.\n");
    }
}

void relatorioSalarial(Funcionario *funcionarios, int quant_funcionarios) {
    if (quant_funcionarios == 0) {
        printf("\nNenhum funcionario cadastrado para gerar relatorio.\n");
        return;
    }
    float soma_salarios = 0.0;
    float maior_salario = 0.0;
    float menor_salario = -1.0;
    for (int i = 0; i < quant_funcionarios; i++) {
        float salario_atual = funcionarios[i].salario;
        soma_salarios += salario_atual;
        if (salario_atual > maior_salario) {
            maior_salario = salario_atual;
        }
        if (menor_salario == -1.0 || salario_atual < menor_salario) {
            menor_salario = salario_atual;
        }
    }
    float media_salarial = (float)soma_salarios / quant_funcionarios;
    printf("\n--- Relatorio de Salarios ---\n");
    printf("Total de Funcionarios: %d\n", quant_funcionarios);
    printf("Soma de todos os salarios (Folha salarial): R$%.2f\n", soma_salarios);
    printf("Media Salarial: R$%.2f\n", media_salarial);
    printf("Maior Salario: R$%.2f\n", maior_salario);
    printf("Menor Salario: R$%.2f\n", menor_salario);
}
