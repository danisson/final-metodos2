# usando g++ como compilador
CC = g++

# compiler flags:
#  -g        adiciona informações de debug no executável
#  -Wall     ativa a maioria dos erros de compilação
#  -std=c+11 usa o standard mais recente
CFLAGS  = -g -Wall -std=c++11 -L lib

default: bin/main

bin/main: main.cpp bin/métodos.o lib/libmatriz.a utils.h
	$(CC) $(CFLAGS) main.cpp bin/métodos.o -o bin/main -lmatriz

main: bin/main
	bin/main

testar: bin/testes
	bin/testes -s --force-colour -d yes [euler] | less -Sr

testarMatriz: bin/testes
	bin/testes -s --force-colour -d yes [matriz] | less -Sr

bin/métodos.o: métodos.cpp métodos.h
	$(CC) $(CFLAGS) -c métodos.cpp -o bin/métodos.o

bin/testes: testes.cpp bin/métodos.o métodos.cpp hlibs/catch.hpp lib/libmatriz.a
	$(CC) $(CFLAGS) testes.cpp bin/métodos.o -o bin/testes -lmatriz

lib/libmatriz.a: matrizes/matrizes.h matrizes/matriz.cpp matrizes/vetor.cpp matrizes/operadores.cpp
	$(CC) $(CFLAGS) -c matrizes/matriz.cpp -o bin/matriz.o
	$(CC) $(CFLAGS) -c matrizes/vetor.cpp -o bin/vetor.o
	$(CC) $(CFLAGS) -c matrizes/operadores.cpp -o bin/operadores.o
	ar rvs lib/libmatriz.a bin/operadores.o bin/vetor.o bin/matriz.o
	rm bin/matriz.o bin/vetor.o bin/operadores.o