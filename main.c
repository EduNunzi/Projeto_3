#include <stdio.h>
#include "funcoes.h"

//Eduardo G. Nunziata RA: 22.123.002-2

int main() {
    struct STarefas tarefas[MAX_TAREFAS];
    int numero_de_tarefas = Carregar_Tarefas(tarefas);

    int escolha;
    while (1) {
        printf("1. Cadastrar Tarefa\n");
        printf("2. Listar Tarefas\n");
        printf("3. Deletar Tarefa\n");
        printf("4. Alterar Tarefa\n");
        printf("5. Filtrar por Prioridade\n");
        printf("6. Filtrar por Estado\n");
        printf("7. Filtrar por Categoria\n");
        printf("8. Filtrar por Prioridade e Categoria\n");
        printf("9. Exportar por Prioridade\n");
        printf("10. Exportar por Categoria\n");
        printf("11. Exportar por Prioridade e Categoria\n");
        printf("12. Sair\n");
        printf("Escolha uma operacao do menu: ");
        printf("\n");
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
                Alterar_Tarefa(tarefas, numero_de_tarefas);
                break;
            case 5:
                Filtrar_Por_Prioridade(tarefas, numero_de_tarefas);
                break;
            case 6:
                Filtrar_Por_Estado(tarefas, numero_de_tarefas);
                break;
            case 7:
                Filtrar_Por_Categoria(tarefas, numero_de_tarefas);
                break;
            case 8:
                Filtrar_Por_Prioridade_E_Categoria(tarefas, numero_de_tarefas);
                break;
            case 9:
                Exportar_Por_Prioridade(tarefas, numero_de_tarefas);
                break;
            case 10:
                Exportar_Por_Categoria(tarefas, numero_de_tarefas);
                break;
            case 11:
                Exportar_Por_Prioridade_E_Categoria(tarefas, numero_de_tarefas);
                break;
            case 12:
                printf("Sessao encerrada.\n");
                break;
            default:
                printf("Essa opçao nao existe.\n");
                break;
        }
    }

    return 0;
}