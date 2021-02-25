#include "fila.h"

/*
void main(){
	fila *f = NULL;
	enfilera(&f, 10);
	enfilera(&f, 0);
	enfilera(&f, 1);
	enfilera(&f, 2);
	enfilera(&f, 3);
	printa_fila(f);
	printa_fila(desenfilera(&f));
	printa_fila(f);
}
*/

fila *cria_fila(){
	return (fila*)malloc(sizeof(fila));
}

void enfilera(fila **f, int chave){
	fila *celula = cria_fila();
	celula->chave = chave; 
	celula->prox = NULL;
	if(*f == NULL){
		*f = celula;
		return;
	}

	fila *temp = *f;
	while(temp->prox != NULL){
		temp = temp->prox;
	}
	temp->prox = celula;
}

fila *desenfilera(fila **f){
	if(*f == NULL)
		return NULL;

	fila *temp = *f;
	*f = temp->prox;
	temp->prox = NULL;
	return temp;
}


void printa_fila(fila *f){
	fila *temp = f;
	while(temp != NULL){
		printf("%d ", temp->chave);	
		temp = temp->prox;
	}
	printf("\n");
}

