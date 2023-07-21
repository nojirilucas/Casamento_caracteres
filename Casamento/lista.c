#include "lista.h"
#include "estrategia1.h"
#include "estrategia2.h"
#include "estrategia3.h"

// Função para contar o número de nós na lista circular encadeada
int Conta_nos(No* cabeca) {
    if (cabeca == NULL)
        return 0;
    int count = 0; // Inicializa contagem em 0
    No* atual = cabeca;
    do { // Percorre cada nó da lista até que o próximo nó seja igual ao nó de cabeça
        count++;
        atual = atual->prox;
    } while (atual != cabeca);
    return count;
}

// Função para criar um novo nó com as strings fornecidas
No* Cria_no(char string1[], char string2[]) {
    No* novo_no = (No*)malloc(sizeof(No)); // Cria um novo nó para a lista circular encadeada
    // Copia(string1 e string2) para string1 e string2 do nó
    strcpy(novo_no->string1, string1);
    strcpy(novo_no->string2, string2);
    novo_no->prox = NULL;
    return novo_no;
}

// Função para inserir um novo nó no final da lista circular encadeada
void Inserir_no(No** cabeca, char string1[], char string2[]) {
    No* novo_no = Cria_no(string1, string2);
    if (*cabeca == NULL) { // Verifica se a lista está vazia 
        *cabeca = novo_no; // Ponteiro para a cabeça é atualizado para apontar para o novo_no e aponta para cabeça da lista
        novo_no->prox = *cabeca;
    } else { // Percorre a lista até o último nó 
        No* temp = *cabeca;
        while (temp->prox != *cabeca) {
            temp = temp->prox;
        }
        temp->prox = novo_no; // prox desse último nó aponta para o novo nó
        novo_no->prox = *cabeca; // Ponteiro para a cabeça é atualizado para apontar para o novo_no e aponta para cabeça da lista
    }
}

// Função para liberar a memória alocada para a lista circular encadeada
void Libera_lista(No** cabeca) {
    if (*cabeca == NULL) // Verifica se a lista está vazia
        return;
    No* atual = *cabeca;
    No* prox;
    while (atual->prox != *cabeca) { // Percorre a lista a partir do primeiro nó até o último nó antes da cabeça
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
    free(atual);
    *cabeca = NULL;
}

// Função para ler a entrada de um arquivo e criar uma lista circular encadeada
int Leitura_input(const char* input, No** cabeca) {
    FILE* entrada;
    entrada = fopen(input, "r"); // Faz abertura do arquivo para apenas leitura
    if (entrada == NULL) {
        return 0;
    }
    int teste;
    fscanf(entrada, "%d", &teste);
    char string1[100], string2[100];
    for (int i = 0; i < teste; i++) {
        fscanf(entrada, "%s %s", string1, string2);
        Inserir_no(cabeca, string1, string2);
    }
    fclose(entrada);
    return 1;
}

// Função para executar uma estratégia com base na entrada e no número da estratégia fornecidos
void executarEstrategia(const char *entrada, int strategy) {
    No *cabeca = NULL;
    if (!Leitura_input(entrada, &cabeca)) {
        printf("Erro na leitura do arquivo.\n");
        return;
    }

    FILE *output = fopen("output.out", "w"); // Abre o arquivo de saída para escrita
    if (output == NULL){
        printf("Erro ao criar o arquivo de saída.\n");
        Libera_lista(&cabeca);
        return;
    }

    switch (strategy) {
        case 1:
            Casamento_forca_bruta(cabeca, output);
            break;
        case 2:
            Casamento_KMP(cabeca, output);
            break;
        case 3:
            Casamento_ShiftAnd(cabeca, output);
            break;
        default:
            printf("Estratégia errada! Escolha 1, 2 ou 3.\n");
            break;
    }

    fclose(output); // Fecha o arquivo de saída
    Libera_lista(&cabeca); // Libera a memória alocada para a lista
}