#include "pilha.h"

/*
void main(){
	pilha *p = NULL;
	empilha(&p, 1);
	empilha(&p, 0);
	empilha(&p, 3);
	printaPilha(p);
	printf("%d\n",desempilha(&p));
	printaPilha(p);
}
*/

pilha *criaPilha(){
	return (pilha*)malloc(sizeof(pilha));
}

void empilha(pilha **p, int chave){
	pilha *celula = criaPilha();
	celula->chave = chave; 
	celula->prox = *p;
	*p = celula;
}

int desempilha(pilha **p){
	pilha *temp = *p;
	int chave = temp->chave;
	*p = temp->prox;
	free(temp);
	return chave;
}


void printaPilha(pilha *p){
	pilha *temp = p;
	while(temp != NULL){
		printf("%d ", temp->chave);	
		temp = temp->prox;
	}
	printf("\n");
}

