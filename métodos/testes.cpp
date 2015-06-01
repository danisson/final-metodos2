#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "hlibs/catch.hpp"
#include "métodos.h"
#include <cmath>


TEST_CASE("Vetor vazio recebe outros vetores","[matriz]") {
	tnw::Vetor v1, v2 = {1,2,3};
	v1 = v2;
	REQUIRE(v1 == v2);
}

TEST_CASE("Vetor não-vazio recebem outros vetores","[matriz]") {
	tnw::Vetor v1 = {1,2,4}, v2 = {1,2,3};
	v1 = v2;
	REQUIRE(v1 == v2);
}

TEST_CASE("e^-x para x := 6 e step := 1e-4","[euler][backward]") {
	tnw::MatrizQuadrada F = {{-1,0},{0,-1}};

	const double step = 1e-4,
	             epsilon = 1e-1,
	             x = 6.0;

	const double y = 0.002478752176666;
	tnw::Vetor y0 = {1,1};

	auto forward = chp::ForwardEuler(F,y0,step);
	auto backward = chp::BackwardEuler(F,y0,step,epsilon);
	auto modificado = chp::EulerModificado(F,y0,step,epsilon);
	auto rk4 = chp::RungeKutta4(F,y0,step);


	REQUIRE(forward(x)(0) == Approx(y));
	REQUIRE(backward(x)(0) == Approx(y));
	REQUIRE(modificado(x)(0) == Approx(y));
	REQUIRE(rk4(x)(0) == Approx(y));
}

TEST_CASE("y' = y+z; z' = z","[euler][backward]") {
	tnw::MatrizQuadrada F = {{1,1},{0,1}};

	const double step = 1e-6,
	             epsilon = 1e-1,
	             x = 6.0;

	const double y1 = 2824.001554449145;
	const double y2 = 403.4287934927351;
	tnw::Vetor y0 = {1,1};

	auto forward = chp::ForwardEuler(F,y0,step);
	auto backward = chp::BackwardEuler(F,y0,step,epsilon);
	auto modificado = chp::EulerModificado(F,y0,step,epsilon);
	auto rk4 = chp::RungeKutta4(F,y0,step);

	auto rforward = forward(x);
	// auto rbackward = backward(x);
	// auto rmodificado = modificado(x);
	// auto rrk4 = rk4(x);


	REQUIRE(rforward(0) == Approx(y1));
	REQUIRE(rforward(1) == Approx(y2));
}