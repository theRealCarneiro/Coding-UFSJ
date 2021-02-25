#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "pilha.h"

typedef struct grafo {
	lista **listaAdj;
	pilha *p;
	int *visitado;
	int **matrixAdj;
	int numElementos;
	int numArestas;
} grafo;


void kosaraju(grafo g);

pilha *enchePilha(grafo g, int i);

void dfs(grafo g, int i, FILE *fp);

void buscaProfundidadeMatrixAdj(grafo g, int i);

void buscaProfundidadeListaAdj(grafo g, int i);

grafo criaListaAdj(grafo g, int val[][3]);

grafo criaMatrixAdj(grafo g, int val[][3]);

void printaGrafo(grafo g);

//grafo criaListaAdjPorMatrixAdj(grafo g);

//float densidade(grafo g);

void printaSumario(grafo g);

void grau(grafo g, int indice);

void sucessores(grafo g, int indice);

void antecessores(grafo g, int indice);

int maxx(int a, int b, int max);

int lineCount(char *fileName);

grafo criaGrafo();

