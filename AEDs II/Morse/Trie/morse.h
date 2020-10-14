#define TRUE 1
#define FALSE 0

nodo *criaMorse(nodo *raiz); //Cria a arvore morse

char *morseParaString(nodo* raiz, char *palavra); //Converte código morse para alfanumerico 

void stringParaMorse(nodo *raiz, char *palavra); //Convete um texto alfanumericopara para um texto morse

void charParaMorse(nodo *raiz, char val); //Convete um char para uma chave morse

void arquivoParaMorse(nodo *raiz); //Lê de um arquivo e converte para código morse

void arquivoMorseParaString(nodo *raiz); //Lê de um arquivo e converte para alfanumerico
