#include "lista.h"

lista *criaLista(){
	return (lista*)malloc(sizeof(lista));
}

lista *insereLista(lista *l, int chave, int valor){
	lista *celula = criaLista();
	celula->chave = chave; 
	celula->valor = valor;
	celula->prox = NULL;
	if(l == NULL || celula->chave < l->chave){
		celula->prox = l;	
		return celula;
	}
	else {
		lista *temp = l;
		while(temp->prox != NULL && temp->prox->chave < celula->chave){
			temp = temp->prox;
		}
		celula->prox = temp->prox;
		temp->prox = celula;
	}
	return l;
}

void printaLista(lista *l){
	lista *temp = l;
	while(temp != NULL){
		//printf("%c %d \n", temp->chave + 65, temp->valor);
		printf("%d->", temp->chave);
		temp = temp->prox;
	}
	printf("null\n");
}

lista *removeLista(lista *l, int chave){
	if(l->chave == chave){
		l = l->prox;
		return l;
	}

	lista *temp = l;
	while(temp->prox != NULL){
		if(temp->prox->chave == chave){
			lista *aux = temp->prox;
			temp->prox = temp->prox->prox;
			free(aux);
		}
		temp = temp->prox;	
		return l;
	}

	printf("Elemento nao existe na lista");
	return l;
	
}
