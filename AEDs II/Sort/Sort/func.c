#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "header.h"

void preenche(elemento *listaElementos, int ordem){
  int i = 0, j = 0, k = 0;
  switch(ordem){
    case 1: //Aleatorio
      while (i < TAM){
        listaElementos[i].chave = rand() % RANGE;
        i++;
      }
      break;
    case 2: //Crescente
      while (i < TAM){
        listaElementos[i].chave = i;
        i++;
      }
      break;
    case 3: //Decrescente
      i = TAM;
      while (i >= 0){
        listaElementos[i].chave = i;
        i--;
      }
      break;
  }
}

benchmark mergeSort(elemento *listaElementos, int rep){
  int i;
  int aux;
  benchmark bench;
  bench.comp = 0;
  bench.mov = 0;
  bench.tempo = 0;
  elemento *temp;
  for(i = 0; i < rep; i++) {
    temp = listaElementos;
    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);
    callMergeSort(temp, 0, TAM - 1, &bench);
    gettimeofday(&fim, NULL);
    bench.tempo += (((fim.tv_sec - inicio.tv_sec) * 1000000) + (fim.tv_usec - inicio.tv_usec));
  }
  bench.tempo /= rep;
  bench.mov /= rep;
  bench.comp /= rep;
  return bench;
}



benchmark quickSort(elemento *listaElementos, int rep){
  int i;
  int aux;
  benchmark bench;
  bench.comp = 0;
  bench.mov = 0;
  bench.tempo = 0;
  elemento *temp;
  for(i = 0; i < rep; i++) {
    temp = listaElementos;
    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);
    callQuickSort(temp, 0, TAM - 1, &bench);
    gettimeofday(&fim, NULL);
    bench.tempo += (((fim.tv_sec - inicio.tv_sec) * 1000000) + (fim.tv_usec - inicio.tv_usec));
  }
  bench.tempo /= rep;
  bench.mov /= rep;
  bench.comp /= rep;
  return bench;
}

void merge(elemento *listaElementos, int comeco, int meio, int fim, benchmark *bench) {
  int com1 = comeco, com2 = meio + 1, comAux = 0, tam = fim-comeco + 1;
  elemento *vetAux;
  vetAux = (elemento*)malloc(tam * sizeof(struct elemento));
  while(com1 <= meio && com2 <= fim){
    bench->comp++;
      if(listaElementos[com1].chave < listaElementos[com2].chave) {
        bench->comp++;
        vetAux[comAux].chave = listaElementos[com1].chave;
        bench->mov++;
        com1++;
      }
      else {
        vetAux[comAux].chave = listaElementos[com2].chave;
        bench->mov++;
        com2++;
      }
      comAux++;
  }
  while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
    bench->comp++;
    vetAux[comAux].chave = listaElementos[com1].chave;
    bench->mov++;
    comAux++;
    com1++;
  }
  while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
    bench->comp++;
    vetAux[comAux].chave = listaElementos[com2].chave;
    comAux++;
    com2++;
  }
  for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
    bench->comp++;
    listaElementos[comAux].chave = vetAux[comAux-comeco].chave;
    bench->mov++;
  }
  free(vetAux);
}

benchmark callMergeSort(elemento *listaElementos, int comeco, int fim, benchmark *bench){
  if (comeco < fim) {
    bench->comp++;
    int meio = (fim+comeco) / 2;
    callMergeSort(listaElementos, comeco, meio, bench);
    callMergeSort(listaElementos, meio + 1, fim, bench);
    merge(listaElementos, comeco, meio, fim, bench);
  }
}

benchmark callQuickSort(elemento *listaElementos, int inicio, int fim, benchmark *bench){
  int pivo, aux, i, j, meio;
  i = inicio;
  j = fim;
  meio = (int) ((i + j) / 2);
  pivo = listaElementos[meio].chave;
  do {
    while (listaElementos[i].chave < pivo){
      bench->comp++;
      i = i + 1;
    }
    while (listaElementos[j].chave > pivo){
      bench->comp++;
      j = j - 1;
    }
    if(i <= j){
      bench->comp++;
      aux = listaElementos[i].chave;
      listaElementos[i].chave = listaElementos[j].chave;
      listaElementos[j].chave = aux;
      bench->mov += 2;
      i = i + 1;
      j = j - 1;
    }
    bench->comp++;
  } while(j > i);
  if(inicio < j){
    bench->comp++;
    callQuickSort(listaElementos, inicio, j, bench);
  }
  if(i < fim){
    bench->comp++;
    callQuickSort(listaElementos, i, fim, bench);
  }
}

benchmark insertionSort(elemento *listaElementos, int rep) {
  int escolhido, j, i;
  benchmark bench;
  bench.tempo = 0;
  bench.comp = 0;
  bench.mov = 0;
  int cont = rep;
  while (cont != 0) {
    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);
    for (int i = 1; i < TAM ; i++) {
      bench.comp++;
      escolhido = listaElementos[i].chave;
  		j = i - 1;
  		while ((j >= 0) && (listaElementos[j].chave > escolhido)) {
        bench.comp++;
  		  listaElementos[j + 1].chave = listaElementos[j].chave;
        bench.mov++;
  		  j--;
  	  }
  		listaElementos[j + 1].chave = escolhido;
      bench.mov++;
  	}
    gettimeofday(&fim, NULL);
    bench.tempo += (((fim.tv_sec - inicio.tv_sec) * 1000000) + (fim.tv_usec - inicio.tv_usec));
    cont--;
  }
  bench.tempo /= rep;
  bench.mov /= rep;
  bench.comp /= rep;
  return bench;
}

benchmark shellSort(elemento *listaElementos, int rep) {
  benchmark bench;
  bench.tempo = 0;
  bench.comp = 0;
  bench.mov = 0;
  int cont = rep;
  while (cont != 0) {
    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);
    int i , j , value;
    int x;
    int gap = 1;
    while(gap < TAM) {
        gap = 3 * gap + 1;
        bench.comp++;
    }
    while ( gap > 1) {
      bench.comp++;
        gap /= 3;
        for(i = gap; i < TAM; i++) {
            bench.comp++;
            value = listaElementos[i].chave;
            j = i;
            while (j > gap && value <= listaElementos[j - gap].chave) {
                bench.comp += 2;
                listaElementos[j].chave = listaElementos[j - gap].chave;
                bench.mov++;
                j = j - gap;
            }
            listaElementos[j].chave = value;
            bench.mov++;
        }
    }
    gettimeofday(&fim, NULL);
    bench.tempo += (((fim.tv_sec - inicio.tv_sec) * 1000000) + (fim.tv_usec - inicio.tv_usec));
    cont--;
  }
  bench.tempo /= rep;
  bench.mov /= rep;
  bench.comp /= rep;
  return bench;
}

benchmark selectionSort(elemento *listaElementos, int rep) {
  benchmark bench;
  bench.tempo = 0;
  bench.comp = 0;
  bench.mov = 0;
  int cont = rep;
  while (cont != 0) {
    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);
    int i, j, min, aux;
    for (i = 0; i < (TAM - 1); i++) {
      bench.comp++;
       min = i;
       for (j = (i + 1); j < TAM; j++) {
         bench.comp++;
         if(listaElementos[j].chave < listaElementos[min].chave){
           min = j;
           bench.comp++;
         }
       }
       if (listaElementos[i].chave != listaElementos[min].chave) {
         bench.comp++;
         aux = listaElementos[i].chave;
         listaElementos[i].chave = listaElementos[min].chave;
         listaElementos[min].chave = aux;
         bench.mov += 2;
       }
    }
    gettimeofday(&fim, NULL);
    bench.tempo += (((fim.tv_sec - inicio.tv_sec) * 1000000) + (fim.tv_usec - inicio.tv_usec));
    cont--;
  }
  bench.tempo /= rep;
  bench.mov /= rep;
  bench.comp /= rep;
  return bench;
}


benchmark heapSort(elemento *listaElementos, int rep) {
  benchmark bench;
  bench.tempo = 0;
  bench.comp = 0;
  bench.mov = 0;
  int cont = rep;
  while (cont != 0) {
    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);
    int n = TAM;
    int i = n / 2, pai, filho, t;
    while(1) {
      bench.comp++;
      if (i > 0) {
        bench.comp++;
        i--;
        t = listaElementos[i].chave;
      }
      else {
        n--;
        if (n == 0){
          bench.comp++;
           break;
        }
        t = listaElementos[n].chave;
        listaElementos[n].chave = listaElementos[0].chave;
        bench.mov++;
        }
        pai = i;
        filho = i * 2 + 1;
        while (filho < n) {
          bench.comp++;
          if ((filho + 1 < n)  &&  (listaElementos[filho + 1].chave > listaElementos[filho].chave)){
            bench.comp += 2;
            filho++;
          }
          if (listaElementos[filho].chave > t) {
            bench.comp++;
            listaElementos[pai].chave = listaElementos[filho].chave;
            bench.mov++;
            pai = filho;
            filho = pai * 2 + 1;
          }
          else {
            break;
          }
        }
        listaElementos[pai].chave = t;
        bench.mov++;
    }
    gettimeofday(&fim, NULL);
    bench.tempo += (((fim.tv_sec - inicio.tv_sec) * 1000000) + (fim.tv_usec - inicio.tv_usec));
    cont--;
    }
 bench.tempo /= rep;
 bench.mov /= rep;
 bench.comp /= rep;
 return bench;
}
