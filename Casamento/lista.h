#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>


typedef struct No {
    char string1[100];
    char string2[100];
    struct No* prox;
} No;

int Conta_nos(No* cabeca);
No* Cria_no(char string1[], char string2[]);
void Inserir_no(No** cabeca, char string1[], char string2[]);
void Libera_lista(No** cabeca);
int Leitura_input(const char* input, No** cabeca);
void executarEstrategia(const char *entrada, int strategy);

#endif