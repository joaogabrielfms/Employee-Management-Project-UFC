#ifndef DADOS_H
#define DADOS_H

// Estruturas de Dados
typedef struct {
    int id;
    char nome[50];
} Cargo;

typedef struct {
    int id;
    char nome[100];
} Departamento;

typedef struct {
    int id;
    char nome[100];
    float salario;
    int id_cargo;
    int id_departamento;
} Funcionario;

// ----- Protótipos de Funções -----

// Função Utilitária
void limpar_buffer();

// Funções de Cargo
int inserir_cargo(Cargo **vetor, int *tamanho, int *capacidade);
int atualizar_cargo(Cargo *vetor, int tamanho);
int excluir_cargo(Cargo **vetor, int *tamanho, int *capacidade);
void buscar_cargo(Cargo *vetor, int tamanho);

// Funções de Departamento
int inserir_departamento(Departamento **vetor, int *tamanho, int *capacidade);
int atualizar_departamento(Departamento *vetor, int tamanho);
int excluir_departamento(Departamento **vetor, int *tamanho, int *capacidade);
void buscar_departamento(Departamento *vetor, int tamanho);

// Funções de Funcionário
// ---> ALTERAÇÃO AQUI: Adicionamos os parâmetros de cargos e departamentos <---
void inserir_funcionario(Funcionario **vetor, int *tamanho, int *capacidade, Departamento *departamentos, int quant_departamentos, Cargo *cargos, int quant_cargos);
void atualizar_funcionario(Funcionario *vetor, int tamanho);
void excluir_funcionario(Funcionario **vetor, int *tamanho, int *capacidade);
void buscar_funcionario(Funcionario *vetor, int tamanho);

// Funções de Relatório
void relatorioPorDepartamento(Funcionario *funcionarios, int quant_funcionarios, Departamento *departamentos, int quant_departamentos);
void relatorioSalarial(Funcionario *funcionarios, int quant_funcionarios);

// Funções de Persistência (Arquivos)
void salvar_dados(Cargo *cargos, int quant_cargos, Departamento *departamentos, int quant_departamentos, Funcionario *funcionarios, int quant_funcionarios);
void carregar_dados(Cargo **cargos, int *quant_cargos, int *cap_cargos, Departamento **departamentos, int *quant_departamentos, int *cap_departamentos, Funcionario **funcionarios, int *quant_funcionarios, int *cap_funcionarios);

#endif