#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Pega o maior elemento do vetor */
int max(int *vetor, int numPlanetas){
    int max = 0; //max começa com o indice 0
    for(int i = 1; i <= numPlanetas; i++){ //Loop inicia em 1 pq max já é a posição 0
        if(vetor[max] < vetor[i]){ //Se o valor na posição max for menor que o valor na posição i
            max = i;
        }
    }
    return vetor[max];
}

/* Resolve o problema com um algoritmo guloso */
int algoritmoGuloso(int *distancia, int numPlanetas, int recursos){
    int n = numPlanetas - recursos; //numero de planetas que não serão visitados
    
    for(int j = 0; j < n; j++){
        int min = 0;
        
        for(int i = 0; i < numPlanetas - j; i++){
            //Se a distancia entre dois planetas for menor que a atual menor distancia entre dois planetas
            if(distancia[i] + distancia[i + 1] <= distancia[min] + distancia[min + 1]){
                if(distancia[i] - distancia[i + 1] < distancia[min] - distancia[min + 1]){ //Testa a prioridade
                    min = i;
                }
                if(distancia[i] + distancia[i + 1] < distancia[min] + distancia[min + 1]){ //Testa a prioridade
                    min = i;
                }
            }
        }

        //Atualiza as distancias entre os planetas
        for(int i = min; i < numPlanetas; i++){
            if(i == min){ //Se for o planeta a receber a distancia do proximo
                distancia[i] += distancia[i + 1];
            } else distancia[i] = distancia[i + 1]; //senao so concerta o vetor
        }
        
    }

    return max(distancia, numPlanetas);
}
