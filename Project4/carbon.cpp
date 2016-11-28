/* Project - Project 4
 * Professor - Dr. Xu
 * Author - Jake Rowland
 * Date - 12/1/2016
 * Purpose - Calculate carbon concentration
*/

#include "fcn.hpp"

#include <iostream>
#include <cmath>


//Integration function
class fcn : public Fcn {
public:
  	double operator()(double x) {   // function evaluation
    	return (exp(-pow(x,2)));
  	}
};

//Temperature-dependent diffusion coefficient
class fcnD : public Fcn {
public:
  	double operator()(double x) {   // function evaluation
  		double left = .00000062;
  		double top = 80000;
  		double bottom = 8.31 * x;
    	return (left * exp(-(top/bottom)));
  	}
};


int adaptive_int(Fcn& f, const double a, const double b, const double rtol, const double atol, double& R, int& n, int& Ntot);

//Error function
double erf(const double y, const double rtol, const double atol)
{
	//Define return values
	fcn f;
	double R;
	int n;
	int Ntot;

	//Get the integral of the error function
	int success = adaptive_int(f, 0, y, rtol, atol, R, n, Ntot);

	//If failed
	if(success == 1)
	{
		std::cout << "Error in calculating the erf derivative!\n";
	}
	//If successed
	else
	{
		//Multipy by constant
		R = 2.0/sqrt(M_PI) * R;
	}
	
	//Return r
	return R;
};

//Carbon diffusion function
double carbon(const double x, const double t, const double T, const double rtol, const double atol)
{
//	std::cout << "CARBON START\n";

	//Set constants
	double cInit = 0.001;
	double cGas  = 0.02;

	fcnD D;

//	std::cout << "C(x,t,T) = " << cGas << "(" << cGas << " - " << cInit << ")erf((" << x << ")/(sqrt(4 * " << t << " * D(" << T << ")))\n\n";
//	std::cout << "erf(y) = (2)/(sqrt(PI)) * \\int_{0}^{y} e^{-z^{2}}dz\n\n";
//	std::cout << "D(T) = 0.00000062 exp(-(80000)/(8.31 * " << T <<"))\n";

	//Get temperatue-dependent coefficient
	double dt = D(T);

	//Get y for erf(y)
	double y = x/sqrt(4 * t * dt);

	//Get erf(y)
	double erfy = erf(y, rtol, atol);

//	std::cout << "D(" << T << ") = " << dt << "\n";
//	std::cout << "erf(" << y << ") = (2)/(sqrt(PI)) * \\int_{0}^{" << y << "} e^{-z^{2}}dz = " << erfy <<"\n";

	//Get diffusion of carbon
	double val = cGas - (cGas - cInit) * erfy;

//	std::cout << "C(" << x << "," << t << "," << T << ") = " << cGas << "(" << cGas << " - " << cInit << ") * "<< erfy <<  " = "  << val << "\n\n\n";

	//Return diffusion
	return val;
};