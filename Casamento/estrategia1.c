#include "estrategia1.h"

// Essa função  implementa a estratégia de busca de casamentos entre duas strings 
int Forca_bruta(const char *string1, const char *string2){
    // Obtem tamanho das strings
    int len1 = strlen(string1);
    int len2 = strlen(string2);

    // Verifica se há casamento na ordem direta
    for (int i = 0; i < len2; i++){ // Loop externo que percorre a string2
        int j = 0;
        int k = i;
        while (j < len1 && string2[k] == string1[j]) // Loop interno que percorre a string1
        {
            j++;
            k = (k + 1) % len2;
        }
        if (j == len1)
        {
            return i;
        }
    }

    // Verifica se há casamento na ordem reversa
    for (int i = 0; i < len2; i++){
        int j = 0;
        int k = (i + len2 - 1) % len2; // Começa a partir do último caractere de string2
        while (j < len1 && string2[k] == string1[j]){
            j++;
            k = (k - 1 + len2) % len2; // Percorre a string2 em ordem reversa
        }
        if (j == len1){
            return (i == 0) ? (len2 - 1) : (i + 1) % len2; // Retorna a última posição ou a posição invertida
        }
    }

    return -1; // Nenhum casamento encontrado
}

// Essa função aplica a estratégia de força bruta a cada par de strings da lista circular encadeada
void Casamento_forca_bruta(No *cabeca, FILE *output){
    No *atual = cabeca;
    do{ // Percorre todos os nós da lista circular encadeada
        int posicao_casamento = Forca_bruta(atual->string1, atual->string2);
        if (posicao_casamento != -1){ // Existe casamento
            fprintf(output, "S %d\n", posicao_casamento + 1);
        }else{ // Não possui casamento
            fprintf(output, "N\n");
        }
        atual = atual->prox;
    } while (atual != cabeca);
}

