#include "lista.h"
#include "estrategia1.h"
#include "estrategia2.h"
#include "estrategia3.h"

int main(int argc, char *argv[]) {
    struct rusage buff;
    if (argc != 3) {
        printf("Use: %s <input.txt> <estrategia>\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    int strategy = atoi(argv[2]);

    executarEstrategia(input_file, strategy);

    getrusage(RUSAGE_SELF,&buff);
    printf("|---------------------------------------|\n");
    printf("|\tTempo = %lf segundos\t|\n", (double) buff.ru_utime.tv_sec + (double) buff.ru_utime.tv_usec / (double) 1000000);
    printf("|---------------------------------------|\n");
    printf("|\tUso de memória  = %ld Kb\t|\n", buff.ru_maxrss);
    printf("|---------------------------------------|\n\n\n");

    return 0;
}

