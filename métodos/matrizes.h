#ifndef MATRIZES_H
#define MATRIZES_H
#include <initializer_list>
#include <vector>
#include <string>
#include <tuple>

namespace tnw
{
	class Vetor
	{
	private:
		unsigned tamanho;
		std::vector<double> v;
	public:
		double operator()(unsigned i) const;
		double& operator()(unsigned i);
		unsigned getTamanho() const;

		std::string toString() const;
		std::string toJSON() const;

		Vetor(unsigned n);
		Vetor(std::initializer_list<double> v);
	};

	class MatrizQuadrada
	{
	private:
		unsigned tamanho;
		std::vector<double> m;
	public:
		double operator()(unsigned i, unsigned j) const;
		double& operator()(unsigned i, unsigned j);
		unsigned getTamanho() const;

		std::tuple<MatrizQuadrada,MatrizQuadrada> DR() const;
		int testeLinhas() const;
		int testeSassenfeld() const;

		std::string toString() const;
		std::string toJSON() const;

		MatrizQuadrada(unsigned n);
		MatrizQuadrada(std::initializer_list<std::initializer_list<double>> m);
		MatrizQuadrada(std::initializer_list<Vetor> l);
		MatrizQuadrada(std::vector<Vetor> v);
	};

	double abs(const Vetor& v);
	MatrizQuadrada identidade(unsigned tamanho);
}

tnw::MatrizQuadrada operator* (const tnw::MatrizQuadrada& e,const tnw::MatrizQuadrada& d);
tnw::MatrizQuadrada operator+ (const tnw::MatrizQuadrada& e,const tnw::MatrizQuadrada& d);
tnw::MatrizQuadrada operator- (const tnw::MatrizQuadrada& e,const tnw::MatrizQuadrada& d);
bool operator==(const tnw::MatrizQuadrada& e,const tnw::MatrizQuadrada& d);

tnw::Vetor operator* (const tnw::MatrizQuadrada& m,const tnw::Vetor& v);
tnw::Vetor operator+ (const tnw::Vetor& e,const tnw::Vetor& d);
tnw::Vetor operator- (const tnw::Vetor& e,const tnw::Vetor& d);
bool operator==(const tnw::Vetor& e,const tnw::Vetor& d);

#endif