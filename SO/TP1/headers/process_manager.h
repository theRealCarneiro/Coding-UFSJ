#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAMANHO_PCB 100
#define TEMPO_PADRAO 3

typedef struct {
	char comando;
	char *valor;
}programa;

typedef struct{
	programa *processo;
	char *nome_arquivo;
	int tamanho;
	int chave;
	int contador;
	int tempo_total;
	int tempo_atual;
} CPU;

typedef struct{
	CPU *programa;
	int pid;
	int ppid;
	char estado;
	int *contador;
	int tempo_inicio;
} tabela_pcb;

typedef struct {
	tabela_pcb *pcb;
	int tamanho;
	tabela_pcb *pcb_atual;
}array_list;

typedef struct fila{
	CPU *chave;
	struct fila *prox;
} fila;

int tempo = 0;
CPU *executando;
fila *estado_pronto = NULL;
fila *estado_bloqueado = NULL;
array_list *pcb_list = NULL;
int multiplicador_pcb = 1;

void printa_processo(tabela_pcb *p);

void insere_pcb(CPU *c);

void remove_pcb(CPU *c);

tabela_pcb *busca_pcb(CPU *c);

int line_count(char *fileName);

void enfilera(fila **f, CPU *chave);

fila *desenfilera(fila **f);

void printa_fila(fila *f);

void printa_comando(programa p);

CPU cria_processo(char *prog);

void bloqueia_processo();

void desbloqueia_processo();

void troca_de_imagem(CPU *c);

void troca_de_contexto();

void escalona_processo();

void encerra_processo();

void reporter();

void substitui_processo();

void executa_processo();
