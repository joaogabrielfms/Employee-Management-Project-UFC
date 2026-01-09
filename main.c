#include <stdio.h>
#include <stdlib.h> 
#include "dados.h"

int main() {
    Cargo *cargos = NULL;
    int quant_cargos = 0;
    int cap_cargos = 0;

    Departamento *departamentos = NULL;
    int quant_departamentos = 0;
    int cap_departamentos = 0;

    Funcionario *funcionarios = NULL;
    int quant_funcionarios = 0;
    int cap_funcionarios = 0;
    
    carregar_dados(&cargos, &quant_cargos, &cap_cargos, &departamentos, &quant_departamentos, &cap_departamentos, &funcionarios, &quant_funcionarios, &cap_funcionarios);

    int opcao;
    do {
        printf("\n--- MENU DE GESTAO ---\n0. Sair\n1. Inserir\n2. Atualizar\n3. Excluir\n4. Buscar\n5. Relatorio por Departamento\n6. Relatorio de Salario\nDigite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                salvar_dados(cargos, quant_cargos, departamentos, quant_departamentos, funcionarios, quant_funcionarios);
                printf("Saindo do Prog. Dados salvos!\n");
                break;
            case 1: {
                int opc;
                printf("\n--- Inserir ---\n1. Funcionario\n2. Departamento\n3. Cargo\n0. Voltar\nDigite: ");
                scanf("%d", &opc);
                // ---> ALTERAÇÃO AQUI: Passamos os vetores para a função <---
                if (opc == 1) inserir_funcionario(&funcionarios, &quant_funcionarios, &cap_funcionarios, departamentos, quant_departamentos, cargos, quant_cargos);
                if (opc == 2) inserir_departamento(&departamentos, &quant_departamentos, &cap_departamentos);
                if (opc == 3) inserir_cargo(&cargos, &quant_cargos, &cap_cargos);
                break;
            }
            case 2: {
                int opc;
                printf("\n--- Atualizar ---\n1. Funcionario\n2. Departamento\n3. Cargo\n0. Voltar\nDigite: ");
                scanf("%d", &opc);
                if (opc == 1) atualizar_funcionario(funcionarios, quant_funcionarios);
                if (opc == 2) atualizar_departamento(departamentos, quant_departamentos);
                if (opc == 3) atualizar_cargo(cargos, quant_cargos);
                break;
            }
            case 3: {
                int opc;
                printf("\n--- Excluir ---\n1. Funcionario\n2. Departamento\n3. Cargo\n0. Voltar\nDigite: ");
                scanf("%d", &opc);
                if (opc == 1) excluir_funcionario(&funcionarios, &quant_funcionarios, &cap_funcionarios);
                if (opc == 2) excluir_departamento(&departamentos, &quant_departamentos, &cap_departamentos);
                if (opc == 3) excluir_cargo(&cargos, &quant_cargos, &cap_cargos);
                break;
            }
            case 4: {
                int opc;
                printf("\n--- Buscar ---\n1. Funcionario\n2. Departamento\n3. Cargo\n0. Voltar\nDigite: ");
                scanf("%d", &opc);
                if (opc == 1) buscar_funcionario(funcionarios, quant_funcionarios);
                if (opc == 2) buscar_departamento(departamentos, quant_departamentos);
                if (opc == 3) buscar_cargo(cargos, quant_cargos);
                break;
            }
            case 5:
                relatorioPorDepartamento(funcionarios, quant_funcionarios, departamentos, quant_departamentos);
                break;
            case 6:
                relatorioSalarial(funcionarios, quant_funcionarios);
                break;
        }
    } while (opcao != 0);

    free(cargos);
    free(departamentos);
    free(funcionarios);

    return 0;
}