#include "matrizes/matrizes.h"
#include <fstream>
#include <string>
#include <cstdio>
#include <iostream>
#include <limits>

#ifndef UTILSH
#define UTILSH

using std::numeric_limits;

namespace chp{
	class Printer {
	protected:
		std::ofstream arquivo;
		const double step;
	public:
		Printer(std::string arqNome,const double step) : arquivo(arqNome),step(step) {
			arquivo << step << std::endl;
			arquivo.precision(numeric_limits<double>::digits10 + 1);
		}
		void printVetor(tnw::Vetor v) {
			arquivo << v(0) << "," << v(2) << std::endl;
		}
	};
}
#endif