#include "funcoes.h"
#include <stdio.h>
#include <string.h>

//Primeiro desenvolvemos a função para cadastrar as tarefas, seguindo a ordem do menu jogando as informações de Prioridade; Descrição; e Categoria dentro do array STarefas
int Cadastrar_Tarefas(STarefas tarefas[], int *numero_de_tarefas) {
    // Limitamos a quantidade para o maximo de 100 tarefas
    if (*numero_de_tarefas >= 100) {
        printf("Voce atingiu o limite de 100 Tarefas, nao é possivel adicionar mais tarefas.\n");
        return 0;
    }
    STarefas criar_tarefa;
    printf("Coloque a prioridade da sua tarefa entre 0 e 10: ");
    scanf("%d", &criar_tarefa.prioridade);
    printf("Coloque a descricao da sua tarefa, ate no maximo 300 caracteres: ");
    getchar();
    fgets(criar_tarefa.descricao, sizeof(criar_tarefa.descricao), stdin);
    printf("Classifique a categoria da sua tarefa, ate no maximo 100 caracteres: \n");
    fgets(criar_tarefa.categoria, sizeof(criar_tarefa.categoria), stdin);
    tarefas[*numero_de_tarefas] = criar_tarefa;
    (*numero_de_tarefas)++;
    Salvar_Tarefas(tarefas, *numero_de_tarefas);
    //Confirmação do cadastro
    printf("Sua tarefa foi cadastrada.\n");
}

//Desenvolvemos a função de listar tarefas, percorrendo o array STarefas através de um for, e mostrando todas as tarefas ja cadastradas com o printf da sequencia de Prioridade, Categoria e Descrição
int Listar_Tarefas(STarefas tarefas[], int numero_de_tarefas) {
    if (numero_de_tarefas == 0) {
        printf("Sua lista de tarefas esta vazia.\n");
        return 0;
    }
    printf("Sua lista de tarefas:\n");
    for (int i = 0; i < numero_de_tarefas; i++) {
        printf("Prioridade: %d\n", tarefas[i].prioridade);
        printf("\n");
        printf("Categoria: %s\n", tarefas[i].categoria);
        printf("Descricao: %s\n", tarefas[i].descricao);
        printf("\n");

        return numero_de_tarefas;
    }
}

//Desenvolvemos a função de deletar tarefas, percorrendo o array STarefas através de um for, e excluindo a tarefa baseado na prioridade e da categoria cedidas pelo usuário
int Deletar_Tarefa(STarefas tarefas[], int *numero_de_tarefas, char cate[], int priori) {
    int localizar_tarefa = 0;
    for (int i = 0; i < *numero_de_tarefas; i++) {
        if (tarefas[i].prioridade == priori &&
            strcmp(tarefas[i].categoria, cate) == 0) {
            localizar_tarefa = 1;
            for (int j = i; j < *numero_de_tarefas - 1; j++) {
                tarefas[j] = tarefas[j + 1];
            }
            (*numero_de_tarefas)--;
            Salvar_Tarefas(tarefas, *numero_de_tarefas);
            printf("Tarefa deletada.\n");
            printf("\n");
            break;
        }
    }
    if (!localizar_tarefa) {
        printf("Essa tarefa não foi encontrada.\n");
    }
}

//Desenvolvemos a função de salvar tarefas, puxando as informações do struct STarefas e abrindo o arquivo "Projeto_Tarefas.bin"
int Salvar_Tarefas(STarefas tarefas[], int numero_de_tarefas) {
    FILE *arquivo = fopen("Projeto_Tarefas.bin", "wb");
    if (arquivo == NULL) {
        return 1;
    }
    fwrite(tarefas, sizeof(STarefas), numero_de_tarefas, arquivo);
    fclose(arquivo);
    return 0;
}

//Desenvolvida a função para leitura do arquivo "Projeto_Tarefas.bin"
int Carregar_Tarefas(STarefas tarefas[]) {
    FILE *arquivo = fopen("Projeto_Tarefas.bin", "rb");
    if (arquivo == NULL) {
        printf("Arquivo Inexistente.\n");
        return 0;
    }
    int numero_de_tarefas = 0;
    while (fread(&tarefas[numero_de_tarefas], sizeof(STarefas), 1, arquivo) == 1) {
        numero_de_tarefas++;
    }
    fclose(arquivo);
    return numero_de_tarefas;
}