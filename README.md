# final-metodos2
## Descrição do projeto
Resolver problemas de valor incial aplicado a um sistema massa-mola.
Sendo necessário implementação, relatório e apresentação.

<!-- Gambiarra para centralizar a imagem -->
<p align="center"><img src="./apresentação/enunciado.png"/></p>

Os métodos usados serão:

* Euler: forward, modificado e backward;
* Runge-Kutta: segunda, terceira e quarta ordem;
* Preditor-Corretor de Adams: terceira e quarta ordem.

## Implementação
A implementação dos métodos númericos será feita em C++11 e a visualização dos resultados será em Python2 usando a biblioteca Pygame.

## Relatório
O relatório contém a descrição do problema tratado, a descrição do que cada membro da equipe fez e a análise dos resultados que compare o tempo e a estabilidade dos diferentes métodos.

## Apresentação
A apresentação deve cobrir os mesmos tópicos do relatório e uma demonstração da implementação.

## Como usar
Compile o resolvedor de sistemas indo pra pasta `métodos` e execute o comando `make` nesta pasta.
Depois disso, execute o arquivo compilado em `bin/main`. Irá aparecer um menu e você escolhe o que
quer fazer.

Tenha certeza que as pastas `bin` e `lib` existem dentro da pasta `métodos`.

As opções com nomes de métodos irá executar aquele método e trazer o output para um arquivo que você pode
escolher o nome, o output são as coordenadas das duas massas.
Dado que o método executou e você tem esse arquivo, podemos agora visualizar a solução desse sistema.
Na pasta `visualização`, execute o visualizador com `python main.py <caminho para resultado>` ou então,
`./main.py <caminho para resultado>` se o arquivo tem permissão para ser executado.