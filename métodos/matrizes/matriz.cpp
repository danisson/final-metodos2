#include "matrizes.h"
#include <stdexcept>
#include <limits>
#include <sstream>
#include <ios>

#define eu(i,j) m[i*tamanho + j]

using std::tuple;
using std::make_tuple;
using tnw::MatrizQuadrada;

double MatrizQuadrada::operator()(unsigned i, unsigned j) const {
if (i < tamanho && j <tamanho)
		return eu(i,j);
	throw std::out_of_range("Argumento fora do tamanho");
}
double& MatrizQuadrada::operator()(unsigned i, unsigned j) {
	if (i < tamanho && j <tamanho)
		return eu(i,j);
	throw std::out_of_range("Argumento fora do tamanho");
}

unsigned MatrizQuadrada::getTamanho() const {
	return tamanho;
}

tuple<MatrizQuadrada,MatrizQuadrada> MatrizQuadrada::DR() const {
	MatrizQuadrada d(tamanho),r(tamanho);

	for (unsigned i = 0; i < tamanho; ++i) {
		for (unsigned j = 0; j < tamanho; ++j) {
			if(i==j) d(i,i) = eu(i,i);
			else     r(i,j) = eu(i,j);
		}
	}

	return make_tuple(d,r);
}

int MatrizQuadrada::testeLinhas() const {
	double alfa;
	for (unsigned i = 0; i < tamanho; ++i)
	{
		alfa=0;
		for (unsigned j = 0; j < tamanho; ++j)
			if (j!=i) alfa += eu(i,j)/eu(i,i);
		if (alfa >= 1) return i;
	}
	return -1;
}

int MatrizQuadrada::testeSassenfeld() const {
	std::vector<double> beta;
	double aux=0;
	for (unsigned i = 1; i < tamanho; ++i)
		aux+=eu(0,i)/eu(0,0);
	if (aux >= 1) return 0;
	beta.push_back(aux);

	for (unsigned i = 1; i < tamanho; ++i)
	{
		aux=0;
		for (unsigned j = 0; j < tamanho; ++j)
			if (j!=i) aux += eu(i,j) * beta[j]/eu(i,i);
		if (aux >= 1) return i;
		beta.push_back(aux);
	}

	return -1;
}

std::string MatrizQuadrada::toString() const {
	std::string output,aux;
	for (unsigned i = 0; i < tamanho; ++i)
	{
		output += "[ ";
		for (unsigned j = 0; j < tamanho; ++j)
		{
			aux = std::to_string(eu(i,j));
			aux.erase(aux.find_last_not_of('0') + 1, std::string::npos);
			if(aux.back() == '.') aux.pop_back();
			output+= aux + " ";
		}
		output += "]\n";
	}
	return output;
}

std::string MatrizQuadrada::toJSON() const {
	std::stringstream output;
	output.precision(std::numeric_limits<double>::digits10+1);
	output << "[";
	for (unsigned i = 0; i < tamanho; ++i)
	{
		output << "[";
		for (unsigned j = 0; j < tamanho; ++j)
		{
			output << std::fixed << eu(i,j);
			if (j<tamanho-1) output << ",";
		}
		output << "]";
		if (i<tamanho-1) output << ",";
	}
	output << "]";
	return output.str();
}

MatrizQuadrada::MatrizQuadrada(unsigned n) {
	tamanho = n;
	for (unsigned i = 0; i < (n*n); ++i)
		m.push_back(0);
}

MatrizQuadrada::MatrizQuadrada(std::initializer_list<std::initializer_list<double>> l) {
	tamanho = l.size();
	for (auto linha : l)
	{
		if(linha.size() > tamanho) throw std::domain_error("Lista de dimensão errada");;
		m.insert(m.end(), linha.begin(), linha.end());
	}
}

MatrizQuadrada::MatrizQuadrada(std::initializer_list<tnw::Vetor> l) {
	tamanho = l.size();
	unsigned j=0;
	for (unsigned i = 0; i < (tamanho*tamanho); ++i) m.push_back(0);	
	for (auto coluna : l) {
		if(coluna.getTamanho() > tamanho) throw std::domain_error("Lista de dimensão errada");;
		for (unsigned i = 0; i < tamanho; ++i)
			eu(i,j) = coluna(i);
		j++;
	}
}

MatrizQuadrada::MatrizQuadrada(std::vector<tnw::Vetor> l) {
	tamanho = l.size();
	unsigned j=0;
	for (unsigned i = 0; i < (tamanho*tamanho); ++i) m.push_back(0);	
	for (auto coluna : l) {
		if(coluna.getTamanho() > tamanho) throw std::domain_error("Lista de dimensão errada");;
		for (unsigned i = 0; i < tamanho; ++i)
			eu(i,j) = coluna(i);
		j++;
	}
}

MatrizQuadrada tnw::identidade(unsigned tamanho){
	MatrizQuadrada m(tamanho);
	for (unsigned i = 0; i < tamanho; ++i)
		m(i,i)=1;
	return m;
}