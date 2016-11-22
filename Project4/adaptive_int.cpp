#include "fcn.hpp"
#include <cmath>

double composite_int(Fcn& f, const double a, 
			const double b, const int n);

int increment(int x)
{
	double w = 0.4;
	double xD = 0.4;
	double yD = 0;
	return (int) round(exp(w * x + xD) + yD);
}

int adaptive_int(Fcn& f, const double a, const double b, const double rtol, const double atol, double& R, int& n, int& Ntot)
{
	int startN = 10;

	int runCount = 1;

	while(startN <= 510)
	{
		double Rn = composite_int(f, a, b, startN);
		double RnIncr = composite_int(f, a, b, 10 * increment(runCount));

		if(std::abs(RnIncr - Rn) < rtol * std::abs(RnIncr) + atol)
		{
			R = RnIncr;
			n = startN;
			Ntot = runCount;
			return 0;
		}

		startN = 10 * increment(runCount);
		runCount ++;
	}
	return 1;
}