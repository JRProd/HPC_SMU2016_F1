//Creating file
#include <iostream>
#include <cmath>
#include "fcn.hpp"

#ifndef NEWTON
#define NEWTON

class Newton{
public:
	static double newton(Fcn& f, Fcn& df, double xStart, int maxit, double tol, bool show_iterates)
	{
		double x = xStart;
		double fx = f(x);
		for(int i = 0; i < maxit; i++)
		{
			double fp = df(x);
			if(std::abs(fp) < pow(10, -9))
			{
				if(show_iterates)
					std::cout << "Too Small Derivative\n";
				break;
			}

			double d = (double)fx/(double)fp;
			x = x - d;
			fx = f(x);

			if(std::abs(d) < tol)
			{
				if(show_iterates)
				{
					std::cout << "Convergence\n";
				}
				break;
			}

			if(show_iterates)
			{
				std::cout << "Iter=" << i << "  ::  x=" << x << "  ::  fx=" << fx << "  ::  fp=" << fp <<"\n";
			}
		}
		return x;
	}
};



#endif
