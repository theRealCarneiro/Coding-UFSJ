#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int chave;
	int valor;
	struct lista *prox;
} lista;

lista *criaLista();

lista *insereLista(lista *l, int chave, int valor);

void printaLista(lista *l);

lista *removeLista(lista *l, int chave);
