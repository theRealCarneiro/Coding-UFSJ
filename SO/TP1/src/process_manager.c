#include "../headers/process_manager.h"

int main() {
	/*system("clear");*/
	char string;
	CPU *c = malloc(sizeof(CPU));
	*c = cria_processo("init");
	insere_pcb(c);
	executando = c;
	do {
		scanf("%c", &string);
		switch(string){
			case 'Q':
				if(executando->contador <= executando->tamanho - 1 || estado_pronto != NULL)
					executa_processo();
				break;
			case 'U':
				if(estado_bloqueado != NULL)
					desbloqueia_processo();
				break;
			case 'P':
				/*system("clear");*/
				reporter();
				break;
			case 'T':
				/*system("clear");*/
				reporter();
				break;
		}
		
		fflush(stdout);
	} while(string != 'T');

}

/*Printa informações basicas sobre o processo*/
void printa_processo(tabela_pcb *p){
	printf("pid: %d ppid: %d ",p->pid,p->ppid);
	/*printa_comando(p.programa->processo[0]);*/
}

/*Insere um processo na tabela PCB*/
void insere_pcb(CPU *c){
	/*Se a tabela pcb estiver vazia, iserir na posição 0*/
	if(pcb_list == NULL){
		pcb_list = (array_list*)malloc(sizeof(array_list));
		pcb_list->pcb = (tabela_pcb*)malloc(sizeof(tabela_pcb) * TAMANHO_PCB);
		pcb_list->pcb[0].pid = 0;
		pcb_list->pcb[0].ppid = 0;
		pcb_list->pcb[0].programa = malloc(c->tamanho * sizeof(CPU));
		pcb_list->pcb[0].programa = c;
		pcb_list->pcb[0].contador = &(c->contador);
		pcb_list->pcb[0].tempo_inicio = tempo; 
		pcb_list->pcb[0].estado = 'E';
		pcb_list->pcb_atual = &(pcb_list->pcb[0]);
		pcb_list->tamanho = 1;
		return;
	}
	/*Se a tabela pcb estiver cheia, aumente o tamanho*/
	if(pcb_list->tamanho == TAMANHO_PCB * multiplicador_pcb){
		multiplicador_pcb++;
		pcb_list->pcb =realloc(pcb_list,sizeof(tabela_pcb)*TAMANHO_PCB*multiplicador_pcb);
	}

	/*Insere na primeira posição vazia*/
	pcb_list->pcb[pcb_list->tamanho].programa = malloc(sizeof(CPU) * c->tamanho);
	pcb_list->pcb[pcb_list->tamanho].programa = c;
	pcb_list->pcb[pcb_list->tamanho].pid = pcb_list->pcb[pcb_list->tamanho - 1].pid + 1;
	pcb_list->pcb[pcb_list->tamanho].ppid = pcb_list->pcb_atual->pid;
	pcb_list->pcb[pcb_list->tamanho].tempo_inicio = tempo; 
	pcb_list->pcb[pcb_list->tamanho].estado = 'E'; 
	pcb_list->pcb_atual = &(pcb_list->pcb[pcb_list->tamanho]);
	pcb_list->tamanho++;
}

/*Remove o processo que corresponde com o endereço */
/*da struct CPU usada como paramentro da função*/
void remove_pcb(CPU *c){
	int achou = 0;
	for(int i = 0; i < pcb_list->tamanho; i++){
		if(pcb_list->pcb[i].programa == c) {
			free(pcb_list->pcb[i].programa->processo); //Libera a memoria
			free(pcb_list->pcb[i].programa); //Libera a memoria
			achou = 1;
		}

		/*Faz com que todos elementos apos o elemento removido*/
		/*sejam movidos para o endereço da esquerda deles*/
		if(achou == 1)
			pcb_list->pcb[i] = pcb_list->pcb[i + 1];
	}
		

	if(achou)
		pcb_list->tamanho--;
}

/*Busca na tabela PCB pelo endereço de memoria da struct CPU*/
/*usada como parametro*/
tabela_pcb *busca_pcb(CPU *c){
	for(int i = 0; i < pcb_list->tamanho; i++)
		/*Verifica se o endereço é o mesmo*/
		if(pcb_list->pcb[i].programa == c)
			return &(pcb_list->pcb[i]);
	/*Se o processo não foi encontrado, retorne o processo atual*/
	return pcb_list->pcb_atual;
}

/*Apenas conta o numero de linhas no arquivo*/
int line_count(char *fileName){
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

/*Insere no fim da fila*/
void enfilera(fila **f, CPU *chave){
	fila *celula = (fila*)malloc(sizeof(fila));
	celula->chave = chave; 
	celula->prox = NULL;
	if(*f == NULL){
		*f = celula;
		return;
	}

	fila *temp = *f;
	while(temp->prox != NULL){
		temp = temp->prox;
	}
	temp->prox = celula;
}

/*Remove o primeiro da fila*/
fila *desenfilera(fila **f){
	if(*f == NULL)
		return NULL;

	fila *temp = *f;
	*f = temp->prox;
	temp->prox = NULL;
	return temp;
}

/*Printa a fila*/
void printa_fila(fila *f){
	fila *temp = f;
	while(temp != NULL){
		printf("%d ", temp->chave->chave);	
		temp = temp->prox;
	}
	printf("\n");
}

/*Printa o comando atual na tela*/
void printa_comando(programa p){
	if(p.comando != 'B' && p.comando != 'E')	
		printf("%c %s\n", p.comando, p.valor);	
	else	
		printf("%c\n", p.comando);	

}

/*Le um arquivo com o programa */
CPU cria_processo(char *prog){
	FILE *fp; //arquivo
     char *line = NULL; //recebe uma linha do arquivo
     size_t len = 0; //tamanho da linha
     ssize_t read;

     fp = fopen(prog, "r"); //Abre o arquivo no modo de leitura
     if (fp == NULL){
          printf("ERRO: ARQUIVO NÃO ENCONTRADO\n");
          exit(EXIT_FAILURE);
     }

	/*Cria a struct para guardar o programa*/
	CPU c;
	int num_linhas = line_count(prog);
	c.processo = (programa*)malloc(num_linhas * sizeof(programa));
	c.tamanho = num_linhas;
	c.chave = 0;
	c.contador = 0;
	c.tempo_atual = 0;
	c.tempo_total = 0;
	c.nome_arquivo = prog;

	int i,j = 0;
	/*Coloca o comando no char comando da struct processo e*/
	/*o argumento na string valor */
	while ((read = getline(&line, &len, fp)) != -1) { 
		c.processo[i].comando = line[0];	
		if(line[0] != 'B' && line[0] != 'E'){
			/*Calcula o numero de caracteres no argumento*/
			for(j = 2; line[j+1] != '\0' && line[j+1] != '\n'; j++); 
			/*aloca espaço para o argumento*/
			c.processo[i].valor = (char*)malloc(j * sizeof(char));
			memcpy(c.processo[i].valor, &line[2], j-1);
			c.processo[i].valor[j-1] = '\0';
		} else c.processo[i].valor = NULL;
		i++;
     }
	fclose(fp);
	return c;
}

/*Bloqueia o processo que esta em execução*/
void bloqueia_processo(){
	/*printa_comando(executando->processo[executando->contador]);*/
	executando->tempo_atual = 0;
	executando->contador++;
	pcb_list->pcb_atual->estado = 'B';
	enfilera(&estado_bloqueado, executando); //insere na fila de processos prontos
	CPU *c = desenfilera(&estado_pronto)->chave;
	troca_de_imagem(c);
}

/*Tira o primeir o processo na fila de bloqueados e */
/*coloca na fila de prontos*/
void desbloqueia_processo(){
	CPU *c = desenfilera(&estado_bloqueado)->chave; //remove o primeiro elemento na fila de bloqueados 
	enfilera(&estado_pronto, c); //insere na fila de processos prontos
}

/*Troca o processo que esta em execução pelo processo */
/*colocado como argumento*/
void troca_de_imagem(CPU *c){
	pcb_list->pcb_atual->estado = 'P';
	executando = c;
	pcb_list->pcb_atual = busca_pcb(executando);
	pcb_list->pcb_atual->estado = 'E';
}

/*Faz uma copia do processo em execução e insere na tabela PCB e */
/*substitui o processo em execução pelo novo processo criado*/
void troca_de_contexto(){
	CPU *c = malloc(sizeof(CPU));
	c->processo = malloc(sizeof(programa) * executando->tamanho);
	*c = *executando;
	c->tempo_atual = 0;
	insere_pcb(c);

	executando->tempo_atual = 0;
	executando->contador+=atoi(executando->processo[executando->contador].valor)+1; 
	enfilera(&estado_pronto,executando); //insere na fila de processos prontos
	troca_de_imagem(c);
	/*printa_comando(executando->processo[executando->contador]);*/
}

/*Substitui o processo em execução pelo primeiro processo na fila*/
/*de processos prontos caso a fila de prontos não esteja vazia*/
void escalona_processo(){
	if(estado_pronto != NULL){
		executando->tempo_atual = 0;
		if(executando->contador < executando->tamanho)
			enfilera(&estado_pronto, executando); //insere na fila de processos prontos
		CPU *c = desenfilera(&estado_pronto)->chave; //remove o primeiro processo na fila de prontos
		troca_de_imagem(c);
	}
}

/*Remove o processo da tabela PCB */
void encerra_processo(){
	remove_pcb(executando);
	/*Realiza o escalonamento caso tenha algum processo pronto */
	/*para ser executado*/
	if(estado_pronto != NULL){
		CPU *c = desenfilera(&estado_pronto)->chave;
		troca_de_imagem(c);
	} else{
		return;
	}
}

/*Printa o estado do sistema*/
void reporter(){
	tabela_pcb *a = busca_pcb(executando);
	printf("*****************************************************************************\n"
		  "Estado do sistema:\n"
		  "*****************************************************************************\n");
	printf("TEMPO ATUAL: %d\n",tempo);
	printf("PROCESSO EXECUTANDO:\n");
	printf("pid	ppid	valor	tempo inicio	CPU usada ate agora	nome processo\n");
	if(executando->contador < executando->tamanho)
		printf("%d\t%d	%d\t%d\t\t%d\t\t\t%s\n", a->pid,a->ppid,a->programa->chave,
			  a->tempo_inicio, a->programa->tempo_total, a->programa->nome_arquivo);
	printf("PROCESSO BLOQUEADOS:\n");
	fila *temp = estado_bloqueado;
	while(temp != NULL){
		a = busca_pcb(temp->chave);
		temp = temp->prox;
		printf("%d\t%d	%d\t%d\t\t%d\t\t\t%s\n", a->pid,a->ppid,a->programa->chave,
			  a->tempo_inicio, a->programa->tempo_total, a->programa->nome_arquivo);
	}
	printf("PROCESSO PRONTOS:\n");
	temp = estado_pronto;
	while(temp != NULL){
		a = busca_pcb(temp->chave);
		temp = temp->prox;
		printf("%d\t%d	%d\t%d\t\t%d\t\t\t%s\n", a->pid,a->ppid,a->programa->chave,
			  a->tempo_inicio, a->programa->tempo_total, a->programa->nome_arquivo);
	}
	printf("*****************************************************************************\n\n");
}

/*Substitui o codigo do processo em execução pelo codigo */
/*do processo no arquivo especificado na instrução R*/
void substitui_processo(){
	CPU *c = malloc(sizeof(CPU));
	*c = cria_processo(executando->processo[executando->contador].valor);
	executando = c;
	executando->tempo_total = 0;
	pcb_list->pcb_atual->programa = executando;
}

/*Interpreta o codigo do processo em execução*/
void executa_processo(){
	/*Caso o processo tente ser executado apos sua finalização*/
	if(executando->contador >= executando->tamanho - 1)
		escalona_processo();

	executando->tempo_total++;
	tempo++;
	switch(executando->processo[executando->contador].comando){
		case 'S':
			executando->chave = atoi(executando->processo[executando->contador].valor);
			/*printa_comando(executando->processo[executando->contador]);*/
			executando->tempo_atual++;
			break;
		case 'A':
			executando->chave += atoi(executando->processo[executando->contador].valor);
			/*printa_comando(executando->processo[executando->contador]);*/
			executando->tempo_atual++;
			break;
			break;
		case 'D':
			executando->chave -= atoi(executando->processo[executando->contador].valor);
			/*printa_comando(executando->processo[executando->contador]);*/
			executando->tempo_atual++;
			break;
			break;
		case 'B':
			bloqueia_processo();
			return;
		case 'E':
			encerra_processo();
			break;
		case	'F':
			troca_de_contexto();
			break;
		case	'R':
			substitui_processo();
			return;
	}
	executando->contador++;

	/*Realiza o escalonamento caso o processo em execução tenha*/
	/*terminado	sua fatia de tempo*/
	if(executando->tempo_atual >= TEMPO_PADRAO)
		escalona_processo();
}


