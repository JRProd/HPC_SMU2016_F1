#include <iostream>
#include <fstream>
#include <cmath>
#include "newton.cpp"
#include "fcn.hpp"

class fnorm: public Fcn 
{
	double operator()(double x)
	{
		return pow(x, 2) * (x - 3) * (x + 2);
	}
};

class fderv: public Fcn 
{
	double operator()(double x)
	{
		return x * (4 * pow(x, 4) - 3 * x - 12); 
	}
};

int main ()
{
	std::cout << "STARTING PROJECT 2 - PART B \n\n";
	
	Newton proj2;
	double x0[3] = {-3, 1, 2};
	double e[3] = {pow(10, -1), pow(10, -5), pow (10, -9)};

	fnorm f1;
	fderv f2;

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			std::cout << "Using " << x0[i] << " to an error of " << e[j] << "\n";
			proj2.newton(f1, f2, x0[i], 50, e[j], true);
			std::cout << "\n\n";
		}
	}

}