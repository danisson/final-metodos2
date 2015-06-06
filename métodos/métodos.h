#include <functional>
#include "matrizes/matrizes.h"

namespace chp {
	typedef std::function<tnw::Vetor(tnw::Vetor)> funcaoReal;

	class ResolvedorEDO {
	protected:
		const tnw::MatrizQuadrada f;
		tnw::Vetor y0;
	public:
		const double step;

		ResolvedorEDO(tnw::MatrizQuadrada f,tnw::Vetor y0,double step) : f(f), y0(y0),step(step) {};
		virtual ~ResolvedorEDO() {};
		virtual tnw::Vetor operator*() {return y0;}
		virtual ResolvedorEDO& operator++() = 0;
		virtual void setInicio(tnw::Vetor v) {y0 = v;}
	};

	class ForwardEuler : public ResolvedorEDO {
	public:
		ForwardEuler(tnw::MatrizQuadrada f,tnw::Vetor y0,double step) : ResolvedorEDO(f,y0,step) {};
		virtual ~ForwardEuler() = default;
		virtual ResolvedorEDO& operator++();
	};

	class BackwardEuler : public ResolvedorEDO {
	protected:
		const double epsilon;
	public:
		BackwardEuler(tnw::MatrizQuadrada f,tnw::Vetor y0,double step,double epsilon) : ResolvedorEDO(f,y0,step),epsilon(epsilon) {};
		virtual ~BackwardEuler() = default;
		virtual ResolvedorEDO& operator++();
	};

	class EulerModificado : public ResolvedorEDO {
	protected:
		const double epsilon;
	public:
		EulerModificado(tnw::MatrizQuadrada f,tnw::Vetor y0,double step,double epsilon) : ResolvedorEDO(f,y0,step),epsilon(epsilon) {};
		virtual ~EulerModificado() = default;
		virtual ResolvedorEDO& operator++();
	};

	class RungeKutta : public ResolvedorEDO {
	public:
		RungeKutta(tnw::MatrizQuadrada f,tnw::Vetor y0,double step) : ResolvedorEDO(f,y0,step) {};
		virtual ~RungeKutta() = default;
		virtual ResolvedorEDO& operator++();
	};
	
	class RungeKutta3 : public ResolvedorEDO {
	public:
		RungeKutta3(tnw::MatrizQuadrada f,tnw::Vetor y0,double step) : ResolvedorEDO(f,y0,step) {};
		virtual ~RungeKutta3() = default;
		virtual ResolvedorEDO& operator++();
	};

	class RungeKutta4 : public ResolvedorEDO {
	public:
		RungeKutta4(tnw::MatrizQuadrada f,tnw::Vetor y0,double step) : ResolvedorEDO(f,y0,step) {};
		virtual ~RungeKutta4() = default;
		virtual ResolvedorEDO& operator++();
	};

	class PreditorCorretor3 : public ResolvedorEDO {
	protected:
		tnw::Vetor y[3];
		tnw::Vetor yDeriv[3];
	public:
		PreditorCorretor3(tnw::MatrizQuadrada f,tnw::Vetor y0,double step) : ResolvedorEDO(f,y0,step) {
			y[0] = y0;
			yDeriv[0] = f(y[0]);

			y[1] = y[0] + step*f(y[0]);
			yDeriv[1] = f(y[1]);

			y[2] = y[1] + step*f(y[1]);
			yDeriv[2] = f(y[2]);
		};
		virtual tnw::Vetor operator*() {return y[0];}
		virtual ResolvedorEDO& operator++();
	};

	class PreditorCorretor4 : public ResolvedorEDO {
	protected:
		tnw::Vetor y[4];
		tnw::Vetor yDeriv[4];
	public:
		PreditorCorretor4(tnw::MatrizQuadrada f,tnw::Vetor y0,double step) : ResolvedorEDO(f,y0,step) {
			y[0] = y0;
			yDeriv[0] = f(y[0]);

			for (int j = 1; j < 4; j++){
				y[j] = y[j-1] + step*f(y[j-1]);
				yDeriv[j] = f(y[j]);
			}
		};
		virtual tnw::Vetor operator*() {return y[0];}
		virtual ResolvedorEDO& operator++();
	};

	tnw::Vetor pontoFixo(funcaoReal,double,tnw::Vetor);
	tnw::Vetor aplicarMetodo(ResolvedorEDO&,double x);
	void iterarMetodo(ResolvedorEDO&,std::function<void(tnw::Vetor)>,double);
}
