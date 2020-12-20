struct elementoPilha{
    int valor;
    struct elementoPilha* proximo;
};

typedef struct elementoPilha ElementoPilha;
typedef ElementoPilha** Pilha;

Pilha inicializa_pilha();
void push(Pilha p,int x);
int pop(Pilha p);
int pilha_vazia(Pilha p);
int tamanho_pilha(Pilha p);
void visualiza_pilha(Pilha p);
void libera_pilha(Pilha p);
