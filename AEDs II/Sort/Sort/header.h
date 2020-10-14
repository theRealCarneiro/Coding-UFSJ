#define RANGE 100
#define WIN32_LEAN_AND_MEAN
long TAM;

typedef struct elemento{
  int chave;
  char a[50][50];
} elemento;

typedef struct benchmark {
  long int comp;
  long int mov;
  long int tempo;
} benchmark;

void preenche(elemento *listaElementos, int ordem);

void merge(elemento *listaElementos, int comeco, int meio, int fim, benchmark *bench);

benchmark callMergeSort(elemento *listaElementos, int comeco, int fim, benchmark *bench);

benchmark callQuickSort(elemento *listaElementos, int low, int high, benchmark *bench);

benchmark mergeSort(elemento *listaElementos, int rep);

benchmark quickSort(elemento *listaElementos, int rep);

benchmark insertionSort(elemento *listaElementos, int rep);

benchmark shellSort(elemento *listaElementos, int rep);

benchmark selectionSort(elemento *listaElementos, int rep);

benchmark heapSort(elemento *listaElementos, int rep);
