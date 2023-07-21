#ifndef ESTRATEGIA2_H
#define ESTRATEGIA2_H

#include "lista.h"

//void KMP(char *padrao, char *txt, int caso_teste);
int KMP_Reverso(char *padrao, char *txt);
int KMP_Busca(char *padrao, char *txt);
void Contagem_Caracteres(char *padrao, int M, int *lps);
void Casamento_KMP(No *cabeca, FILE *output);
#endif