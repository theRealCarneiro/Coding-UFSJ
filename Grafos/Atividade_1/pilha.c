#include "pilha.h"

/*
void main(){
	pilha *p = NULL;
	p = empilha(p, 1);
	p = empilha(p, 0);
	p = empilha(p, 3);
//	printaPilha(p);
//	desempilha(p);
	int topo;
	p = desempilha(p, &topo);
	printaPilha(p);
	printf("%d", topo);
}
*/

pilha *criaPilha(){
	return (pilha*)malloc(sizeof(pilha));
}

pilha *empilha(pilha *p, int chave){
	pilha *celula = criaPilha();
	celula->chave = chave; 
	celula->prox = p;
	return celula;
}

pilha *desempilha(pilha *p, int *chave){
	pilha *temp = p;
	*chave = p->chave;
	p = p->prox;
	free(temp);
	return p;
}


void printaPilha(pilha *p){
	pilha *temp = p;
	while(temp != NULL){
		printf("%d ", temp->chave);	
		temp = temp->prox;
	}
	printf("\n");
}

