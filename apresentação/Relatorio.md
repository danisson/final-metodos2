
#Trabalho de Métodos Numéricos II - Relatório
|Nome               |Matrícula|
|-------------------|---------|
|Carolina Herbster  | 354044  |
|Daniel Augusto     | 354047  |
|Heitor Oliveira    | 354065  |
|Mariana Fontenele  | 354081  |

## Introdução
O trabalho tem como objetivo aplicar conhecimentos adquiridos na cadeira de
Métodos Numéricos II em que cada equipe recebe um problema de valor inicial e
deve resolvê-lo implementando os métodos seguintes em C++:

* Euler: forward, modificado e backward;
* Runge-Kutta: segunda, terceira e quarta ordem;
* Preditor-Corretor de Adams: terceira e quarta ordem.

## Problema proposto

<p align="center"><img src="./enunciado.png"/></p>

Trata-se de um problema num sistema massa-mola em que o movimento das massas é
definido por duas equações diferenciais ordinárias de segunda ordem. Contudo,
os métodos estudados na disciplina só resolvem EDOs de primeira ordem, então
teve que ser feito uma adaptação no sistema, transformando ele de duas EDOs de
segunda ordem em quatro de primeira ordem.

## Implementação

A implementação dos métodos numéricos foi feita em C++11, contudo, para resolver
sistemas lineares de EDOs precisariamos de algumas classes envolvendo vetores e
matrizes. Felizmente, na disciplina de [Métodos Numéricos I][m1] já tinhamos
classes que representam essas estruturas e estas classes foram importadas com
leves modificações neste projeto.

Para organizar o trabalho em equipe, usamos a plataforma [Github][m2] e a
ferramenta de controle de versão [Git][git]. Isso facilitou muito o trabalho
concorrente de membros da equipe. Outra ferramenta que ajudou muito a
implementação foi a biblioteca [Catch][cth] que fornece uma interface simples
para a implementação de testes unitários, usando ela certos bugs foram
detectados mais cedo e de forma automatizada.

Sobre a estrutura das classes do trabalho, estamos representando cada método
como uma classe que herda de uma classe abstrata que indica o que um método
precisa ter e implementar. No caso, ela precisa ter a matriz que representa o
sistema linear, o valor do passo, um valor corrente e uma função que transforma
o valor corrente no próximo.

Ou seja, os métodos são "iteradores" que alteram seu estado a cada passo.
Já que essa interface é muito baixo-nível, foram criadas funções auxiliares
para o usuário comum usar. A interface de mais alto nível é uma função que
recebe um método e um valor para qual queremos avaliar a solução do sistema,
retornando o valor da solução naquele ponto.

Como foi altamente recomendado a existencia uma simulação que demonstrasse o
movimento do sistema, uma simulação foi implementada em Python2 utilizando a
biblioteca [PyGame][pg].

[m1]: https://github.com/danisson/final-metodos1 "Github do projeto anterior"
[m2]: https://github.com/danisson/final-metodos2 "Github do projeto atual"
[git]: http://en.wikipedia.org/wiki/Git_%28software%29 "Página do Wikipédia sobre git"
[cth]: https://github.com/philsquared/Catch "Github da biblioteca Catch"
[pg]: http://en.wikipedia.org/wiki/Pygame "Página do Wikipédia sobre Pygame"

##Divisão do trabalho
| Membro da Equipe 			| Parte do trabalho 										                   	|
|:--------------------------|:------------------------------------------------------------------------------|
| Carolina Herbster  		| Implementação do método Euler backward										|
|							| Implementação do método de Runge-Kutta de quarta ordem						|
|							| Implementação do método Preditor-Corretor de Adams de terceira e quarta ordem	|
|							| Implementação da visualização													|
|							| Implementação do menu															|
| Daniel Augusto Ramos		| Implementação do método Euler forward											|
|							| Implementação do método de Runge-Kutta de terceira ordem						|
|                           | Escrita do Relatório                                                          |
|							| Correção de bugs																|
| Heitor Oliveira			| Implementação do método Runge-Kutta de segunda ordem							|
|							| Implementação da visualização													|
| Mariana Fontenele Lopes	| Implementação do método Euler modificado										|
|							| Escrita do Relatório 															|

##Resultados e Análise
