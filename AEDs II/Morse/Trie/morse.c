#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include "morse.h"

nodo *criaMorse(nodo *raiz) { //Cria a arvore morse
     raiz = insereNodo(raiz, 'a', ".-");
     raiz = insereNodo(raiz, 'b', "-...");
     raiz = insereNodo(raiz, 'c', "-.-.");
     raiz = insereNodo(raiz, 'd', "-..");
     raiz = insereNodo(raiz, 'e', ".");
     raiz = insereNodo(raiz, 'f', "..-.");
     raiz = insereNodo(raiz, 'g', "--.");
     raiz = insereNodo(raiz, 'h', "....");
     raiz = insereNodo(raiz, 'i', "..");
     raiz = insereNodo(raiz, 'j', ".---");
     raiz = insereNodo(raiz, 'k', "-.-");
     raiz = insereNodo(raiz, 'l', ".-..");
     raiz = insereNodo(raiz, 'm', "--");
     raiz = insereNodo(raiz, 'n', "-.");
     raiz = insereNodo(raiz, 'o', "---");
     raiz = insereNodo(raiz, 'p', ".--.");
     raiz = insereNodo(raiz, 'q', "--.-");
     raiz = insereNodo(raiz, 'r', ".-.");
     raiz = insereNodo(raiz, 's', "...");
     raiz = insereNodo(raiz, 't', "-");
     raiz = insereNodo(raiz, 'u', "..-");
     raiz = insereNodo(raiz, 'v',  "...-");
     raiz = insereNodo(raiz, 'x', "-..-");
     raiz = insereNodo(raiz, 'w', ".--");
     raiz = insereNodo(raiz, 'y', "-.--");
     raiz = insereNodo(raiz, 'z', "--..");
     raiz = insereNodo(raiz, '0', "-----");
     raiz = insereNodo(raiz, '1', ".----");
     raiz = insereNodo(raiz, '2', "..---");
     raiz = insereNodo(raiz, '3', "...--");
     raiz = insereNodo(raiz, '4', "....-");
     raiz = insereNodo(raiz, '5', ".....");
     raiz = insereNodo(raiz, '6', "-....");
     raiz = insereNodo(raiz, '7', "--...");
     raiz = insereNodo(raiz, '8', "---..");
     raiz = insereNodo(raiz, '9', "----.");
     raiz = insereNodo(raiz, '+', ".-.-.");
     raiz = insereNodo(raiz, '=', "-...-");
     raiz = insereNodo(raiz, '/', "-..-.");
     return raiz;
} 

char *morseParaString(nodo* raiz, char *palavra){ //Converte código morse para alfanumerico
     if(palavra[0] != '\0' && palavra[0] != '\n'){ //Se o primeiro elemento for \0, significa que já percorremos todo o vetor
          if(palavra[0] == '.') { //Vai para a esquerda
               palavra = morseParaString(raiz->esq, &palavra[1]); //Chamada recursiva, filho da esquerda é a nova raiz e palavra = &palavra[1]
               if(raiz->val == '!'){ //Se for o primeiro nodo da arvore
                    morseParaString(raiz, &palavra[1]); //Chama recursiva
               }
          }
          else if(palavra[0] == '-') { //Vai para a direita
               palavra = morseParaString(raiz->dir, &palavra[1]); //Chamada recursiva, filho da direita é a nova raiz e palavra = &palavra[1]
               if(raiz->val == '!'){ //Se for o primeiro nodo da arvore
                    morseParaString(raiz, &palavra[1]); //Chama recursiva
               }
          }
          else if(palavra[0] == ' ') { //Se for um espaço, significa que terminamos de ler uma letra e estamos no nodo certo
               printf("%c", raiz->val);
               if(palavra[1] == '/'){ //Se o próximo char for / significa um espaço entre as palavras
                    printf(" "); //Printa um espaço na tela
                    return &palavra[2]; //retorna a posição depois de /
               }
               else return palavra;
          }
     }
     else if(raiz->val != '!' && raiz->val != '\0'){ //Se o nodo não for a raiz da arvore e nem vazio
          printf("%c", raiz->val);
     }
     return palavra;
}

void stringParaMorse(nodo *raiz, char *palavra){ //Convete um texto alfanumericopara para um texto morse
     if(palavra[0] != '\0' && palavra[0] != '\n'){
          charParaMorse(raiz, palavra[0]); //chama a função para converter cada char para morse
          stringParaMorse(raiz, &palavra[1]); //chamada recursiva
     } else printf("\n");
}

void charParaMorse(nodo *raiz, char val){ //Convete um char para uma chave morse
     if(raiz != NULL){//Se a raiz não for nula
          if(val == ' '){ //Se tiver um espaço entre as palavras
               printf("/ ");
          }
          else if(raiz->val == val) { //Se o elemento for encontrado
               printf("%s ", raiz->chave);
          }
          else {
               charParaMorse(raiz->esq, val); //Chamada recursiva, filho da esquerda vira a nova raiz
               charParaMorse(raiz->dir, val); //Chamada recursiva, filho da direita vira a nova raiz
          }
     }
}

void arquivoParaMorse(nodo *raiz){ //Lê de um arquivo e converte para código morse
     FILE *fp; //arquivo
     char *line = NULL; //recebe uma linha do arquivo
     size_t len = 0; //tamanho da linha
     ssize_t read;

     fp = fopen("alfanum.txt", "r"); //Abre o arquivo no modo de leitura
     if (fp == NULL){//em caso de erro
          printf("ERRO: ARQUIVO NÃO ENCONTRADO\n");
          exit(EXIT_FAILURE);
     }
     printf("alfanum.txt \n");
     while ((read = getline(&line, &len, fp)) != -1) { //Lê cada linha do arquivo separadamente e guarda na variavel line
          printf("Menssagem original: %s", line); //Imprime a menssagem original
          printf("Menssagem traduzida: ");
          stringParaMorse(raiz, line); //Chama a função de converter textos para código morse
     }
     fclose(fp);//fecha o arquivo
     if (line){
          free(line);
     }
}

void arquivoMorseParaString(nodo *raiz){ //Lê de um arquivo e converte para alfanumerico
     FILE *fp; //arquivo
     char *line = NULL; //recebe uma linha do arquivo
     size_t len = 0; //tamanho da linha
     ssize_t read;
     int i = 2; //contador para pular linhas

     fp = fopen("msg.txt", "r"); //Abre o arquivo no modo de leitura
     if (fp == NULL){
          printf("ERRO: ARQUIVO NÃO ENCONTRADO\n");
          exit(EXIT_FAILURE);
     }
     printf("msg.txt \n");
     while ((read = getline(&line, &len, fp)) != -1) { //Lê cada linha do arquivo separadamente e guarda na variavel line
          if(i % 2 == 0) { //Para pular uma linha no arquivo
               printf("Menssagem original: %s", line); //Imprime a menssagem original
               printf("Menssagem traduzida: ");
               morseParaString(raiz, line); //Chama a função de converter morse para alfanumerico
               printf("\n");
          }
          i++;
     }
     fclose(fp);//fecha o arquivo
     if (line){
          free(line);
     }
}
