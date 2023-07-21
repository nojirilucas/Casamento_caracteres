#include "estrategia3.h"

// Essa função implementa o algoritmo Shift-And para busca de padrão
int ShiftAnd(char *txt, char *padrao) {
    int txt_tam = strlen(txt);
    int padrao_tam = strlen(padrao);

    char txt_circ[txt_tam * 2 + 1];
    strcpy(txt_circ, txt);
    strcat(txt_circ, txt);

    unsigned int mascara[256] = {0}; // Cria a mascara de bits para realizar a busca eficiente
    unsigned int encontrou = 1;
    int i;

    // retorna a posição do casamento na string1 ou -1 se nenhum casamento for encontrado
    for (i = 0; i < padrao_tam; i++) {
        mascara[(unsigned char)padrao[i]] |= encontrou;
        encontrou = encontrou << 1;
    }

    unsigned int est = 0;
    for (i = 0; i < txt_tam * 2; i++) {
        est = ((est << 1) | 1) & mascara[(unsigned char)txt_circ[i]];
        if ((est & (1 << (padrao_tam - 1))) != 0) {
            int pos = i - padrao_tam + 1;
            if (pos >= txt_tam)
                pos -= txt_tam;
            if (pos < 0)
                pos += txt_tam;
            return pos;
        }
    }

    return -1;
}

// Essa função implementa o algoritmo Shift-And para busca de padrão em ordem reversa
int ShiftAnd_Reverso(char *txt, char *padrao) {
    int txt_tam = strlen(txt);

    char txt_reverso[txt_tam + 1];
    for (int i = 0; i < txt_tam; i++) {
        txt_reverso[i] = txt[txt_tam - 1 - i];
    }
    txt_reverso[txt_tam] = '\0';

    int pos = ShiftAnd(txt_reverso, padrao); // Chama a função ShiftAnd para buscar o padrão
    if (pos != -1)
        pos = txt_tam - 1 - pos;

    return pos;
}

// Essa função aplica a estratégia Shift-And para busca de padrão a cada par de strings da lista circular encadeada
void Casamento_ShiftAnd(No *cabeca, FILE *output) {
    No *atual = cabeca;
    do { // Percorre todos os nós da lista circular encadeada
        int pos = ShiftAnd(atual->string1, atual->string2); // Buscar o padrão na string1
        if (pos != -1) {
            //printf("S %d\n", pos+1);
        } else {
            pos = ShiftAnd_Reverso(atual->string1, atual->string2); // buscar o padrão na string2
            if (pos != -1) {
                //printf("S %d (string invertida)\n", pos+1);
            } else {
                //printf("N\n");
            }
        }

        pos = ShiftAnd(atual->string2, atual->string1);
        if (pos != -1) {
            fprintf(output, "S %d\n", pos+1);
        } else {
            pos = ShiftAnd_Reverso(atual->string2, atual->string1);
            if (pos != -1) {
                fprintf(output, "S %d\n", pos+1);
            } else {
                fprintf(output, "N\n");
            }
        }
        atual = atual->prox;
    } while (atual != cabeca);
}