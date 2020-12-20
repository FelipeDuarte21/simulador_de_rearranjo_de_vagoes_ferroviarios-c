#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "simulador.h"

#define MSG_ERRO "Valor Inválido! Digite um valor acima de 0(zero)"

int main(){
    setlocale(LC_ALL,"Portuguese");

    Simulador s = inicializa_simulador();
    int numVagao,qtdTrilho,numVagaoTrilho;
    Fila f;

    int acao;
    do{
        printf("\n");
        printf("SIMULADOR DE REARRANJO DE VAGÕES FERROVIÁRIOS\n");
        printf("1 - Digitar a sequência\n");
        printf("2 - Gerar sequência aleatória\n");
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
                printf("Quantidade de Vagões nos Trilhos: ");
                scanf("%d",&numVagaoTrilho);
                if(numVagaoTrilho <= 0){
                    printf("%s\n",MSG_ERRO);
                }
            }while(numVagaoTrilho <= 0);

            switch(acao){

                case 1: //Digitar a sequência

                    printf("Observações\n");
                    printf("-Digite 0(zero) para indicar final da sequência\n");
                    printf("-Digite valores acima de 0 e que a sequência contenha de 1 á N\n");

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
                                    printf("%s ou 0(zero) para indicar final da sequência\n",MSG_ERRO);
                                }
                            }
                        }while(numVagao != 0);

                        if(fila_continua(f) != 1){
                            printf("Sequênica Inválida!\n");
                            liberar_fila(f);
                        }else{
                            continua = 1;
                        }

                    }while(continua != 1);

                break;

                case 2: //Gerar sequênica aleatória

                    do{
                        printf("Número de vagões: ");
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
