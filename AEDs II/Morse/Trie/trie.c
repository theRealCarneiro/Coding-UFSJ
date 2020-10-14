#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "trie.h"

nodo *inicializaNodo(nodo *raiz){ //Inicializa a árvore 
     raiz = (nodo *)malloc(sizeof(nodo)); //Aloca espaço na memoria para o nodo
     raiz->esq = NULL;//Apontador para o filho da esquerda recebe nulo
     raiz->dir = NULL;//Apontador para o filho da direita recebe nulo
     raiz->val = '!';//Para indicar que é a raiz
     return raiz;
}

nodo *insereNodo(nodo *raiz, char val, char chave[6]){ //Insere novo elemento na árvore
     nodo *temp; //Cria um nodo temporario para retornar a posição a ser inserido o nodo
     if(chave[0] != '\0'){ //Testa se já verificou todos os valores da chave
          if(chave[0] == '.'){//Vai para a esquerda
               if(raiz->esq == NULL) { //Se o filho da esquerda for nulo
                    raiz->esq = (nodo *)malloc(sizeof(nodo)); //Aloca o filho da esquerda
                    raiz->esq->val = '\0'; //Nome para indicar que o nodo está vazio
                    raiz->esq->esq = NULL;
                    raiz->esq->dir = NULL;
               }
               temp = insereNodo(raiz->esq, val, &chave[1]); //Chama recursiva, filho da esquerda é a nova raiz
          }
          else if(chave[0] == '-'){//Vai para a direita
               if(raiz->dir == NULL) {//Se o filho da direita for nulo
                    raiz->dir = (nodo *)malloc(sizeof(nodo));//Aloca o filho da direita
                    raiz->dir->val = '\0'; //Nome para indicar que o nodo está vazio
                    raiz->dir->esq = NULL;
                    raiz->dir->dir = NULL;
               }
               temp = insereNodo(raiz->dir, val, &chave[1]);//Chamada recursiva, filho da direita é a nova raiz
          }
     }
     else return raiz; //retorna a posição a ser inserido o nodo
     if(raiz->val == '!') {//Testa se o nodo é a raiz da arvore
          temp->val = val;
          sprintf(temp->chave, "%s", chave);
          return raiz;
     }
     return temp;
}

void imprimirArvore(nodo *raiz){ //Imprime a árvore em Pré-Ordem
     if(raiz != NULL){
          if(raiz->val != '\0' && raiz->val != '!'){ //Se o valor do nodo não for a raiz ou for nulo
               printf("%c ", raiz->val);
          }
          imprimirArvore(raiz->esq); //Chamada recursiva, filho da esquerda é a nova raiz
          imprimirArvore(raiz->dir); //Chamada recursiva, filho da direita é a nova raiz
     }
}
