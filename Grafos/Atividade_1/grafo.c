#include "grafo.h"

void kosaraju(grafo g){
	FILE *fp; //arquivo
     char *line = NULL; //recebe uma linha do arquivo
     size_t len = 0; //tamanho da linha
     ssize_t read;

     fp = fopen("subgrafos.txt", "w"); //Abre o arquivo no modo de leitura
     if (fp == NULL){
          printf("ERRO: ARQUIVO NÃO ENCONTRADO\n");
          exit(EXIT_FAILURE);
     }

	g.p = NULL;
	g.p = enchePilha(g, 0);
	for(int i = 0; i < g.numElementos; i++)
		g.visitado[i] = 0;
	printf("Componentes reduzidas por f* conexidade:\n");
	while(g.p != NULL){
		int v;
		g.p = desempilha(g.p, &v);
		if(!g.visitado[v]){
			dfs(g, v, fp);
			printf("\n");
			fprintf(fp, "\n");
		}
	}
     fclose(fp); //fecha o arquivo
}

pilha *enchePilha(grafo g, int i){
	int j;
	g.visitado[i] = 1;

	for(j = 0; j < g.numElementos; j++)
		if(!g.visitado[j] && g.matrixAdj[i][j] > 0)
			g.p = enchePilha(g, j);
	return empilha(g.p, i);
}

void dfs(grafo g, int i, FILE *fp){
	int j;
	printf("%d ",i);
	fprintf(fp, "%d ", i);
	g.visitado[i] = 1;

	for(j = 0; j < g.numElementos; j++)
		if(!g.visitado[j] && g.matrixAdj[j][i] > 0)
			dfs(g, j, fp);
}


void buscaProfundidadeListaAdj(grafo g, int i){
	lista *p;

	printf("%d\n", i);
	p = g.listaAdj[i];
	g.visitado[i] = 1;
	while(p != NULL) {
		i = p->chave;

		if(!g.visitado[i])
			buscaProfundidadeListaAdj(g, i);
		p = p->prox;
	}
}

void buscaProfundidadeMatrixAdj(grafo g, int i) {
	int j;
	printf("%d\n",i);
	g.visitado[i] = 1;

	for(j = 0; j < g.numElementos; j++)
		if(!g.visitado[j] && g.matrixAdj[i][j] > 0)
			buscaProfundidadeMatrixAdj(g, j);
}

grafo criaListaAdj(grafo g, int val[][3]){
	g.listaAdj = (lista**)malloc(g.numElementos * sizeof(lista*));
	for(int i = 0; i < g.numElementos; i++)
		g.listaAdj[i] = NULL;

	for(int i = 0; i < g.numArestas; i++)
		g.listaAdj[val[i][0]] = insereLista(g.listaAdj[val[i][0]], val[i][1], val[i][2]);	
	
	return g;
}

grafo criaMatrixAdj(grafo g, int val[][3]){
	g.matrixAdj = (int **)calloc(g.numElementos, sizeof(int*)); 
	for(int i = 0; i < g.numElementos; i++){
		g.matrixAdj[i] = (int *)calloc(g.numElementos, sizeof(int));
	}

	for(int i = 0; i < g.numArestas; i ++){
		g.matrixAdj[val[i][0]][val[i][1]] = val[i][2];	
	}
	return g;
}

void printaGrafo(grafo g){
	printf("\n  ");
	for(int i = 0; i < g.numElementos; i ++){
		printf("%c ", i + 65);
	}

	printf("\n");
	for(int i = 0; i < g.numElementos; i ++){
		for(int j = 0; j < g.numElementos; j ++){
			if(j == 0) printf("%c ", i + 65);
			printf("%d ",g.matrixAdj[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	for(int i = 0; i < g.numElementos; i++){
		printf("%d->",i);
		printaLista(g.listaAdj[i]);
	}

	printf("\n");
}

/*
grafo criaListaAdjPorMatrixAdj(grafo g){
	g.listaAdj = (lista_adj*)malloc(g.numElementos * sizeof(lista_adj));
	for(int i = 0; i < g.numElementos; i++){
		for(int j = 0; j < g.numElementos; j++){
			if(g.matrixAdj[i][j] != 0){
				if(!j)
					g.listaAdj[i].filhos = NULL;
				g.listaAdj[i].filhos = insereLista(g.listaAdj[i].filhos, j, g.matrixAdj[i][j]);
			}
		}
	}
	return g;
}*/


void printaSumario(grafo g){
	float densidade = (float)g.numArestas / ((float)g.numElementos * ((float)g.numElementos - 1.0));
	printf("Numero de vertices: %d\n", g.numElementos);
	printf("Numero de arestas: %d\n", g.numArestas);
	printf("Densidade: %.2f\n", densidade);
}


void grau(grafo g, int indice){
	int saida = 0;
	int entrada = 0;
	for (int i = 0; i < g.numElementos; i++){
		if(g.matrixAdj[indice][i] > 0){
			saida++;	
		}

		if(g.matrixAdj[i][indice] > 0){
			entrada++;	
		}
	}

	printf("Grau de saida do vertice %d: %d\n", indice, saida);
	printf("Grau de entrada do vertice %d: %d\n", indice, entrada);
}

void sucessores(grafo g, int indice){
	printf("Sucessores do vertice %d: ", indice);
	for (int i = 0; i < g.numElementos; i++){
		if(g.matrixAdj[indice][i] > 0){
			printf("%c ", i + 65);	
		}
	}
	printf("\n");
}

void antecessores(grafo g, int indice){
	printf("Antecessores do vertice %d: ", indice);
	for (int i = 0; i < g.numElementos; i++){
		if(g.matrixAdj[i][indice] > 0){
			printf("%c ", i + 65);	
		}
	}
	printf("\n");
}

int maxx(int a, int b, int max){
	if(a > b){
		if(a > max){
			return a;
		}
	} else if(a < b){
		if(b > max){
			return b;
		}
	}
	return max;
}

int lineCount(char *fileName){
	FILE *fp; //arquivo
	int numLinhas = 0;
	fp = fopen(fileName, "r"); //Abre o arquivo no modo de leitura
     if (fp == NULL){
          printf("ERRO: ARQUIVO NÃO ENCONTRADO\n");
          exit(EXIT_FAILURE);
     }

	char chr;
	chr = getc(fp);
	while (chr != EOF){
		if (chr == '\n' || chr == '\0'){
		   numLinhas++;	
		}
		chr = getc(fp);
	}
	return numLinhas;
}

grafo criaGrafo(){
	FILE *fp; //arquivo
     char *line = NULL; //recebe uma linha do arquivo
     size_t len = 0; //tamanho da linha
     ssize_t read;
	grafo g;

     fp = fopen("grafo.txt", "r"); //Abre o arquivo no modo de leitura
     if (fp == NULL){
          printf("ERRO: ARQUIVO NÃO ENCONTRADO\n");
          exit(EXIT_FAILURE);
     }
	int numLinhas = lineCount("grafo.txt");
	char temp[10];
	int max, k, i = 0;

	int val [numLinhas][3];		
	g.numArestas = numLinhas;

     for (numLinhas = 0; (read = getline(&line, &len, fp)) != -1; numLinhas++){ 
		for(int j = 0; line[j] != '\n' && line[j] != '\0'; j++){
			if(line[j] != ' ') {
				temp[k] = line[j];	
				k++;
				if(line[j + 1] == ' ' || line[j + 1] == '\n' || line[j + 1] == '\0'){
					temp[k] = '\0';
					k = 0;
					val[numLinhas][i] = atoi(temp);
					i++;
				}
			}
		}
		max = maxx(val[numLinhas][0], val[numLinhas][1], max); 
		i = 0;
     }
     fclose(fp); //fecha o arquivo
     if (line)
          free(line);
     
	g.numElementos = max + 1;
	g = criaMatrixAdj(g, val);
	g = criaListaAdj(g, val);
	g.visitado = calloc(g.numElementos, sizeof(int*));
	return g;
}
