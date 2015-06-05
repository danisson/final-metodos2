#include "métodos.h"
#include "matrizes/matrizes.h"
#include "utils.h"
#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include <chrono>
#include <array>

int main(int argc, char const *argv[])
{
	enum Opcao {FORW_EULER, BACK_EULER, EULER_MOD, RUNGE_KUTTA, RUNGE_KUTTA_3, RUNGE_KUTTA_4, PRED_CORR_3, PRED_CORR_4, SAIR, ANALISE_GERAL};
	std::string opcaoName[] = {"Forward Euler", "Backward Euler", "Euler Modificado", "Runge Kutta Segunda Ordem", "Runge Kutta Terceira Ordem", "Runge Kutta Quarta Ordem", "Preditor Corretor Terceira Ordem", "Preditor Corretor Quarta Ordem", "Sair", "Análise de todos os métodos"};
	bool feito = false;
	int metodo;
	const int numMetod = 8; //Número de métodos
	double g = 9.81, step, epsilon;
	std::array<chp::ResolvedorEDO*, numMetod> resolvedores;
	tnw::Vetor valIniciais = {1,0,1,0,g}, resultado;
	tnw::MatrizQuadrada sistemaEq = {{0,1,0,0,0},
	                                 {-200, -10, 100, 0, 1},
	                                 {0,0,0,1,0},
	                                 {100, 0, -100, 0, 1},
	                                 {0,0,0,0,0}
	                                };

	while (!feito){
		std::cout << "Bem-vindos à simulação de equações diferenciais! Selecione o método que você quer executar:\n";
		for (int i = FORW_EULER; i <= ANALISE_GERAL; i++){
			std::cout << "(" << i << ")" << opcaoName[i] << "\n"; 
		} 	
		std::cin >> metodo;
		if (metodo!=SAIR){
			std::cout << "Informe o passo do método: ";
			std::cin >> step;
			std::cout << "Informe a precisão do ponto fixo: ";
			std::cin >> epsilon;
			resolvedores[FORW_EULER] = new chp::ForwardEuler(sistemaEq, valIniciais, step);
			resolvedores[BACK_EULER] = new chp::BackwardEuler(sistemaEq, valIniciais, step, epsilon);
			resolvedores[EULER_MOD] = new chp::EulerModificado(sistemaEq, valIniciais, step, epsilon); 
			resolvedores[RUNGE_KUTTA] = new chp::RungeKutta(sistemaEq, valIniciais, step);
			resolvedores[RUNGE_KUTTA_3] = new chp::RungeKutta3(sistemaEq, valIniciais, step);
			resolvedores[RUNGE_KUTTA_4] = new chp::RungeKutta4(sistemaEq, valIniciais, step);
			resolvedores[PRED_CORR_3] = new chp::PreditorCorretor3(sistemaEq, valIniciais, step);
			resolvedores[PRED_CORR_4] = new chp::PreditorCorretor4(sistemaEq, valIniciais, step);
		}

		switch (metodo) {
			case FORW_EULER: {
				std::string arqNome;
				std::cout << "Digite o nome do arquivo de saída dos valores: ";
				std::cin >> arqNome;
				chp::Printer printer(arqNome,step);
				chp::iterarMetodo(*resolvedores[FORW_EULER], [&](tnw::Vetor x) {printer.printVetor(x);}, 20);
				break;
			}
			case BACK_EULER: {
				std::string arqNome;
				std::cout << "Digite o nome do arquivo de saída dos valores: ";
				std::cin >> arqNome;
				chp::Printer printer(arqNome,step);
				chp::iterarMetodo(*resolvedores[BACK_EULER], [&](tnw::Vetor x) {printer.printVetor(x);}, 20);
				break;
			}
			case EULER_MOD: {
				std::string arqNome;
				std::cout << "Digite o nome do arquivo de saída dos valores: ";
				std::cin >> arqNome;
				chp::Printer printer(arqNome,step);
				chp::iterarMetodo(*resolvedores[EULER_MOD], [&](tnw::Vetor x) {printer.printVetor(x);}, 20);
				break;
			}
			case RUNGE_KUTTA: {
				std::string arqNome;
				std::cout << "Digite o nome do arquivo de saída dos valores: ";
				std::cin >> arqNome;
				chp::Printer printer(arqNome,step);
				chp::iterarMetodo(*resolvedores[RUNGE_KUTTA], [&](tnw::Vetor x) {printer.printVetor(x);}, 20);
				break;
			}
			case RUNGE_KUTTA_3: {
				std::string arqNome;
				std::cout << "Digite o nome do arquivo de saída dos valores: ";
				std::cin >> arqNome;
				chp::Printer printer(arqNome,step);
				chp::iterarMetodo(*resolvedores[RUNGE_KUTTA_3], [&](tnw::Vetor x) {printer.printVetor(x);}, 20);
				break;
			}
			case RUNGE_KUTTA_4: {
				std::string arqNome;
				std::cout << "Digite o nome do arquivo de saída dos valores: ";
				std::cin >> arqNome;
				chp::Printer printer(arqNome,step);
				chp::iterarMetodo(*resolvedores[RUNGE_KUTTA_4], [&](tnw::Vetor x) {printer.printVetor(x);}, 20);
				break;
			}
			case PRED_CORR_3: {
				std::string arqNome;
				std::cout << "Digite o nome do arquivo de saída dos valores: ";
				std::cin >> arqNome;
				chp::Printer printer(arqNome,step);
				chp::iterarMetodo(*resolvedores[PRED_CORR_3], [&](tnw::Vetor x) {printer.printVetor(x);}, 20);
				break;
			}
			case PRED_CORR_4: {
				std::string arqNome;
				std::cout << "Digite o nome do arquivo de saída dos valores: ";
				std::cin >> arqNome;
				chp::Printer printer(arqNome,step);
				chp::iterarMetodo(*resolvedores[PRED_CORR_4], [&](tnw::Vetor x) {printer.printVetor(x);}, 20);
				break;
			}
			case SAIR: {
				std::cout << "Tchau!\n";
				feito = true;
				break;
			}
			case ANALISE_GERAL: {
				std::cout << "Informe o nome do arquivo de tempos: ";
				std::string nomeTempos;
				std::cin >> nomeTempos;

				std::fstream arqTempos(nomeTempos);
				if (arqTempos){
					//Arquivo já existe
					arqTempos.close();
					arqTempos.open(nomeTempos,std::ios::out | std::ios::app);
				} else {
					//Arqivo não existe
					arqTempos.open(nomeTempos,std::ios::out);
					arqTempos << "Nome Método, Tempo (ms), Step, Epsilon\n";
				}

				if (arqTempos.is_open()) {
					for (int i=0; i < numMetod; i++){
						//Calculando para a medição do tempo
						auto tempoInicial = std::chrono::high_resolution_clock::now();
						resultado = aplicarMetodo(*resolvedores[i], 20);
						auto tempoFinal = std::chrono::high_resolution_clock::now();
						int dif = std::chrono::duration_cast<std::chrono::milliseconds>(tempoFinal-tempoInicial).count();
						arqTempos << opcaoName[i] << "," << dif << "," << step << "," << epsilon << "\n";
					}
				}

				for (int i=0; i < numMetod; i++){
					resolvedores[i]->setInicio(valIniciais);
				}

				std::cout << "Informe o nome do arquivo para plot: ";
				std::string nomePontos;
				std::cin >> nomePontos;
				std::fstream arqPontos(nomePontos, std::ios::out);
				if (arqPontos.is_open()) {
					arqPontos << "Nome do Método,Pontos...\n";
					arqPontos.precision(numeric_limits<double>::digits10 + 1);
					auto f = [&](tnw::Vetor v) {arqPontos << "," << v(0);};
					for (int i=0; i < numMetod; i++){
						arqPontos << opcaoName[i];
						iterarMetodo(*resolvedores[i],f,20);
						arqPontos << std::endl;
					}
				}

				break;
			}
			default: {
				std::cout << "Opção incorreta!\n";
				break;
			}
		}
	}

	return 0;
}
