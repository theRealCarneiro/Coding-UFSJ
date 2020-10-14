
/* Pega o maior elemento do vetor */
int max(int *vetor, int tamanhoAmostra);

/* Faz análise combinatória sem repetição e resolve o problema com força bruta */
int forcaBruta(int solucao[], int tamanhoAmostra, int numElementosParaEscolher, int atual, int next, int *distancia, int min);

/* Arruma as distancias geradas pelo algoritmo de combianção */
int arrumaDistancia(int *combinacao, int *distancia, int numPlanetas);

/* Chama o algorimo de força bruta */
int *chamaForcaBruta(int rep, int *min);

/* Resolve o problema com programação dinâmica */
int programacaoDinamica(int **distancia, int i, int j, int recursos, int numPlanetas, int max, int min);

/* Retorna a distancia entre dois pontos/planetas */
int pegaDistancia(int **distancia, int i, int j);

/* Le os inputs e chama a função para resolver com programação dinâmica */
int *chamaProgramacaoDinamica(int rep, int *min);

/* Resolve o problema com um algoritmo guloso */
int algoritmoGuloso(int *distancia, int numPlanetas, int recursos);

/* Le os inputs e chama a função para resolver com algorimo guloso */
int *chamaAlgoritmoGuloso(int rep, int *min);
