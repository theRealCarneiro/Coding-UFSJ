#include "lista.h"

int main(){
	lista *l = NULL;
	insereLista(&l, 1);
	insereLista(&l, 3);
	insereLista(&l, 2);
	removeLista(&l, 3);
	removeLista(&l, 2);
	printaLista(l);
	return 0;
}

lista *criaLista(){
	return (lista*)malloc(sizeof(lista));
}

void insereLista(lista **l, int chave){
	lista *celula = criaLista();
	celula->chave = chave;
	celula->prox = NULL;
	if(*l == NULL){
		*l = celula;	
		return;
	}

	lista *temp = *l;
	while(temp->prox != NULL){
		temp = temp->prox;
	}
	temp->prox = celula;
}

void printaLista(lista *l){
	lista *temp = l;
	while(temp != NULL){
		printf("%d ", temp->chave);
		temp = temp->prox;
	}
	printf("\n");
}

void removeLista(lista **l, int chave){
	if(*l == NULL)
		return;

	lista *temp = *l;
	if(temp->chave == chave){
		*l = temp->prox;
		return;
	}

	while(temp->prox != NULL){
		if(temp->prox->chave == chave){
			lista *aux = temp->prox;
			temp->prox = temp->prox->prox;
			free(aux);
		}
		temp = temp->prox;	
		return;
	}

	printf("Elemento nao existe na lista");
	return;
}
