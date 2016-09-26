//Creating file
#include <iostream>
#include <cmath>
#include "fcn.hpp"

#ifndef NEWTON
#define NEWTON

class Newton{
public:
	double newton(Fcn& f, Fcn& df, double xStart, int maxit, double tol, bool show_iterates)
	{
		double x = xStart;
		double fx = f(x);
		for(int i = 0; i < maxit; i++)
		{
			double fp = df(x);
			if(fabs(fp) < pow(10, -9))
			{
				if(show_iterates)
					std::cout << "Too Small Derivative\n";
				break;
			}

			double d = (double)fx/(double)fp;
			//std::cout << "d=" << fabs(d) <<  "  :: tol=" << tol << "\n";
			x = x - d;
			fx = f(x);

			if(fabs(d) < tol)
			{
				if(show_iterates)
				{
					std::cout << "Convergence\n";
				}
				break;
			}

			if(show_iterates)
			{
				std::cout << "Iter=" << i << "  ::  x=" << x << "  ::  fx=" << fx << "\n";
			}
		}
		return x;
	}
};



#endif