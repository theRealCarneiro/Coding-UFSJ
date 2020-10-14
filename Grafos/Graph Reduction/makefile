Grafo:	pilha.o	lista.o	grafo.o	main.o
	gcc pilha.o lista.o grafo.o main.o -o Grafo 
	rm -rf *.o
grafo.o:	grafo.c
	gcc -c grafo.c
lista.o:	lista.c
	gcc -c lista.c
pilha.o:	pilha.c
	gcc -c pilha.c
main.o:	main.c
	gcc -c main.c
clean:
	rm -rf *.o Grafo
