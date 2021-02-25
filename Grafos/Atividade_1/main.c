#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

void main() {
	grafo g;
	g = criaGrafo();
	
	printaGrafo(g);
	printaSumario(g);

	/*trocar 1 pelo vertice que deseja*/
	int v = 1;

	grau(g, v); 
	sucessores(g, v); 
	antecessores(g, v); 
	kosaraju(g);
}
