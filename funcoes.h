#ifndef PROJETO_TAREFAS_FUNCOES_H

#define PROJETO_TAREFAS_FUNCOES_H

#endif //PROJETO_TAREFAS_FUNCOES_H

#define MAX_TAREFAS 100

typedef struct STarefas{
    int prioridade;
    char descricao[300];
    char categoria[100];
    char estado[20];
};

int Salvar_Tarefas(struct STarefas tarefas[], int numero_de_tarefas);

int Carregar_Tarefas(struct STarefas tarefas[]);

int Cadastrar_Tarefas(struct STarefas tarefas[], int *numero_de_tarefas);

int Listar_Tarefas(struct STarefas tarefas[], int numero_de_tarefas);

int Deletar_Tarefa(struct STarefas tarefas[], int *numero_de_tarefas, char cate[], int priori);

void Alterar_Tarefa(struct STarefas tarefas[], int numero_de_tarefas);

void Filtrar_Por_Prioridade(struct STarefas tarefas[], int numero_de_tarefas);

void Filtrar_Por_Estado(struct STarefas tarefas[], int numero_de_tarefas);

void Filtrar_Por_Categoria(struct STarefas tarefas[], int numero_de_tarefas);

void Filtrar_Por_Prioridade_E_Categoria(struct STarefas tarefas[], int numero_de_tarefas);

void Exportar_Por_Prioridade(struct STarefas tarefas[], int numero_de_tarefas);

void Exportar_Por_Categoria(struct STarefas tarefas[], int numero_de_tarefas);

void Exportar_Por_Prioridade_E_Categoria(struct STarefas tarefas[], int numero_de_tarefas);