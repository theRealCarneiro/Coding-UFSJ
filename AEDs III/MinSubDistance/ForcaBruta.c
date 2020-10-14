#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Arruma as distancias entre os planetas e e retorna o maior valor entre eles */
int arrumaDistancia(int *combinacao, int *distancia, int numPlanetas){
    int aux[numPlanetas + 1], max = 0, soma = 0;
    memcpy(aux, distancia, (numPlanetas + 1) * sizeof(int));

    for(int i = 0; i < numPlanetas; i++){
        if(combinacao[i] == 0){ //Se o planeta não for ser usado
            soma += distancia[i]; //soma a distancia entre planetas que serão usados
            
            //Se estiver no ultimo loop e não for usar o ultimo planeta
            if(i == numPlanetas - 1){ 
                aux[i + 1] += soma; //Recebe a soma das distancias dos que não serão usados
                if(aux[i + 1] > aux[max]){ //testa se a ultima posição é o maior elemento do vetor
                    max = i + 1;
                    return aux[max];
                }
            }   

        }
        
        else { //Se o planeta for ser usado
            aux[i] += soma; //Recebe a soma das distancias dos que não serão usados
            soma = 0;
            if(aux[i] > aux[max]){ //Se a distancia for maior que a maior distancia atual
                max = i;
            }
        }
        
    }

    return aux[max];
}

/* Faz análise combinatória sem repetição e chama o algoritmo de força bruta ou o guloso */
int forcaBruta(int combinacao[], int numPlanetas, int recursos, int atual, int next, int *distancia, int min){
    if(atual == recursos) {
        int temp;
        temp = arrumaDistancia(combinacao, distancia, numPlanetas);

        if(temp < min || min == 0){ //Se o mínimo for maior que o máximo encontradado no algoritmo guloso ou no de força bruta
            min = temp;
        }
        return min;
    }
    else for(int i = next; i < numPlanetas; i++){
        combinacao[i] = 1;
        min = forcaBruta(combinacao, numPlanetas, recursos, atual + 1, i + 1, distancia, min); //chamada recursiva
        combinacao[i] = 0;
    }
    return min;
}
