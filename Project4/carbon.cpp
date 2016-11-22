#include "fcn.hpp"

#include <iostream>
#include <cmath>


class fcn : public Fcn {
public:
  	double operator()(double x) {   // function evaluation
    	return (exp(-pow(x,2)));
  	}
};

class fcnD : public Fcn {
public:
  	double operator()(double x) {   // function evaluation
  		double left = .00000062;
  		double top = 8000;
  		double bottom = 8.31 * x;
    	return (left * exp(-(top/bottom)));
  	}
};


int adaptive_int(Fcn& f, const double a, const double b, const double rtol, const double atol, double& R, int& n, int& Ntot);

double erf(const double y, const double rtol, const double atol)
{
	fcn f;
	double R;
	int n;
	int Ntot;
	int success = adaptive_int(f, 0, y, rtol, atol, R, n, Ntot);

	if(success == 1)
	{
		std::cout << "Error in calculating the erf derivative!\n";
	}
	else
	{
		R = 2.0/sqrt(M_PI) * R;
	}

//	std::cout << "R : " << R << "\n";
	
	return R;
};

double carbon(const double x, const double t, const double T, const double rtol, const double atol)
{
	double cInit = 0.001;
	double cGas  = 0.02;

	fcnD D;

	double y = x/sqrt(4 * t * D(T));
	double yVal = erf(y, rtol, atol);

//	std::cout << "D(" << T <<") :: " << D(T);
//	std::cout << "yVal :: " << yVal << "\n";

	double val = cGas - (cGas - cInit) * yVal;

//	std::cout << "val :: " << val;

	return val;
};