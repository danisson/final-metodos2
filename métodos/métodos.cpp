#include "métodos.h"
#include <cassert>
#include <cmath>
#include <cstdio>

chp::ResolvedorEDO& chp::ForwardEuler::operator++() {
	y0 = y0 + step*f(y0);
	return *this;
}

chp::ResolvedorEDO& chp::BackwardEuler::operator++() {
	y0 = chp::pontoFixo([&](tnw::Vetor yn){return y0+step*f(yn);},epsilon,y0);
	return *this;
}

chp::ResolvedorEDO& chp::EulerModificado::operator++(){
	y0 = chp::pontoFixo([&](tnw::Vetor y1){return y0+(step/2)*(f(y1)+f(y0));},epsilon,y0);
	return *this;
}

chp::ResolvedorEDO& chp::RungeKutta::operator++(){
	tnw::Vetor k1, k2;

	k1 = step * f(y0);
	k2 = step * f(y0 + k1);
	y0 = y0 + (k1 + k2)/2;

	return *this;
}

chp::ResolvedorEDO& chp::RungeKutta3::operator++() {
	tnw::Vetor k[3];

	k[0] = step * f(y0);
	k[1] = step * f(y0 + k[0]/2);
	k[2] = step * f(y0 - k[0] + 2*k[1]);
	y0 = y0 + (k[0] + 4*k[1] + k[2])/6;

	return *this;
}

chp::ResolvedorEDO& chp::RungeKutta4::operator++() {
	tnw::Vetor k[4];

	k[0] = step * f(y0);
	k[1] = step * f(y0 + k[0]/3);
	k[2] = step * f(y0 + k[0]/3 + k[1]/3);
	k[3] = step * f(y0 + k[0] - k[1] + k[2]);
	y0 = y0 + (k[0] + 3*k[1] + 3*k[2] + k[3])/8;

	return *this;
}

chp::ResolvedorEDO& chp::PreditorCorretor3::operator++() {
	tnw::Vetor yProx, yDerivProx;

	//Predição
	yProx = y[2] + (step/12) * (23*yDeriv[2] - 16*yDeriv[1] + 5*yDeriv[0]);
	yDerivProx = f(yProx);

	//Correção
	yProx = y[2] + (step/12) * (5*yDerivProx + 8*yDeriv[2] - yDeriv[1]);
	yDerivProx = f(yProx);

	//Atualização
	y[0] = y[1];
	yDeriv[0] = yDeriv[1];
	y[1] = y[2];
	yDeriv[1] = yDeriv[2];

	y[2] = yProx;
	yDeriv[2] = yDerivProx;

	return *this;
}

chp::ResolvedorEDO& chp::PreditorCorretor4::operator++() {
	tnw::Vetor yProx, yDerivProx;

	//Predição
	yProx = y[3] + (step/24) * (55*yDeriv[3] - 59*yDeriv[2] + 37*yDeriv[1] - 9*yDeriv[0]);
	yDerivProx = f(yProx);

	//Correção
	yProx = y[3] + (step/24) * (9*yDerivProx + 19*yDeriv[3] - 5*yDeriv[2] + yDeriv[1]);
	yDerivProx = f(yProx);

	//Atualização
	y[0] = y[1];
	yDeriv[0] = yDeriv[1];
	y[1] = y[2];
	yDeriv[1] = yDeriv[2];
	y[2] = y[3];
	yDeriv[2] = yDeriv[3];

	y[3] = yProx;
	yDeriv[3] = yDerivProx;

	return *this;
}

tnw::Vetor chp::pontoFixo(funcaoReal f, double epsilon, tnw::Vetor x0) {
	tnw::Vetor x = x0;
	while(tnw::abs(f(x) - x) >= epsilon) {
		x = f(x);
	}
	return f(x);
}

tnw::Vetor chp::aplicarMetodo(chp::ResolvedorEDO& metodo, double x) {
	for (double i=0; fabs(x-i)>=metodo.step; i+=metodo.step) {
		++metodo;
	}
	return *metodo;
}

void chp::iterarMetodo(chp::ResolvedorEDO& metodo, std::function<void(tnw::Vetor)> f,double x) {
	for (double i=0; fabs(x-i)>=metodo.step; i+=metodo.step) {
		f(*metodo);
		++metodo;
		//f(*metodo);
	}
}
