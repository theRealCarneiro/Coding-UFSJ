#include <stdio.h>
#include "trie.h"
#include "morse.h"

void main(){
     nodo *arvore;
     arvore = inicializaNodo(arvore);
     arvore = criaMorse(arvore);
     
     arquivoMorseParaString(arvore);
     printf("\n");
     arquivoParaMorse(arvore);
     printf("\n");
     imprimirArvore(arvore);
     printf("\n");
}
