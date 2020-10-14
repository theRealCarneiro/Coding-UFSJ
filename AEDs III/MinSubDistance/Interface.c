#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cabecalho.h"

int *chamaAlgoritmoGuloso(int rep, int *min){
    int numPlanetas, recursos;
    for(int x = 0; x < rep; x++){
        scanf("%d %d", &numPlanetas, &recursos);
        int *distancia = (int*)calloc(numPlanetas + 1, sizeof(int));

        //Lê as distancias
        for(int i = 0; i <= numPlanetas; i++){
            scanf("%d", &distancia[i]);
        }

        min[x] = algoritmoGuloso(distancia, numPlanetas, recursos);
        free(distancia);
    }
    return min;
}

int *chamaProgramacaoDinamica(int rep, int *min){
    int numPlanetas, recursos;
    for(int x = 0; x < rep; x++){
        scanf("%d %d", &numPlanetas, &recursos);
        //Aloca dinamicamente a matriz de distancias
        int **distancia = (int**)calloc(numPlanetas + 2, sizeof(int*));
        for(int i = 0; i < numPlanetas + 2; i++){
            distancia[i] = (int*)calloc(numPlanetas + 2, sizeof(int));
        }

        //Lê as distancias entre os planetas
        for(int i = 0; i <= numPlanetas; i++){
            scanf("%d", &distancia[i][i + 1]);
            if(i + numPlanetas - recursos + 2 <= numPlanetas + 1){ //Testa qual a maior distancia que pode andar
                distancia[i][i + numPlanetas - recursos + 2] = -1; //-1 simboliza de que não é possível fazer um salto até esse ponto
            }
        }

        //chama a função para resolver com Programacao dinâmica
        min[x] = programacaoDinamica(distancia, 0, 1, recursos, numPlanetas, 0 , 0);

        //libera a memoria
        free(distancia);
    }
    return min;
}

int *chamaForcaBruta(int rep, int *min){
    int numPlanetas, recursos;
    for(int x = 0; x < rep; x++){
        scanf("%d %d", &numPlanetas, &recursos);
        //Aloca dinamicamente o vetor de distancias e de combinações
        int *distancia = (int*)calloc(numPlanetas + 1, sizeof(int));
        int *combinacao = (int*)calloc(numPlanetas, sizeof(int));

        //Lê as distancias
        for(int i = 0; i <= numPlanetas; i++){
            scanf("%d", &distancia[i]);
        }

        min[x] = forcaBruta(combinacao, numPlanetas, recursos, 0, 0, distancia, 0);

        //libera a memoria
        free(distancia);
        free(combinacao);
    }
    return min;
}
