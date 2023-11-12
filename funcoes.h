#ifndef PROJETO_TAREFAS_FUNCOES_H

#define PROJETO_TAREFAS_FUNCOES_H

#endif //PROJETO_TAREFAS_FUNCOES_H
typedef struct {
    int prioridade;
    char descricao[300];
    char categoria[100];
}STarefas;

int Salvar_Tarefas(STarefas tarefas[], int numero_de_tarefas);

int Carregar_Tarefas(STarefas tarefas[]);

int Cadastrar_Tarefas(STarefas tarefas[], int *numero_de_tarefas);

int Listar_Tarefas(STarefas tarefas[], int numero_de_tarefas);

int Deletar_Tarefa(STarefas tarefas[], int *numero_de_tarefas, char cate[], int priori);