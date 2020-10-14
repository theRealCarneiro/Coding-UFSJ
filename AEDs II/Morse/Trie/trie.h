typedef struct nodo{
  char chave[6];
  char val;
  struct nodo *esq;
  struct nodo *dir;
} nodo;

typedef struct trie{
  nodo *raiz;
} trie;

nodo *inicializaNodo(nodo *raiz); //Inicializa a árvore 

nodo *insereNodo(nodo *raiz, char val, char chave[6]); //Insere novo elemento na árvore

void imprimirArvore(nodo *raiz); //Imprime a árvore em Pré-Ordem
