#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
	int chave;
	struct pilha *prox;
} pilha;

pilha *criaPilha();

void empilha(pilha **p, int chave);

int desempilha(pilha **p);

void printaPilha(pilha *p);

