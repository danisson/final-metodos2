#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "hlibs/catch.hpp"
#include "métodos.h"
#include <cmath>


TEST_CASE("e^-x para x := 6 e step := 1e-4","[euler][backward]") {
	tnw::MatrizQuadrada F = {{-1,0},{0,-1}};

	const double step = 1e-4,
	             epsilon = 1e-1,
	             x = 6.0;

	const double y = 0.002478752176666;
	tnw::Vetor y0 = {1,1};

	auto forward = chp::ForwardEuler(F,y0,step);
	auto backward = chp::BackwardEuler(F,y0,step,epsilon);
	auto rForward = forward(x);
	auto rBackward = backward(x);

	REQUIRE(rForward(0) == Approx(y));
	REQUIRE(rBackward(1) == Approx(y));
}