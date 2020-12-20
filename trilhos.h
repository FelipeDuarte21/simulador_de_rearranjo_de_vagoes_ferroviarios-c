#include "pilha.h"

struct trilhos{
    int qtdVagao;
    struct elementoTrilho *cabeca;
};

struct elementoTrilho{
    Pilha trilho;
    struct elementoTrilho *proximo;
};

typedef struct elementoTrilho ElementoTrilho;
typedef struct trilhos** Trilhos;

Trilhos inicializa_trilhos(int qtd);
void acrescentar_trilho(Trilhos t,int qtd);
void mover_vagao(Trilhos t,int vagao);
int retirar_vagao(Trilhos t);
int qtd_trilhos(Trilhos t);
void visualizar_trilhos(Trilhos t);
void libera_trilhos(Trilhos t);
