#include "estrategia2.h"

// Essa função implementa o algoritmo de busca de padrão KMP
int KMP_Reverso(char *padrao, char *txt){
    int len1 = strlen(padrao);
    int len2 = strlen(txt);

    for (int i = 0; i < len2; i++){
        int j = 0;
        int k = (i + len2 - 1) % len2; // Começa a partir do último caractere de string2
        while (j < len1 && txt[k] == padrao[j]){
            j++;
            k = (k - 1 + len2) % len2; // Percorre a string2 em ordem reversa
        }if (j == len1){
            return (i == 0) ? (len2 - 1) : (i + 1) % len2; // Retorna a última posição ou a posição invertida
        }
    }

    return -1; // Nenhum casamento encontrado
}

// Essa função implementa o algoritmo de busca de padrão KMP em ordem-direta e
// usa a tabela LPS (Longest Proper Prefix which is also Suffix) para otimizar a busca
int KMP_Busca(char *padrao, char *txt){
    int M = strlen(padrao);
    int N = strlen(txt);

    int *lps = (int *)malloc(sizeof(int) * M);
    Contagem_Caracteres(padrao, M, lps);

    int i = 0;
    int j = 0;

    while (i < N){
        if (padrao[j] == txt[i]){
            j++;
            i++;
        }if (j == M){
            free(lps);
            return i - j;
        }else if (i < N && padrao[j] != txt[i]){
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }

    free(lps);
    return -1;
}

// Uma função auxiliar usada pelo algoritmo KMP
void Contagem_Caracteres(char *padrao, int M, int *lps){
    int len = 0;
    lps[0] = 0;
    int i = 1;

    // preenche o array LPS de acordo com os caracteres correspondentes do padrão
    while (i < M){
        if (padrao[i] == padrao[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if (len != 0){
                len = lps[len - 1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void Casamento_KMP(No *cabeca, FILE *output) {
    No *atual = cabeca;
    int caso_teste = 1;
    do { // percorre todos os nós da lista circular encadeada
        int len2 = strlen(atual->string2);

        char *txtCircular = (char *)malloc(sizeof(char) * (2 * len2 + 1)); // txtCircular concatena duas cópias da string2
        strncpy(txtCircular, atual->string2, len2);
        strncpy(txtCircular + len2, atual->string2, len2);
        txtCircular[2 * len2] = '\0';

        int posicao_casamento = KMP_Busca(atual->string1, txtCircular);
        int posicao_casamento_reverse = KMP_Reverso(atual->string1, txtCircular);

        free(txtCircular);

        if (posicao_casamento != -1) {
            fprintf(output, "S %d\n", posicao_casamento + 1); // Se houver um casamento em ordem direta, escreve S
        } else if (posicao_casamento_reverse != -1) {
            fprintf(output, "S %d\n", (posicao_casamento_reverse + 1) / 2); // Se houver um casamento em ordem reversa, escreve S seguido pela posição do casamento invertido dividido por 2
        } else {
            fprintf(output, "N\n"); // Escreve N se não existir casamento
        }

        atual = atual->prox;
        caso_teste++;
    } while (atual != cabeca);
}