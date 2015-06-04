#include "métodos.h"
#include "matrizes/matrizes.h"
#include <string>
#include <iostream>
#include <memory>

int main(int argc, char const *argv[])
{
	enum Opcao {FORW_EULER, BACK_EULER, EULER_MOD, RUNGE_KUTTA, RUNGE_KUTTA_3, RUNGE_KUTTA_4, PRED_CORR_3, PRED_CORR_4, SAIR};
	std::string opcaoName[] = {"Forward Euler", "Backward Euler", "Euler Modificado", "Runge Kutta Segunda Ordem", "Runge Kutta Terceira Ordem", "Runge Kutta Quarta Ordem", "Preditor Corretor Terceira Ordem", "Preditor Corretor Quarta Ordem", "Sair"};
	bool feito = false;
	int metodo;
	chp::ResolvedorEDO* resolvedor = nullptr;
	double g = 9.81, K1 = 100, K2 = 100, M1 = 1, M2 = 1, B1 = 10, step;
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
		for (int i = FORW_EULER; i <= SAIR; i++){
			std::cout << "(" << i << ")" << opcaoName[i] << "\n"; 
		} 	
		std::cin >> metodo;
		if (metodo!=SAIR){
			std::cout << "Informe o passo do método: ";
			std::cin >> step;
		}

		switch (metodo) {
			case FORW_EULER: {
				resolvedor = new chp::ForwardEuler(sistemaEq, valIniciais, step);
				break;
			}
			case BACK_EULER: {
				double epsilon;
				std::cout << "Informe a precisão do ponto fixo: ";
				std::cin >> epsilon;
				resolvedor = new chp::BackwardEuler(sistemaEq, valIniciais, step, epsilon);
				break;
			}
			case EULER_MOD: {
				double epsilon;
				std::cout << "Informe a precisão do ponto fixo: ";
				std::cin >> epsilon;
				resolvedor = new chp::EulerModificado(sistemaEq, valIniciais, step, epsilon);
				break;
			}
			case RUNGE_KUTTA: {
				resolvedor = new chp::RungeKutta(sistemaEq, valIniciais, step);
				break;
			}
			case RUNGE_KUTTA_3: {
				resolvedor = new chp::RungeKutta3(sistemaEq, valIniciais, step);
				break;
			}
			case RUNGE_KUTTA_4: {
				resolvedor = new chp::RungeKutta4(sistemaEq, valIniciais, step);
				break;
			}
			case PRED_CORR_3: {
				resolvedor = new chp::PreditorCorretor3(sistemaEq, valIniciais, step);
				break;
			}
			case PRED_CORR_4: {
				resolvedor = new chp::PreditorCorretor4(sistemaEq, valIniciais, step);
				break;
			}
			case SAIR: {
				std::cout << "Tchau!\n";
				feito = true;
				break;
			}
			default: {
				std::cout << "Opção incorreta!\n";
				break;
			}
		}
	}
	delete resolvedor;

	return 0;
}