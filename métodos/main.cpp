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
	enum Opcao {FORW_EULER, BACK_EULER, EULER_MOD, RUNGE_KUTTA,
	            RUNGE_KUTTA_3, RUNGE_KUTTA_4, PRED_CORR_3,
	            PRED_CORR_4, ANALISE_GERAL,SAIR};

	std::string opcaoName[] = {"Forward Euler", "Backward Euler", "Euler Modificado",
	                           "Runge Kutta Segunda Ordem", "Runge Kutta Terceira Ordem",
	                           "Runge Kutta Quarta Ordem", "Preditor Corretor Terceira Ordem",
	                           "Preditor Corretor Quarta Ordem", "Análise de todos os métodos","Sair"};
	int metodo;
	const int numMetod = 8; //Número de métodos
	double step, epsilon;
	std::array<chp::ResolvedorEDO*, numMetod> resolvedores = {nullptr};

	tnw::Vetor valIniciais = {/* y1  = */   1 ,
	                          /* y1' = */   0 ,
	                          /* y2  = */   1 ,
	                          /* y2' = */   0 ,
	                          /* g   = */ 9.81};

	                                 /*         y1 , y1',  y2 , y2', g */
	tnw::MatrizQuadrada sistemaEq = {/* y1' */{   0,   1,    0,   0, 0},
	                                 /* y1''*/{-200, -10,  100,   0, 1},
	                                 /* y2' */{   0,   0,    0,   1, 0},
	                                 /* y2''*/{ 100,   0, -100,   0, 1},
	                                 /* g'  */{   0,   0,    0,   0, 0}};
	tnw::Vetor resultado;

	while (true){
		std::cout << "Bem-vindos à simulação de equações diferenciais!" << std::endl << "Selecione o método que você quer executar:" << std::endl;
		for (int i = FORW_EULER; i <= SAIR; i++)
			std::cout << "(" << i << ")" << opcaoName[i] << std::endl;
		std::cin >> metodo;

		if (metodo!=SAIR){
			std::cout << "Informe o passo do método: ";
			std::cin >> step;
			std::cout << "Informe a precisão do ponto fixo: ";
			std::cin >> epsilon;

			for (chp::ResolvedorEDO* r : resolvedores) delete r;

			resolvedores[FORW_EULER]    = new chp::ForwardEuler      (sistemaEq, valIniciais, step);
			resolvedores[BACK_EULER]    = new chp::BackwardEuler     (sistemaEq, valIniciais, step, epsilon);
			resolvedores[EULER_MOD]     = new chp::EulerModificado   (sistemaEq, valIniciais, step, epsilon);
			resolvedores[RUNGE_KUTTA]   = new chp::RungeKutta        (sistemaEq, valIniciais, step);
			resolvedores[RUNGE_KUTTA_3] = new chp::RungeKutta3       (sistemaEq, valIniciais, step);
			resolvedores[RUNGE_KUTTA_4] = new chp::RungeKutta4       (sistemaEq, valIniciais, step);
			resolvedores[PRED_CORR_3]   = new chp::PreditorCorretor3 (sistemaEq, valIniciais, step);
			resolvedores[PRED_CORR_4]   = new chp::PreditorCorretor4 (sistemaEq, valIniciais, step);
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
			case ANALISE_GERAL: {
				std::cout << "Informe a pasta que ficará os arquivos da análise: ";
				std::string nomePasta;
				std::cin >> nomePasta;
				std::string nomeTempos = nomePasta + "/tempos.csv";
				std::cout << "Será criado o arquivo tempos.csv na pasta " << nomePasta << std::endl;

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

				std::cout << "Informe o prefixo do arquivo para plotagem: ";
				std::string nomePontos;
				std::cin >> nomePontos;
				for (int i=0; i < numMetod; i++){
					std::fstream arqPontos(nomePasta + "/" + nomePontos + std::to_string(i) + ".csv", std::ios::out);
					if (arqPontos.is_open()) {
						arqPontos.precision(numeric_limits<double>::digits10 + 1);
						arqPontos << opcaoName[i] << std::endl;
						iterarMetodo(*resolvedores[i],[&](tnw::Vetor v){arqPontos << v(0) << std::endl;},20);
						arqPontos << std::endl;
					}
				}

				break;
			}
			case SAIR: {
				std::cout << "Tchau!\n";
				for (chp::ResolvedorEDO* r : resolvedores) delete r;
				goto fim;
			}
			default: {
				std::cout << "Opção incorreta!\n";
				break;
			}
		}
	}

	fim:
	return 0;
}
