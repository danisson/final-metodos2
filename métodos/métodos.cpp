#include "métodos.h"
#include <cassert>
#include <cmath>
#include <cstdio>

double chp::ForwardEuler::operator()(double x) {
	double y = y0;
	for (double i = 0; fabs(x-i) >= step; i+=step) {
		y += step*f(y,i);
	}
	return y;
}

double chp::BackwardEuler::operator()(double x) {
	// (yn+1)^0 = yn
	// (yn+1)^k = yn + step*f((yn+1)^k-1,x)
	double y = y0;
	for (double i = 0; fabs(x-i) >= step; i+=step) {
		y = chp::pontoFixo([&](double yn){return y+step*f(yn,i+step);},epsilon,y);
	}
	return y;
}

double chp::EulerModificado::operator()(double x){
	double yn1 = y0;
	for (double i=0; fabs(x-i)>=step; i+=step) {
		yn1 = chp::pontoFixo([&](double yn2){return yn1+(step/2)*(f(yn2,i+step)+f(yn1,i));},epsilon,yn1);
	}
	return yn1;
}

double chp::pontoFixo(funcaoReal f, double epsilon, double x0) {
	double x = x0;
	while(fabs(f(x) - x) >= epsilon) {
		x = f(x);
	}
	return f(x);
}

double chp::RungeKutta::operator()(double x){
	double yn1 = y0, k1, k2;
	for (double i=0;fabs(x-i)>=step;i+=step){
		k1 = step*f(yn1,i);
		k2 = step*f(yn1+k1,i+step);
		yn1 = yn1 + (k1+k2)/2;
	} 
	return yn1;
}
