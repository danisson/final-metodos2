#include "matrizes/matrizes.h"
#include <fstream>
#include <string>
#include "cstdio"
#include <iostream>
#ifndef UTILSH
#define UTILSH

namespace chp{
	class Printer {
	protected:
		std::ofstream arquivo;
		const double step;
	public:
		Printer(std::string arqNome,const double step) : arquivo(arqNome),step(step) {
			arquivo << step << std::endl;
		}
		void printVetor(tnw::Vetor v) {
			// printf("%s\n", v.toString().c_str());
			arquivo << v(0) << "," << v(2) << std::endl;
			//arquivo << v(1) << "," << v(3) << "\n";
		}
	};
}
#endif