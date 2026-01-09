#include <stdio.h>
#include <stdlib.h>
#include "dados.h"

// Salva todos os dados dos vetores para seus respectivos arquivos .txt
void salvar_dados(Cargo *cargos, int quant_cargos, Departamento *departamentos, int quant_departamentos, Funcionario *funcionarios, int quant_funcionarios) {
    FILE *file;

    // Salvar Cargos
    file = fopen("cargos.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < quant_cargos; i++) {
            fprintf(file, "%d;%s\n", cargos[i].id, cargos[i].nome);
        }
        fclose(file);
    }

    // Salvar Departamentos
    file = fopen("departamentos.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < quant_departamentos; i++) {
            fprintf(file, "%d;%s\n", departamentos[i].id, departamentos[i].nome);
        }
        fclose(file);
    }

    // Salvar Funcionarios
    file = fopen("funcionarios.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < quant_funcionarios; i++) {
            fprintf(file, "%d;%s;%.2f;%d;%d\n", funcionarios[i].id, funcionarios[i].nome, funcionarios[i].salario, funcionarios[i].id_cargo, funcionarios[i].id_departamento);
        }
        fclose(file);
    }
}

// Carrega todos os dados dos arquivos .txt para os vetores
// VERSÃO CORRIGIDA: Agora gerencia a memória diretamente sem chamar as funções "inserir_*"
void carregar_dados(Cargo **cargos, int *quant_cargos, int *cap_cargos, Departamento **departamentos, int *quant_departamentos, int *cap_departamentos, Funcionario **funcionarios, int *quant_funcionarios, int *cap_funcionarios) {
    FILE *file;
    
    // Carregar Cargos
    file = fopen("cargos.txt", "r");
    if (file != NULL) {
        Cargo temp;
        while (fscanf(file, "%d;%49[^\n]\n", &temp.id, temp.nome) == 2) {
            // Lógica de alocação de memória movida para cá
            if (*quant_cargos >= *cap_cargos) {
                *cap_cargos = (*cap_cargos == 0) ? 4 : *cap_cargos * 2;
                *cargos = realloc(*cargos, *cap_cargos * sizeof(Cargo));
            }
            (*cargos)[*quant_cargos] = temp;
            (*quant_cargos)++;
        }
        fclose(file);
    }

    // Carregar Departamentos
    file = fopen("departamentos.txt", "r");
    if (file != NULL) {
        Departamento temp;
        while (fscanf(file, "%d;%99[^\n]\n", &temp.id, temp.nome) == 2) {
            // Lógica de alocação de memória movida para cá
            if (*quant_departamentos >= *cap_departamentos) {
                *cap_departamentos = (*cap_departamentos == 0) ? 4 : *cap_departamentos * 2;
                *departamentos = realloc(*departamentos, *cap_departamentos * sizeof(Departamento));
            }
            (*departamentos)[*quant_departamentos] = temp;
            (*quant_departamentos)++;
        }
        fclose(file);
    }

    // Carregar Funcionarios
    file = fopen("funcionarios.txt", "r");
    if (file != NULL) {
        Funcionario temp;
        while (fscanf(file, "%d;%99[^;];%f;%d;%d\n", &temp.id, temp.nome, &temp.salario, &temp.id_cargo, &temp.id_departamento) == 5) {
            // Lógica de alocação de memória movida para cá
            if (*quant_funcionarios >= *cap_funcionarios) {
                *cap_funcionarios = (*cap_funcionarios == 0) ? 4 : *cap_funcionarios * 2;
                *funcionarios = realloc(*funcionarios, *cap_funcionarios * sizeof(Funcionario));
            }
            (*funcionarios)[*quant_funcionarios] = temp;
            (*quant_funcionarios)++;
        }
        fclose(file);
    }
}