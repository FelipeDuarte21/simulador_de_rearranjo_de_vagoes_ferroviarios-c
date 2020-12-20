#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "fila.h"

Fila inicializa_fila(){

    ElementoFila** f = (ElementoFila**) calloc(1,sizeof(ElementoFila*));

    if(f == NULL){
        printf("Erro! falta de memória.");
        exit(1);
    }

    return f;

}

void inserir(Fila f,int x){

    ElementoFila* el = (ElementoFila*) calloc(1,sizeof(ElementoFila));

    if(el == NULL){
        printf("Erro! falta de memoria");
        exit(1);
    }

    el->valor = x;
    el->proximo = NULL;

    if(*f == NULL){
        *f = el;

    }else{
        ElementoFila* no = *f;
        while(no->proximo != NULL){
            no = no->proximo;
        }
        no->proximo = el;

    }

}

int remover(Fila f){

    ElementoFila* no = *f;

    *f = no->proximo;

    int r = no->valor;
    free(no);

    return r;

}

int fila_vazia(Fila f){

    ElementoFila* no = *f;

    if(no == NULL){
        return 1;
    }else{
        return 0;
    }

}

int consultar_valor(Fila f,int valor){

    int r = 0;

    ElementoFila* no  = *f;
    while(no != NULL){
        if(valor == no->valor){
            r = 1;
            break;
        }
        no = no->proximo;
    }

    return r;
}

void visualizar_fila(Fila f){

    ElementoFila* no = *f;

    while(no != NULL){
        printf("%d ",no->valor);
        no = no->proximo;
    }
    printf("\n");

}

void liberar_fila(Fila f){

    while(*f != NULL){
        ElementoFila* no = *f;
        *f = no->proximo;
        free(no);
    }

    free(f);
}

void gerar_fila(int n,Fila f){

    int i;
    for(i=0; i < n; i++){
        inserir(f,(i+1));
    }

    srand(time(NULL));

    int x,y,indice;
    ElementoFila* noAux;

    ElementoFila* no = *f;
    while(no != NULL){

        noAux = *f;
        indice = (rand() % (n-1)) + 1;
        for(i=1; i < indice; i++){
            noAux = noAux->proximo;
        }

        x = no->valor;
        y = noAux->valor;
        no->valor = y;
        noAux->valor = x;

        no = no->proximo;
    }

}

int fila_continua(Fila f){

    int count = 0;

    ElementoFila* no = *f;
    while(no != NULL){
        count++;
        no = no->proximo;
    }

    int num = 1;
    while(num <= count){
        if(consultar_valor(f,num) == 0){
            break;
        }
        num++;
    }

    if(num > count){
        return 1;
    }else{
        return 0;
    }

}
