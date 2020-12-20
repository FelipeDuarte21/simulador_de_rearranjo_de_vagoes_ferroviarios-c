#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "simulador.h"

#define MSG_ERRO "Valor Inv�lido! Digite um valor acima de 0(zero)"

int main(){
    setlocale(LC_ALL,"Portuguese");

    Simulador s = inicializa_simulador();
    int numVagao,qtdTrilho,numVagaoTrilho;
    Fila f;

    int acao;
    do{
        printf("\n");
        printf("SIMULADOR DE REARRANJO DE VAG�ES FERROVI�RIOS\n");
        printf("1 - Digitar a sequ�ncia\n");
        printf("2 - Gerar sequ�ncia aleat�ria\n");
        printf("0 - Sair\n");
        printf("acao: ");
        scanf("%d",&acao);

        if((acao > 0) && (acao <= 2) ){

            do{
                printf("Quantidade de Trilhos: ");
                scanf("%d",&qtdTrilho);
                if(qtdTrilho <= 0){
                    printf("%s\n",MSG_ERRO);
                }
            }while(qtdTrilho <= 0);

            do{
                printf("Quantidade de Vag�es nos Trilhos: ");
                scanf("%d",&numVagaoTrilho);
                if(numVagaoTrilho <= 0){
                    printf("%s\n",MSG_ERRO);
                }
            }while(numVagaoTrilho <= 0);

            switch(acao){

                case 1: //Digitar a sequ�ncia

                    printf("Observa��es\n");
                    printf("-Digite 0(zero) para indicar final da sequ�ncia\n");
                    printf("-Digite valores acima de 0 e que a sequ�ncia contenha de 1 � N\n");

                    int continua = 0;
                    do{

                        f = inicializa_fila();

                        do{
                            printf("Valor: ");
                            scanf("%d",&numVagao);
                            if(numVagao != 0){
                                if(numVagao > 0){
                                    inserir(f,numVagao);
                                }else{
                                    printf("%s ou 0(zero) para indicar final da sequ�ncia\n",MSG_ERRO);
                                }
                            }
                        }while(numVagao != 0);

                        if(fila_continua(f) != 1){
                            printf("Sequ�nica Inv�lida!\n");
                            liberar_fila(f);
                        }else{
                            continua = 1;
                        }

                    }while(continua != 1);

                break;

                case 2: //Gerar sequ�nica aleat�ria

                    do{
                        printf("N�mero de vag�es: ");
                        scanf("%d",&numVagao);
                        if(numVagao <= 0){
                            printf("%s\n",MSG_ERRO);
                        }
                    }while(numVagao <= 0);

                    f = gerar_sequencia(numVagao);

                break;
            }

            simular(s,f,qtdTrilho,numVagaoTrilho);

        }

    }while(acao != 0);

    libera_simulador(s);

    return 0;
}
