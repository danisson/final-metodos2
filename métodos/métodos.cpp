#include "métodos.h"
#include <cassert>
#include <cmath>
#include <cstdio>

tnw::Vetor chp::ForwardEuler::operator()(double x) {
	tnw::Vetor y = y0;
	for (double i = 0; fabs(x-i) >= step; i+=step) {
		y = y + step*f(y);
	}
	return y;
}

tnw::Vetor chp::BackwardEuler::operator()(double x) {
	// (yn+1)^0 = yn
	// (yn+1)^k = yn + step*f((yn+1)^k-1,x)
	tnw::Vetor y = y0;
	for (double i = 0; fabs(x-i) >= step; i+=step) {
		y = chp::pontoFixo([&](tnw::Vetor yn){return y+step*f(yn);},epsilon,y);
	}
	return y;
}

tnw::Vetor chp::EulerModificado::operator()(double x){
	tnw::Vetor yn1 = y0;
	for (double i=0; fabs(x-i) >= step; i+=step) {
		yn1 = chp::pontoFixo([&](tnw::Vetor yn2){return yn1+(step/2)*(f(yn2)+f(yn1));},epsilon,yn1);
	}
	return yn1;
}

tnw::Vetor chp::RungeKutta::operator()(double x){
	tnw::Vetor yn1 = y0, k1, k2;
	for (double i=0; fabs(x-i)>=step; i+=step){
		k1 = step * f(yn1);
		k2 = step * f(yn1 + k1);
		yn1 = yn1 + (k1 + k2)/2;
	}
	return yn1;
}

tnw::Vetor chp::RungeKutta3::operator()(double x) {
	tnw::Vetor y = y0, k[3] = {y,y,y};
	for (double i = 0; fabs(x-i) >= step; i+=step) {
		k[0] = step * f(y);
		k[1] = step * f(y + k[0]/2);
		k[2] = step * f(y - k[0] + 2*k[1]);
		y = y + (k[0] + 4*k[1] + k[2])/6;
	}
	return y;
}

tnw::Vetor chp::RungeKutta4::operator()(double x) {
	tnw::Vetor y = y0;
	tnw::Vetor k[4];

	for (double i = 0; fabs(x-i) >= step; i+=step) {
		k[0] = step * f(y);
		k[1] = step * f(y + k[0]/3); 
		k[2] = step * f(y + k[0]/3 + k[1]/3);
		k[3] = step * f(y + k[0] - k[1] + k[2]);
		y = y + (k[0] + 3*k[1] + 3*k[2] + k[3])/8;
	}

	return y;	
}

tnw::Vetor chp::PreditorCorretor3::operator()(double x) {
	tnw::Vetor yDeriv[4], y[4];
	double i = 0;
	
	y[0] = y0;
	yDeriv[0] = f(y[0]);
	
	y[1] = y[0] + step*f(y[0]);
	i += step;
	yDeriv[1] = f(y[1]);

	if (fabs(x-i) < step) {
		return y[1]; 
	}

	y[2] = y[1] + step*f(y[1]);
	i += step;
	yDeriv[2] = f(y[2]);

	if (fabs(x-i) < step) {
		return y[2]; 
	}
 
	while (fabs(x-i) >= step) {
		//Predição
		y[3] = y[2] + (step/12) * (23*yDeriv[2] - 16*yDeriv[1] + 5*yDeriv[0]);
		i += step;
		yDeriv[3] = f(y[3]);

		//Correção
		y[3] = y[2] + (step/12) * (5*yDeriv[3] + 8*yDeriv[2] - yDeriv[1]);
		yDeriv[3] = f(y[3]);

		//Atualização
		for (int j = 0; j < 3; j++){
			y[j] = y[j+1];
			yDeriv[j] = yDeriv[j+1];
		}
	}

	return y[3]; 
}

tnw::Vetor chp::PreditorCorretor4::operator()(double x) {
	tnw::Vetor yDeriv[5], y[5];
	double t = 0;
	
	y[0] = y0;
	yDeriv[0] = f(y[0]);
 
	for (int j = 1; j < 4; j++){
		y[j] = y[j-1] + step*f(y[j-1]);
		t += step;
		yDeriv[j] = f(y[j]);

		if (fabs(x-t) < step) {
			return y[j];
		} 
	}

	while (fabs(x-t) >= step) {
		//Predição
		y[4] = y[3] + (step/24) * (55*yDeriv[3] - 59*yDeriv[2] + 37*yDeriv[1] - 9*yDeriv[0]);
		t += step;
		yDeriv[4] = f(y[4]);

		//Correção
		y[4] = y[3] + (step/24) * (9*yDeriv[4] + 19*yDeriv[3] - 5*yDeriv[2] + yDeriv[1]);
		yDeriv[4] = f(y[4]);

		//Atualização
		for (int j = 0; j < 4; j++){
			y[j] = y[j+1];
			yDeriv[j] = yDeriv[j+1];
		}
	}

	return y[4]; 
}

tnw::Vetor chp::pontoFixo(funcaoReal f, double epsilon, tnw::Vetor x0) {
	tnw::Vetor x = x0;
	while(tnw::abs(f(x) - x) >= epsilon) {
		x = f(x);
	}
	return f(x);
}
