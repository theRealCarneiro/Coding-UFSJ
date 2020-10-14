#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cabecalho.h"

//Testa se os argumentos de inicialização do programa são válidos
int testaArg(char **argv){
    if(!strcmp(argv[1], "FB")){ //Força Bruta
        return 1;
    }
    else if(!strcmp(argv[1], "AG")){ //Algoritmo guloso
        return 2;
    }
    else if(!strcmp(argv[1], "PD")){ //Programação dinâmica
        return 3;
    }
    printf("ARGUMENTO INVALIDO\n");
    return 0;
}

void main(int argc, char *argv[]){
    int escolha = testaArg(argv);
    if(!escolha) exit(0);
    int rep, numPlanetas, recursos;
    scanf("%d", &rep);
    int *min = (int*)malloc(sizeof(int) * rep);
    switch (escolha) {
        case 1:
            min = chamaForcaBruta(rep, min);
            break;
        case 2:
            min = chamaAlgoritmoGuloso(rep, min);
            break;
        case 3:
            min = chamaProgramacaoDinamica(rep, min);
            break;
    }

    //Imprime os resultados
    printf("\n");
    for(int i = 0; i < rep; i++){
        printf("%d \n", min[i]);
    }

}
