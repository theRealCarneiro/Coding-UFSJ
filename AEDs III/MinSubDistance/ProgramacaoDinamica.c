#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Calcula a distancia baseado nos valores encontrados anteriormente */
int pegaDistancia(int **distancia, int i, int j){
    if(distancia[i][j] == 0) { //Se a distancia ainda não foi calculada
        distancia[i][j] = pegaDistancia(distancia, i, j - 1) + pegaDistancia(distancia, j - 1, j); //Chamada recursiva
        /*pegaDistancia(distancia, j - 1, j) sempre vai ser O(1)
        pq [j - 1][j] é a diagonal que já possui os valores desde o começo*/
    }
    return distancia[i][j];
}

/* Resolve o problema com programação dinâmica */
int programacaoDinamica(int **distancia, int i, int j, int recursos, int numPlanetas, int max, int min){

    //Se a posição for inválida
    if(i > numPlanetas || j > numPlanetas + 1){
        return min;
    } else if(distancia[i][j] == -1){
        return min;
    }

    if(pegaDistancia(distancia, i, j) > max) { //Calcula a distancia e o máximo
        max = distancia[i][j]; //Se a distancia for maior que o maximo, maximo = distancia
    }

    //Caso base recursos == 0 
    if(!recursos) {
        if(min > max || min == 0){
            min = max;
        }
        return min;
    }

    if(recursos > 1) {
        //Chamada recursiva, linha = coluna, coluna += 1
        min = programacaoDinamica(distancia, j, j + 1, recursos - 1, numPlanetas, max, min);
    }

    if(recursos == 1){
        //Vai do planeta j para a saída (ultima coluna)
        min = programacaoDinamica(distancia, j, numPlanetas + 1, 0, numPlanetas, max, min);
    }

    //Vai para a proxima coluna
    min = programacaoDinamica(distancia, i, j + 1, recursos, numPlanetas, max, min);

    return min;
}
