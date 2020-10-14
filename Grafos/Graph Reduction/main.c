#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

void main() {
	grafo g;
	g = criaGrafo();
//	buscaProfundidadeListaAdj(g, 1);
//	printf("\n");
//	buscaProfundidadeMatrixAdj(g, 1);

	
	printaGrafo(g);
	printaSumario(g);
	grau(g, 1);
	sucessores(g, 1);
	antecessores(g, 1);
	kosaraju(g);
	//printf("\n");
	
}
