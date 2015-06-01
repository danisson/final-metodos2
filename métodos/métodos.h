#include <functional>
#include "matrizes/matrizes.h"

namespace chp {
	typedef std::function<double(double,double)> equacaoDiferencial;
	typedef std::function<tnw::Vetor(tnw::Vetor)> funcaoReal;

	class ResolvedorEDO {
	protected:
		const tnw::MatrizQuadrada f;
		const tnw::Vetor y0;
		const double step;
	public:
		ResolvedorEDO(tnw::MatrizQuadrada f,tnw::Vetor y0,double step) : f(f), y0(y0),step(step) {};
		virtual tnw::Vetor operator()(double) = 0;
	};

	class ForwardEuler : ResolvedorEDO {
	public:
		ForwardEuler(tnw::MatrizQuadrada f,tnw::Vetor y0,double step) : ResolvedorEDO(f,y0,step) {};
		tnw::Vetor operator()(double);
	};

	class BackwardEuler : ResolvedorEDO {
	protected:
		const double epsilon;
	public:
		BackwardEuler(tnw::MatrizQuadrada f,tnw::Vetor y0,double step,double epsilon) : ResolvedorEDO(f,y0,step),epsilon(epsilon) {};
		tnw::Vetor operator()(double x);
	};

	class EulerModificado : ResolvedorEDO {
	protected:
		const double epsilon;
	public:
		EulerModificado(tnw::MatrizQuadrada f,tnw::Vetor y0,double step,double epsilon) : ResolvedorEDO(f,y0,step),epsilon(epsilon) {};
		tnw::Vetor operator()(double x);
	};

	// class RungeKutta : ResolvedorEDO {
	// public:
	// 	RungeKutta(equacaoDiferencial f,double y0,double step) : ResolvedorEDO(f,y0,step) {};
	// 	double operator()(double x);
	// };
	
	// class RungeKutta3 : ResolvedorEDO {
	// public:
	// 	RungeKutta3(equacaoDiferencial f,double y0,double step) : ResolvedorEDO(f,y0,step) {};
	// 	double operator()(double x);
	// };

	class RungeKutta4 : ResolvedorEDO {
	public:
		RungeKutta4(tnw::MatrizQuadrada f,tnw::Vetor y0,double step) : ResolvedorEDO(f,y0,step) {};
		tnw::Vetor operator()(double x);
	};

	// class PreditorCorretor3 : ResolvedorEDO {
	// public:
	// 	PreditorCorretor3(equacaoDiferencial f,double y0,double step) : ResolvedorEDO(f,y0,step) {};
	// 	double operator()(double x);
	// };

	// class PreditorCorretor4 : ResolvedorEDO {
	// public:
	// 	PreditorCorretor4(equacaoDiferencial f,double y0,double step) : ResolvedorEDO(f,y0,step) {};
	// 	double operator()(double x);
	// };

	tnw::Vetor pontoFixo(funcaoReal,double,tnw::Vetor);
}
