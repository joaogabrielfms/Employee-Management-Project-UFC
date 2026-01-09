#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"

// Função para limpar o buffer de entrada (evita bugs com scanf e fgets)
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int buscarFuncionarioPorId(Funcionario *vetor, int tamanho, int id) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i].id == id) {
            return i; // Retorna o índice onde o funcionário foi encontrado
        }
    }
    return -1; // Retorna -1 se não encontrar
}
    
// ---> ALTERAÇÃO AQUI: Função agora recebe os vetores de depto e cargo <---
void inserir_funcionario(Funcionario **vetor, int *tamanho, int *capacidade, Departamento *departamentos, int quant_departamentos, Cargo *cargos, int quant_cargos) {
    
    // ---> LÓGICA DE VALIDAÇÃO 1: Verifica se existem cargos/deptos cadastrados <---
    if (quant_cargos == 0 || quant_departamentos == 0) {
        printf("\nERRO: E necessario cadastrar pelo menos um cargo E um departamento antes de adicionar um funcionario.\n");
        return; // Impede a inserção
    }

    if (*capacidade == 0) {
        *capacidade = 4; 
        *vetor = malloc(*capacidade * sizeof(Funcionario));
    }
    else if (*tamanho >= *capacidade) {
        *capacidade *= 2;
        *vetor = realloc(*vetor, *capacidade * sizeof(Funcionario));
    }

    if (*vetor == NULL) {
        perror("Erro de alocacao de memoria");
        exit(1);
    }

    Funcionario novo_funcionario;
    int cargo_valido = 0;
    int depto_valido = 0;

    printf("\n--- Inserir Novo Funcionario ---\n");
    printf("Digite o ID: ");
    scanf("%d", &novo_funcionario.id);
    limpar_buffer();

    printf("Digite o Nome: ");
    fgets(novo_funcionario.nome, 100, stdin);
    novo_funcionario.nome[strcspn(novo_funcionario.nome, "\n")] = '\0';

    printf("Digite o salario: ");
    scanf("%f", &novo_funcionario.salario);
    
    // ---> LÓGICA DE VALIDAÇÃO 2: Pede o ID do cargo até que um válido seja inserido <---
    do {
        printf("Digite o ID do cargo: ");
        scanf("%d", &novo_funcionario.id_cargo);
        
        // Procura o ID na lista de cargos
        for(int i = 0; i < quant_cargos; i++) {
            if (cargos[i].id == novo_funcionario.id_cargo) {
                cargo_valido = 1;
                break;
            }
        }
        if (!cargo_valido) {
            printf("ID de cargo invalido. Tente novamente.\n");
        }
    } while (!cargo_valido);

    // ---> LÓGICA DE VALIDAÇÃO 3: Pede o ID do depto até que um válido seja inserido <---
    do {
        printf("Digite o ID do departamento: ");
        scanf("%d", &novo_funcionario.id_departamento);

        // Procura o ID na lista de departamentos
        for(int i = 0; i < quant_departamentos; i++) {
            if (departamentos[i].id == novo_funcionario.id_departamento) {
                depto_valido = 1;
                break;
            }
        }
        if (!depto_valido) {
            printf("ID de departamento invalido. Tente novamente.\n");
        }
    } while (!depto_valido);

    (*vetor)[*tamanho] = novo_funcionario;
    (*tamanho)++;
    printf("Funcionario inserido com sucesso!\n");
}

// ... (O restante do arquivo funcionario.c continua igual)

void atualizar_funcionario(Funcionario *vetor, int tamanho) {
    if (tamanho == 0) {
        printf("Nenhum funcionário cadastrado.\n");
        return;
    }
    int id, pos;

    printf("\nDigite o ID do funcionario a atualizar: ");
    scanf("%d", &id);
    limpar_buffer();

    pos = buscarFuncionarioPorId(vetor, tamanho, id);

    if (pos != -1) {
        printf("--- Atualizando dados para: %s ---\n", vetor[pos].nome);

        printf("Novo nome: ");
        fgets(vetor[pos].nome, 100, stdin);
        vetor[pos].nome[strcspn(vetor[pos].nome, "\n")] = '\0';

        printf("Novo salario: ");
        scanf("%f", &vetor[pos].salario);

        printf("Novo ID do Cargo: ");
        scanf("%d", &vetor[pos].id_cargo);

        printf("Novo ID Departamento: ");
        scanf("%d", &vetor[pos].id_departamento);
        limpar_buffer();

        printf("Funcionario atualizado com sucesso.\n");
    } else {
        printf("Funcionario com ID %d nao encontrado.\n", id);
    }
}

void excluir_funcionario(Funcionario **vetor, int *tamanho, int *capacidade) {
    int id_pra_deletar, j; 

    if (*tamanho == 0) {
        printf("A lista de funcionarios ja esta vazia!\n");
        return; 
    }

    printf("\nDigite o ID do funcionario para demitir: ");
    scanf("%d", &id_pra_deletar);
    limpar_buffer();

    int pos = buscarFuncionarioPorId(*vetor, *tamanho, id_pra_deletar);

    if (pos != -1) {
        printf("Funcionario '%s' sera demitido.\n", (*vetor)[pos].nome);

        for (j = pos; j < *tamanho - 1; j++) {
            (*vetor)[j] = (*vetor)[j + 1];
        }

        (*tamanho)--;

        if (*tamanho > 0 && *tamanho <= *capacidade * 0.25) {
            int nova_capacidade = *capacidade / 2;
            if (nova_capacidade < 4) { nova_capacidade = 4; }
            *vetor = realloc(*vetor, nova_capacidade * sizeof(Funcionario));
            *capacidade = nova_capacidade;
            printf("(Info: Espaco de memoria otimizado para %d posicoes.)\n", *capacidade);
        }
        
        printf("Funcionario excluido com sucesso.\n");
        return; 
    }

    printf("Funcionario com ID %d nao encontrado.\n", id_pra_deletar);
}

void buscar_funcionario(Funcionario *vetor, int tamanho) {
    if (tamanho == 0) {
        printf("Nao ha funcionarios cadastrados para buscar.\n");
        return;
    }

    int id_procurado;
    printf("\n--- Buscar Funcionario por ID ---\n");
    printf("Digite o ID do funcionario que deseja procurar: ");
    scanf("%d", &id_procurado);
    limpar_buffer();
    
    int pos = buscarFuncionarioPorId(vetor, tamanho, id_procurado);

    if (pos != -1) {
        printf("\n--- Funcionario Encontrado ---\n");
        printf("ID: %d\n", vetor[pos].id);
        printf("Nome: %s\n", vetor[pos].nome);
        printf("Salario: R$%.2f\n", vetor[pos].salario);
        printf("ID Cargo: %d\n", vetor[pos].id_cargo);
        printf("ID Departamento: %d\n", vetor[pos].id_departamento);
        return; 
    }

    printf("Funcionario com ID %d nao foi encontrado.\n", id_procurado);
}