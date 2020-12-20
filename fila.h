struct elementoFila{
    int valor;
    struct elementoFila *proximo;
};

typedef struct elementoFila ElementoFila;
typedef ElementoFila** Fila;

Fila inicializa_fila();
void inserir(Fila f,int x);
int remover(Fila f);
int fila_vazia(Fila f);
int consultar_valor(Fila f,int valor);
void visualizar_fila(Fila f);
void liberar_fila(Fila f);
void gerar_fila(int n,Fila f);
int fila_continua(Fila f);
