#include "matrizes.h"
#include <stdexcept>
#include <cmath>

using tnw::Vetor;
using tnw::MatrizQuadrada;

// Matrizes
MatrizQuadrada operator* (const MatrizQuadrada& e,const MatrizQuadrada& d) {
	if (e.getTamanho() != d.getTamanho()) throw std::domain_error("Matrizes de dimensão errada");
	unsigned n = e.getTamanho();
	MatrizQuadrada o(n);
	for (unsigned i = 0; i < n; ++i)
		for (unsigned j = 0; j < n; ++j)
			for (unsigned k = 0; k < n; ++k)
				o(i,j)+=e(i,k)*d(k,j);
	return o;
}

tnw::MatrizQuadrada operator+ (const tnw::MatrizQuadrada& e,const tnw::MatrizQuadrada& d) {
	if (e.getTamanho() != d.getTamanho()) throw std::domain_error("Matrizes de dimensão errada");
	unsigned n = e.getTamanho();
	MatrizQuadrada o(n);
	for (unsigned i = 0; i < n; ++i)
		for (unsigned j = 0; j < n; ++j)
			o(i,j)=e(i,j)+d(i,j);
	return o;
}

tnw::MatrizQuadrada operator- (const tnw::MatrizQuadrada& e,const tnw::MatrizQuadrada& d) {
	if (e.getTamanho() != d.getTamanho()) throw std::domain_error("Matrizes de dimensão errada");
	unsigned n = e.getTamanho();
	MatrizQuadrada o(n);
	for (unsigned i = 0; i < n; ++i)
		for (unsigned j = 0; j < n; ++j)
			o(i,j)=e(i,j)-d(i,j);
	return o;
}

bool operator==(const MatrizQuadrada& e,const MatrizQuadrada& d) {
	if (e.getTamanho() != d.getTamanho()) throw std::domain_error("Matrizes de dimensão errada");
	unsigned n = e.getTamanho();
	for (unsigned i = 0; i < n; ++i)
		for (unsigned j = 0; j < n; ++j)
			if (e(i,j)!=d(i,j)) return false;
	return true;
}

tnw::Vetor tnw::MatrizQuadrada::operator()(tnw::Vetor v) const {
	return (*this) * v;
}

// Vetor

double tnw::abs(const Vetor& v) {
	unsigned n = v.getTamanho();
	double out=0;
	for (unsigned i = 0; i < n; ++i)
		out+= v(i)*v(i);
	return sqrt(out);
}

Vetor operator* (const MatrizQuadrada& m,const Vetor& v) {
	if (m.getTamanho() != v.getTamanho()) throw std::domain_error("Matrizes de dimensão errada");
	unsigned n = m.getTamanho();
	Vetor o(n);
	for (unsigned i = 0; i < n; ++i)
			for (unsigned k = 0; k < n; ++k)
				o(i)+=m(i,k)*v(k);
	return o;
}

tnw::Vetor operator+ (const tnw::Vetor& e,const tnw::Vetor& d) {
	if (e.getTamanho() != d.getTamanho()) throw std::domain_error("Matrizes de dimensão errada");
	unsigned n = e.getTamanho();
	Vetor o(n);
	for (unsigned i = 0; i < n; ++i)
		o(i)=e(i)+d(i);
	return o;
}

tnw::Vetor operator- (const tnw::Vetor& e,const tnw::Vetor& d) {
	if (e.getTamanho() != d.getTamanho()) throw std::domain_error("Matrizes de dimensão errada");
	unsigned n = e.getTamanho();
	Vetor o(n);
	for (unsigned i = 0; i < n; ++i)
		o(i)=e(i)-d(i);
	return o;
}

bool operator==(const Vetor& e,const Vetor& d) {
	if (e.getTamanho() != d.getTamanho()) throw std::domain_error("Matrizes de dimensão errada");
	unsigned n = e.getTamanho();
	for (unsigned i = 0; i < n; ++i)
			if (e(i)!=d(i)) return false;
	return true;
}

tnw::Vetor operator* (const double x,const tnw::Vetor& v) {
	tnw::Vetor r = v;
	for (unsigned i = 0; i < r.getTamanho(); ++i) {
		r(i) *= x;
	}
	return r;
}

tnw::Vetor operator* (const tnw::Vetor& v,const double x) {
	return x * v;
}

tnw::Vetor operator/ (const tnw::Vetor& v,const double x) {
	return v * (1/x);
}