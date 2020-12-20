#include <stdio.h>
#include <stdlib.h>
#include "trilhos.h"

Trilhos inicializa_trilhos(int qtd){

    struct trilhos** tr = (struct trilhos**) calloc(1,sizeof(struct trilhos*));

    if(tr == NULL){
        printf("Erro! Falta de memória");
        exit(1);
    }

    struct trilhos* t = (struct trilhos*) calloc(1,sizeof(struct trilhos));
    if(t == NULL){
        printf("Erro! Falta de memória");
        exit(1);
    }

    *tr = t;
    (*tr)->qtdVagao = qtd;

    return tr;
}

void acrescentar_trilho(Trilhos t,int qtd){

    int i;
    for(i = 0; i < qtd; i++){

        ElementoTrilho* no = (ElementoTrilho*) calloc(1,sizeof(ElementoTrilho));

        if(no == NULL){
            printf("Erro! falta de memoria.");
            exit(1);
        }

        no->trilho = inicializa_pilha();
        no->proximo = NULL;

        if( (*t)->cabeca == NULL){
            (*t)->cabeca = no;

        }else{
            ElementoTrilho* el = (*t)->cabeca;
            while(el->proximo != NULL){
                el = el->proximo;
            }
            el->proximo = no;

        }

    }

}

void mover_vagao(Trilhos t,int vagao){

    ElementoTrilho* no = (*t)->cabeca;
    int x;

    while(no != NULL){
        if(pilha_vazia(no->trilho) != 1){
            x = pop(no->trilho);
            push(no->trilho,x);
            if( (vagao < x) && (tamanho_pilha(no->trilho) < (*t)->qtdVagao) ){
                push(no->trilho,vagao);
                break;
            }
        }else{
            push(no->trilho,vagao);
            break;
        }
        no = no->proximo;
    }

    if(no == NULL){
        acrescentar_trilho(t,1);

        no = (*t)->cabeca;
        while(no->proximo != NULL){
            no = no->proximo;
        }

        push(no->trilho,vagao);
    }


}

int retirar_vagao(Trilhos t){

    ElementoTrilho* noAtual;

    ElementoTrilho* no = (*t)->cabeca;
    while(no != NULL){
        if(pilha_vazia(no->trilho) != 1){
            noAtual = no;
            break;
        }
        no = no->proximo;
    }


    int x,y;
    no = (*t)->cabeca;
    while(no != NULL){
        if(pilha_vazia(no->trilho) != 1){
            x = pop(no->trilho);
            push(no->trilho,x);
            y = pop(noAtual->trilho);
            push(noAtual->trilho,y);
            if(x < y){
                noAtual = no;
            }
        }
        no = no->proximo;
    }

    return pop(noAtual->trilho);

}

int qtd_trilhos(Trilhos t){

    int count = 0;

    ElementoTrilho* no = (*t)->cabeca;
    while(no != NULL){
        count++;
        no = no->proximo;
    }

    return count;
}

void visualizar_trilhos(Trilhos t){

    int i=0;
    ElementoTrilho* no = (*t)->cabeca;
    while(no != NULL){
        printf("----------------------\n");
        printf("Trilho %d: ",(i+1));
        visualiza_pilha(no->trilho);
        no = no->proximo;
        i++;
    }
    printf("----------------------\n");

}

void libera_trilhos(Trilhos t){

    while((*t)->cabeca != NULL){
        ElementoTrilho* no = (*t)->cabeca;
        (*t)->cabeca = no->proximo;

        libera_pilha(no->trilho);
        free(no);
    }

    free(*t);
    free(t);
}
