#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha inicializa_pilha(){

    ElementoPilha** p = (ElementoPilha**) calloc(1,sizeof(ElementoPilha*));

    if(p == NULL){
        printf("Erro! Falta de memória.");
        exit(1);
    }

    return p;
}

void push(Pilha p,int x){

    ElementoPilha* el = (ElementoPilha*) calloc(1,sizeof(ElementoPilha));

    if(el == NULL){
        printf("Erro! falta de memória.");
        exit(1);
    }

    el->valor = x;

    if(*p == NULL){
        el->proximo = NULL;
        *p = el;

    }else{
        el->proximo = *p;
        *p = el;
    }

}

int pop(Pilha p){

    if(*p != NULL){

        ElementoPilha* el = *p;

        int r = el->valor;

        *p = el->proximo;

        free(el);

        return r;

    }else{
        return -1;
    }

}

int pilha_vazia(Pilha p){

    ElementoPilha* el = *p;

    if(el == NULL){
        return 1;
    }else{
        return 0;
    }

}

int tamanho_pilha(Pilha p){

    int count = 0;

    ElementoPilha* el = *p;
    while(el != NULL){
        count++;
        el = el->proximo;
    }

    return count;
}

void visualiza_pilha(Pilha p){

    ElementoPilha* el = *p;

    while(el != NULL){
        printf("%d ",el->valor);
        el = el->proximo;
    }
    printf("\n");

}

void libera_pilha(Pilha p){

    if(p != NULL){

        while( *p != NULL ){
            ElementoPilha* el = *p;
            *p = el->proximo;
            free(el);
        }

        free(p);

    }

}
