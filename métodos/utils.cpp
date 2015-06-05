#include "utils.h"
#include "matrizes/matrizes.h"
#include <fstream>
#include <string>


chp::Printer::Printer(std::string arqNome){
	std::fstream newArq(arqNome, std::ios::app);
	if (newArq.is_open()){
		this->arquivo = newArq;
	}
}
void chp::Printer::printVetor(tnw::Vetor v){
	newArq << v(1) << "," << v(3) << "\n";
}