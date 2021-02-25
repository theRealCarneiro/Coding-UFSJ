#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
	int chave;
	struct pilha *prox;
} pilha;

pilha *criaPilha();

pilha *empilha(pilha *p, int chave);

pilha *desempilha(pilha *p, int *chave);

void printaPilha(pilha *p);

