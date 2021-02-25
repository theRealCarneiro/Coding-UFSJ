#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int chave;
	struct lista *prox;
} lista;

lista *criaLista();

void insereLista(lista **l, int chave);

void printaLista(lista *l);

void removeLista(lista **l, int chave);
