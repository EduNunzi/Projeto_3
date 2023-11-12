#include "funcoes.h"
#include <stdio.h>
#include <string.h>

#define MAX_TAREFAS 100

//Primeiro desenvolvemos a função para cadastrar as tarefas, seguindo a ordem do menu jogando as informações de Prioridade; Descrição; e Categoria dentro do array STarefas
int Cadastrar_Tarefas(struct STarefas tarefas[], int *numero_de_tarefas) {
    // Limitamos a quantidade para o maximo de 100 tarefas
    if (*numero_de_tarefas >= 100) {
        printf("Voce atingiu o limite de 100 Tarefas, nao é possivel adicionar mais tarefas.\n");
        return 0;
    }
    struct STarefas criar_tarefa;
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
int Listar_Tarefas(struct STarefas tarefas[], int numero_de_tarefas) {
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
int Deletar_Tarefa(struct STarefas tarefas[], int *numero_de_tarefas, char cate[], int priori) {
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
int Salvar_Tarefas(struct STarefas tarefas[], int numero_de_tarefas) {
    FILE *arquivo = fopen("Projeto_Tarefas.bin", "wb");
    if (arquivo == NULL) {
        return 1;
    }
    fwrite(tarefas, sizeof(struct STarefas), numero_de_tarefas, arquivo);
    fclose(arquivo);
    return 0;
}

//Desenvolvida a função para leitura do arquivo "Projeto_Tarefas.bin"
int Carregar_Tarefas(struct STarefas tarefas[]) {
    FILE *arquivo = fopen("Projeto_Tarefas.bin", "rb");
    if (arquivo == NULL) {
        printf("Arquivo Inexistente.\n");
        return 0;
    }
    int numero_de_tarefas = 0;
    while (fread(&tarefas[numero_de_tarefas], sizeof(struct STarefas), 1, arquivo) == 1) {
        numero_de_tarefas++;
    }
    fclose(arquivo);
    return numero_de_tarefas;
}

void Alterar_Tarefa(struct STarefas tarefas[], int numero_de_tarefas) {
    int priori;
    printf("Digite a prioridade da tarefa a ser modificada: ");
    scanf("%d", &priori);

    char cate[100];
    printf("Digite a categoria da tarefa: ");
    getchar();
    fgets(cate, sizeof(cate), stdin);

    char estado[20];
    printf("Digite o estado da tarefa, completo/em para 'em andamento'/nao para 'nao iniciada': ");
    fgets(estado, sizeof(estado), stdin);

    int Tarefa_Encontrada=0;

    int escolha;
    printf("1. Prioridade \n2.Descricao \n3. Categoria \n4. Estado \n  Digite o campo que vc deseja alterar: ");
    scanf("%d",&escolha);

    for (int i = 0; i < numero_de_tarefas; i++) {
        if (tarefas[i].prioridade == priori && strcmp(tarefas[i].categoria, cate) == 0 && strcmp(tarefas[i].estado, estado) == 0 && escolha==1) {
            Tarefa_Encontrada = 1;

            printf("Nova prioridade da tarefa (0 a 10): ");
            scanf("%d", &tarefas[i].prioridade);

            Salvar_Tarefas(tarefas, numero_de_tarefas);
            printf("Tarefa modificada com sucesso!\n");
            break;

        }

    }
    for (int i = 0; i < numero_de_tarefas; i++) {
        if (tarefas[i].prioridade == priori && strcmp(tarefas[i].categoria, cate) == 0 && strcmp(tarefas[i].estado, estado) == 0 && escolha==2) {
            Tarefa_Encontrada = 1;

            printf("Nova descricao da tarefa (ate 300 letras): ");
            getchar();
            fgets(tarefas[i].descricao, sizeof(tarefas[i].descricao), stdin);

            Salvar_Tarefas(tarefas, numero_de_tarefas);
            printf("Tarefa modificada com sucesso!\n");
            break;

        }

    }

    for (int i = 0; i < numero_de_tarefas; i++) {
        if (tarefas[i].prioridade == priori && strcmp(tarefas[i].categoria, cate) == 0 && strcmp(tarefas[i].estado, estado) == 0 && escolha==3) {
            Tarefa_Encontrada = 1;

            printf("Nova categoria da tarefa (ate 100 letras): ");
            getchar();
            fgets(tarefas[i].categoria, sizeof(tarefas[i].categoria), stdin);

            Salvar_Tarefas(tarefas, numero_de_tarefas);
            printf("Tarefa modificada com sucesso!\n");
            break;

        }

        for (int i = 0; i < numero_de_tarefas; i++) {
            if (tarefas[i].prioridade == priori && strcmp(tarefas[i].categoria, cate) == 0 && strcmp(tarefas[i].estado, estado) == 0 && escolha==4) {
                Tarefa_Encontrada = 1;

                printf("Novo estado da tarefa completo/em para 'em andamento'/nao para 'nao iniciada': ");
                getchar();
                fgets(tarefas[i].estado, sizeof(tarefas[i].estado), stdin);

                Salvar_Tarefas(tarefas, numero_de_tarefas);
                printf("Tarefa modificada com sucesso!\n");
                break;

            }

        }

    }

    if (!Tarefa_Encontrada) {
        printf("Tarefa nao encontrada.\n");
    }
}

void Filtrar_Por_Prioridade(struct STarefas tarefas[], int numero_de_tarefas){
    int Prioridade_da_Tarefa;
    printf("Digite a prioridade que voce deseja filtrar : ");
    scanf("%d", &Prioridade_da_Tarefa);

    int Tarefa_Encontrada=0;

    for(int i= 0; i<numero_de_tarefas; i++ ){
        if( tarefas[i].prioridade == Prioridade_da_Tarefa){
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Descricao : %s", tarefas[i].descricao);
            printf("Categoria : %s", tarefas[i].categoria);
            if (strcmp(tarefas[i].estado, "nao") == 0) {
                printf("Estado: nao iniciada\n");
            }
            else if (strcmp(tarefas[i].estado, "em") == 0) {
                printf("Estado: em antamento\n");
            }
            else if (strcmp(tarefas[i].estado, "completo") == 0){
                printf("Estado: completo\n");
            }
            Tarefa_Encontrada= 1 ;
        }
    }
    if(!Tarefa_Encontrada){
        printf("Nao ha tarefas com a prioridade %d.", Prioridade_da_Tarefa);
    }
}

void Filtrar_Por_Estado(struct STarefas tarefas[], int numero_de_tarefas){
    char estado[20];
    printf("Digite o estado da tarefa: ");
    getchar();
    fgets(estado, sizeof(estado), stdin);

    int Tarefa_Encontrada=0;

    for(int i= 0; i<numero_de_tarefas; i++ ){
        if (strcmp(tarefas[i].estado, estado) == 0) {
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Descricao : %s", tarefas[i].descricao);
            printf("Categoria : %s", tarefas[i].categoria);
            if (strcmp(tarefas[i].estado, "nao") == 0) {
                printf("Estado: nao iniciada\n");
            }
            else if (strcmp(tarefas[i].estado, "em") == 0) {
                printf("Estado: em antamento\n");
            }
            else if (strcmp(tarefas[i].estado, "completo") == 0){
                printf("Estado: completo\n");
            }
            Tarefa_Encontrada= 1 ;
        }
    }
    if(!Tarefa_Encontrada){
        printf("Nao ha tarefas com o estado %s.", estado);
    }
}

void Filtrar_Por_Categoria(struct STarefas tarefas[], int numero_de_tarefas) {
    char Categoria_da_Tarefa[100];
    printf("Digite a categoria da tarefa: ");
    getchar();
    fgets(Categoria_da_Tarefa, sizeof(Categoria_da_Tarefa), stdin);

    int Tarefa_Encontrada = 0;
    int Prioridade_da_Tarefa[MAX_TAREFAS];
    int Prioridades = 0;

    for (int i = 0; i < numero_de_tarefas; i++) {
        if (strcmp(tarefas[i].categoria, Categoria_da_Tarefa) == 0) {
            Prioridade_da_Tarefa[Prioridades] = tarefas[i].prioridade;
            Prioridades++;
        }
    }


    for (int i = 0; i < Prioridades - 1; i++) {
        for (int j = 0; j < Prioridades - i - 1; j++) {
            if (Prioridade_da_Tarefa[j] < Prioridade_da_Tarefa[j + 1]) {
                int temp = Prioridade_da_Tarefa[j];
                Prioridade_da_Tarefa[j] = Prioridade_da_Tarefa[j + 1];
                Prioridade_da_Tarefa[j + 1] = temp;
            }
        }
    }

    for (int k = 0; k < Prioridades; k++) {
        for (int i = 0; i < numero_de_tarefas; i++) {
            if (tarefas[i].prioridade == Prioridade_da_Tarefa[k] && strcmp(tarefas[i].categoria, Categoria_da_Tarefa) == 0) {
                printf("Prioridade: %d\n", tarefas[i].prioridade);
                printf("Descricao: %s", tarefas[i].descricao);
                printf("Categoria: %s", tarefas[i].categoria);
                if (strcmp(tarefas[i].estado, "nao") == 0) {
                    printf("Estado: nao iniciada\n");
                }
                else if (strcmp(tarefas[i].estado, "em") == 0) {
                    printf("Estado: em antamento\n");
                }
                else if (strcmp(tarefas[i].estado, "completo") == 0){
                    printf("Estado: completo\n");
                }
                Tarefa_Encontrada = 1;
            }
        }
    }

    if (!Tarefa_Encontrada) {
        printf("Nao ha tarefas com as categorias %s.\n", Categoria_da_Tarefa);
    }
}