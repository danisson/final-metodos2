#include <functional>
#include "matrizes/matrizes.h"

namespace chp {
	typedef std::function<tnw::Vetor(tnw::Vetor)> funcaoReal;

	class ResolvedorEDO {
	protected:
		const tnw::MatrizQuadrada f;
		const tnw::Vetor y0;
		const double step;
	public:
		ResolvedorEDO(tnw::MatrizQuadrada f,tnw::Vetor y0,double step) : f(f), y0(y0),step(step) {};
		virtual tnw::Vetor operator()(double) = 0;
		virtual ~ResolvedorEDO() {};
	};

	class ForwardEuler : public ResolvedorEDO {
	public:
		ForwardEuler(tnw::MatrizQuadrada f,tnw::Vetor y0,double step) : ResolvedorEDO(f,y0,step) {};
		tnw::Vetor operator()(double);
		virtual ~ForwardEuler() = default;
	};

	class BackwardEuler : public ResolvedorEDO {
	protected:
		const double epsilon;
	public:
		BackwardEuler(tnw::MatrizQuadrada f,tnw::Vetor y0,double step,double epsilon) : ResolvedorEDO(f,y0,step),epsilon(epsilon) {};
		tnw::Vetor operator()(double x);
		virtual ~BackwardEuler() = default;
	};

	class EulerModificado : public ResolvedorEDO {
	protected:
		const double epsilon;
	public:
		EulerModificado(tnw::MatrizQuadrada f,tnw::Vetor y0,double step,double epsilon) : ResolvedorEDO(f,y0,step),epsilon(epsilon) {};
		tnw::Vetor operator()(double x);
		virtual ~EulerModificado() = default;
	};

	class RungeKutta : public ResolvedorEDO {
	public:
		RungeKutta(tnw::MatrizQuadrada f,tnw::Vetor y0,double step) : ResolvedorEDO(f,y0,step) {};
		tnw::Vetor operator()(double x);
		virtual ~RungeKutta() = default;
	};
	
	class RungeKutta3 : public ResolvedorEDO {
	public:
		RungeKutta3(tnw::MatrizQuadrada f,tnw::Vetor y0,double step) : ResolvedorEDO(f,y0,step) {};
		tnw::Vetor operator()(double x);
		virtual ~RungeKutta3() = default;
	};

	class RungeKutta4 : public ResolvedorEDO {
	public:
		RungeKutta4(tnw::MatrizQuadrada f,tnw::Vetor y0,double step) : ResolvedorEDO(f,y0,step) {};
		tnw::Vetor operator()(double x);
		virtual ~RungeKutta4() = default;
	};

	class PreditorCorretor3 : public ResolvedorEDO {
	public:
		PreditorCorretor3(tnw::MatrizQuadrada f,tnw::Vetor y0,double step) : ResolvedorEDO(f,y0,step) {};
		tnw::Vetor operator()(double x);
		virtual ~PreditorCorretor3() = default;
	};

	class PreditorCorretor4 : public ResolvedorEDO {
	public:
		PreditorCorretor4(tnw::MatrizQuadrada f,tnw::Vetor y0,double step) : ResolvedorEDO(f,y0,step) {};
		tnw::Vetor operator()(double x);
		virtual ~PreditorCorretor4() = default;
	};

	tnw::Vetor pontoFixo(funcaoReal,double,tnw::Vetor);
}
