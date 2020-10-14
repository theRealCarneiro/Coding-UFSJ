#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "header.h"

void main(){
  int k = 0;
  benchmark bench;
  for(k = 0; k < 5; k++){
    if(k == 0){
      TAM = 20;
    }
    else if(k == 1){
      TAM = 500;
    }
    else if(k == 2){
      TAM = 5000;
    }
    else if(k == 3){
      TAM = 10000;
    }
    else TAM = 200000;
    elemento *teste;
    teste = malloc(TAM * (sizeof(elemento)));
    preenche(teste, 1);
    bench = selectionSort(teste, 10);
    printf("Slection Sort %ld elementos aleatorios: %ld microsegundos, %ld movimentações e %ld comparações\n", TAM, bench.tempo, bench.mov, bench.comp);
    bench = insertionSort(teste, 10);
    printf("Insertion Sort %ld elementos aleatorios: %ld microsegundos, %ld movimentações e %ld comparações\n", TAM, bench.tempo, bench.mov, bench.comp);
    bench = shellSort(teste, 10);
    printf("Shell Sort %ld elementos aleatorios: %ld microsegundos, %ld movimentações e %ld comparações\n", TAM, bench.tempo, bench.mov, bench.comp);
    bench = heapSort(teste, 10);
    printf("Heap Sort %ld elementos aleatorios: %ld microsegundos, %ld movimentações e %ld comparações\n", TAM, bench.tempo, bench.mov, bench.comp);
    bench = quickSort(teste, 10);
    printf("Quick Sort %ld elementos aleatorios: %ld microsegundos, %ld movimentações e %ld comparações\n", TAM, bench.tempo, bench.mov, bench.comp);
    bench = mergeSort(teste, 10);
    printf("Merge Sort %ld elementos aleatorios: %ld microsegundos, %ld movimentações e %ld comparações\n\n", TAM, bench.tempo, bench.mov, bench.comp);

    preenche(teste, 2);
    bench = selectionSort(teste, 10);
    printf("Slection Sort %ld elementos em ordem crescente: %ld microsegundos, %ld movimentações e %ld comparações\n", TAM, bench.tempo, bench.mov, bench.comp);
    bench = insertionSort(teste, 10);
    printf("Insertion Sort %ld elementos em ordem crescente: %ld microsegundos, %ld movimentações e %ld comparações\n", TAM, bench.tempo, bench.mov, bench.comp);
    bench = shellSort(teste, 10);
    printf("Shell Sort %ld elementos em ordem crescente: %ld microsegundos, %ld movimentações e %ld comparações\n", TAM, bench.tempo, bench.mov, bench.comp);
    bench = heapSort(teste, 10);
    printf("Heap Sort %ld elementos em ordem crescente: %ld microsegundos, %ld movimentações e %ld comparações\n", TAM, bench.tempo, bench.mov, bench.comp);
    bench = quickSort(teste, 10);
    printf("Quick Sort %ld elementos em ordem crescente: %ld microsegundos, %ld movimentações e %ld comparações\n", TAM, bench.tempo, bench.mov, bench.comp);
    bench = mergeSort(teste, 10);
    printf("Merge Sort %ld elementos em ordem crescente: %ld microsegundos, %ld movimentações e %ld comparações\n\n", TAM, bench.tempo, bench.mov, bench.comp);

    preenche(teste, 3);
    bench = selectionSort(teste, 10);
    printf("Slection Sort %ld elementos em ordem decrescente: %ld microsegundos, %ld movimentações e %ld comparações\n", TAM, bench.tempo, bench.mov, bench.comp);
    bench = insertionSort(teste, 10);
    printf("Insertion Sort %ld elementos em ordem decrescente: %ld microsegundos, %ld movimentações e %ld comparações\n", TAM, bench.tempo, bench.mov, bench.comp);
    bench = shellSort(teste, 10);
    printf("Shell Sort %ld elementos em ordem decrescente: %ld microsegundos, %ld movimentações e %ld comparações\n", TAM, bench.tempo, bench.mov, bench.comp);
    bench = heapSort(teste, 10);
    printf("Heap Sort %ld elementos em ordem decrescente: %ld microsegundos, %ld movimentações e %ld comparações\n", TAM, bench.tempo, bench.mov, bench.comp);
    bench = quickSort(teste, 10);
    printf("Quick Sort %ld elementos em ordem decrescente: %ld microsegundos, %ld movimentações e %ld comparações\n", TAM, bench.tempo, bench.mov, bench.comp);
    bench = mergeSort(teste, 10);
    printf("Merge Sort %ld elementos em ordem decrescente: %ld microsegundos, %ld movimentações e %ld comparações\n\n", TAM, bench.tempo, bench.mov, bench.comp);

    free(teste);
  }
}
