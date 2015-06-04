#include "métodos.h"
#include "matrizes/matrizes.h"
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
	double g = 9.81, K1 = 100, K2 = 100, M1 = 1, M2 = 1, B1 = 10, step, epsilon;
	std::array<std::ResolvedorEDO*, numMetod> resolvedores;
	tnw::Vetor valIniciais = {1,0,1,0,g};
	tnw::MatrizQuadrada sistemaEq = {
									{0,1,0,0,0},
									{-(K1+K2)/M1, -B1/M1, K2/M1, 0, 0},
									{0,0,0,1,0},
									{K2/M2, 0, K2/M2, 0, 1},
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
			resolvedores[0] = new chp::ForwardEuler(sistemaEq, valIniciais, step);
			resolvedores[1] = new chp::BackwardEuler(sistemaEq, valIniciais, step, epsilon);
			resolvedores[2] = new chp::EulerModificado(sistemaEq, valIniciais, step, epsilon); 
			resolvedores[3] = new chp::RungeKutta(sistemaEq, valIniciais, step);
			resolvedores[4] = new chp::RungeKutta3(sistemaEq, valIniciais, step);
			resolvedores[5] = new chp::RungeKutta4(sistemaEq, valIniciais, step);
			resolvedores[6] = new chp::PreditorCorretor3(sistemaEq, valIniciais, step);
			resolvedores[7] = new chp::PreditorCorretor4(sistemaEq, valIniciais, step);
		}

		switch (metodo) {
			case FORW_EULER: {
				break;
			}
			case BACK_EULER: {
				break;
			}
			case EULER_MOD: {
				break;
			}
			case RUNGE_KUTTA: {
				break;
			}
			case RUNGE_KUTTA_3: {
				break;
			}
			case RUNGE_KUTTA_4: {
				break;
			}
			case PRED_CORR_3: {
				break;
			}
			case PRED_CORR_4: {
				break;
			}
			case SAIR: {
				std::cout << "Tchau!\n";
				feito = true;
				break;
			}
			case ANALISE_GERAL: {
				std::cout << "Informe o nome do arquivo de resultados: ";
				std::string arqNome;
				std::cin >> arqNome;
				
				for (int i=0; i<numMetod; i++){
					//Calculando para a medição do tempo
					auto tempoInicial = std::chrono::high_resolution_clock::now();
					tnw::Vetor resultado;
					resultado.aplicarMetodo(resolvedores[0], 20);
					auto tempoFinal = std::chrono::high_resolution_clock::now();
					int dif = std::chrono::duration_cast<std::chrono::milliseconds>(tempoFinal-tempoInicial).count();
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