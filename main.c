#include <stdio.h>
#include "funcoes.h"
//Eduardo G. Nunziata RA: 22.123.002-2
//Ana Carolina Lazzuri RA: 22.123.001-4

int main() {
    STarefas tarefas[100];
    int numero_de_tarefas = Carregar_Tarefas(tarefas);

    int escolha;
    while(1){
        printf("1. Cadastrar Tarefa\n");
        printf("2. Listar Tarefas\n");
        printf("3. Deletar Tarefa\n");
        printf("4. Sair\n");
        printf("Escolha uma operacao do menu: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                Cadastrar_Tarefas(tarefas, &numero_de_tarefas);
                break;
            case 2:
                Listar_Tarefas(tarefas, numero_de_tarefas);
                break;
            case 3:
                if (numero_de_tarefas > 0) {
                    int priori;
                    char cate[100];
                    printf("Prioridade da tarefa que deseja deletar: ");
                    scanf("%d", &priori);
                    printf("Categoria da tarefa que deseja deletar: ");
                    getchar();
                    fgets(cate, sizeof(cate), stdin);
                    Deletar_Tarefa(tarefas, &numero_de_tarefas, cate, priori);
                } else {
                    printf("Lista de tarefas vazia.\n");
                }
                break;
            case 4:
                printf("Sessao encerrada.\n");
                break;
            default:
                printf("Essa opcao nao existe.\n");
                break;
        }
    }
}