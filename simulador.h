#include "fila.h"
#include "trilhos.h"

struct simulador{
    Fila entrada;
    Fila saida;
    Trilhos trilhosEspera;
};

typedef struct simulador sml;
typedef sml** Simulador;

Simulador inicializa_simulador();
void simular(Simulador s, Fila entrada, int qtdTrilhos, int qtdVagao);
void visualizar_etapa(Simulador s,int *etapa,int parte);
void libera_simulador(Simulador s);
Fila gerar_sequencia(int n);
