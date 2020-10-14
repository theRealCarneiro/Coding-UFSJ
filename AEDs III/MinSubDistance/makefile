main:	main.o	ForcaBruta.o	AlgoritmoGuloso.o	ProgramacaoDinamica.o	Interface.o
	gcc main.o ForcaBruta.o AlgoritmoGuloso.o ProgramacaoDinamica.o Interface.o -o main
	make clean
main.o:	main.c
	gcc -c main.c
ForcaBruta.o:	ForcaBruta.c
	gcc -c ForcaBruta.c
AlgoritmoGuloso.o:	AlgoritmoGuloso.c
	gcc -c AlgoritmoGuloso.c
ProgramacaoDinamica.o:	ProgramacaoDinamica.c
	gcc -c ProgramacaoDinamica.c
Interface.o:	Interface.c
	gcc -c Interface.c
clean:
	rm -rf *.o
