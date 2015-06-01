#Trabalho de Métodos Numéricos II - Relatório
##Carolina Herbster - 354044
##Daniel Augusto Ramos - 354047
##Heitor Oliveira - 354065
##Mariana Fontenele Lopes - 354081

###O trabalho
O trabalho tem como objetivo aplicar conhecimentos adquiridos na cadeira de Métodos Numéricos II em que cada equipe recebe um problema de valor inicial e deve resolvê-lo implementando os métodos seguintes em C++:

* Euler: forward, modificado e backward;
* Runge-Kutta: segunda, terceira e quarta ordem;
* Preditor-Corretor de Adams: terceira e quarta ordem.

O problema proposto

<p align="center"><img src="./apresentação/enunciado.png"/></p>

Trata-se de um problema num sistema massa-mola em que o movimento das massas é definido por duas equações diferenciáveis ordinárias e nessas equações estão presentes alguns valores a serem utilizados nos cálculos. A implementação do trabalho foi feita em C++11 com algumas classes reaproveitadas do trabalho da disciplina de [métodos numéricos I](https://github.com/danisson/final-metodos1) e foi usado como controle de versão o [Git](https://github.com/danisson/final-metodos2).
como foi altamente recomendado se fazer uma simulação que demonstrasse o movimento do sistema, uma simulação foi implementada em Python2 utilizando a biblioteca Pygame.

###Divisão do trabalho
| Membro da Equipe 			| Parte do trabalho 										                   	|
|:--------------------------|:------------------------------------------------------------------------------|
| Carolina Herbster  		| Implementação do método Euler backward										|
|							| Implementação do método de Runge-Kutta de quarta ordem						|
|							| Implementação do método Preditor-Corretor de Adams de terceira e quarta ordem	|
|							| Implementação da visualização													|
| Daniel Augusto Ramos		| Implementação do método Euler forward											|
|							| Implementação do método de Runge-Kutta de terceira ordem						|
|							| Correção de bugs																|
| Heitor Oliveira			| Implementação do método Runge-Kutta de segunda ordem							|
|							| Implementação da visualização													|
| Mariana Fontenele Lopes	| Implementação do método Euler modificado										|
|							| Escrita do Relatório 															|

###Resultados e Análise
