#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
	int chave;
	struct fila *prox;
} fila;

fila *cria_fila();

void enfilera(fila **f, int chave);

fila *desenfilera(fila **f);

void printa_fila(fila *f);
