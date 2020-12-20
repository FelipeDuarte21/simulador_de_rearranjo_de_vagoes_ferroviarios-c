#include <stdio.h>
#include <stdlib.h>
#include "simulador.h"

Simulador inicializa_simulador(){

    sml** s = (sml**) calloc(1,sizeof(sml*));

    if(s == NULL){
        printf("Erro! falta de memória!");
        exit(1);
    }

    sml* elemento = (sml*) calloc(1,sizeof(sml));

    if(elemento == NULL){
        printf("Erro! falta de memória!");
        exit(1);
    }

    *s = elemento;

    return s;
}

void simular(Simulador s, Fila entrada, int qtdTrilhos, int qtdVagao){

    (*s)->entrada = entrada;
    (*s)->saida = inicializa_fila();
    (*s)->trilhosEspera = inicializa_trilhos(qtdVagao);
    acrescentar_trilho((*s)->trilhosEspera,qtdTrilhos);

    Fila vagoesNosTrilhos = inicializa_fila();

    int vagao,vagaoSaida = 1;

    system("cls");

    int etapa = 0;
    visualizar_etapa(s,&etapa,1);

    while(fila_vazia((*s)->entrada) != 1){

        vagao =  remover((*s)->entrada);

        if(vagao == vagaoSaida){
            inserir((*s)->saida,vagao);
            vagaoSaida++;
            visualizar_etapa(s,&etapa,1);

            while(consultar_valor(vagoesNosTrilhos,vagaoSaida) != 0){
                inserir((*s)->saida,retirar_vagao((*s)->trilhosEspera));
                vagaoSaida++;
                visualizar_etapa(s,&etapa,1);
            }

        }else{
            mover_vagao((*s)->trilhosEspera,vagao);
            inserir(vagoesNosTrilhos,vagao);
            visualizar_etapa(s,&etapa,1);
        }


    }
    visualizar_etapa(s,&etapa,2);

}

void visualizar_etapa(Simulador s, int *etapa, int parte){

    if(parte == 1){

        printf("\n\nEtapa: %d\n",*etapa);
        printf("Entrada: ");
        visualizar_fila((*s)->entrada);
        visualizar_trilhos((*s)->trilhosEspera);
        printf("Saída: ");
        visualizar_fila((*s)->saida);
        (*etapa)++;
        system("pause");
    }else{
        printf("\nTotal de Trilhos: %d\n",qtd_trilhos((*s)->trilhosEspera));
        printf("Numero Total de etapas: %d\n",*etapa);

    }

}

void libera_simulador(Simulador s){

    liberar_fila((*s)->entrada);
    liberar_fila((*s)->saida);
    libera_trilhos((*s)->trilhosEspera);

    free(*s);
    free(s);
}

Fila gerar_sequencia(int n){

    Fila f = inicializa_fila();
    gerar_fila(n,f);

    return f;

}
