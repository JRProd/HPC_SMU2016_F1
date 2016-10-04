/* Project - Project 2_Part b
 * Prof - Dr Xu
 * Name - Jake Rowland
 * Date - 10/6/16
 * Purpuse - Use Newton's method of root finding
*/

#include <iostream>
#include <cmath>
#include "fcn.hpp"

#ifndef NEWTON
#define NEWTON

class Newton{
public:
	//Static as to not require class
	static double newton(Fcn& f, Fcn& df, double xStart, int maxit, double tol, bool show_iterates)
	{
		//Not to override xStart
		double x = xStart;
		//Find f(x)
		double fx = f(x);

		//For total iterations wanted
		for(int i = 0; i < maxit; i++)
		{
			//Find derivative at f(x)
			double fp = df(x);

			//If derivative to small approcing horizontal asymptote or double root.
			if(std::abs(fp) < pow(10, -5))
			{
				if(show_iterates)
					std::cout << "Too Small Derivative\n";
				break;
			}

			//Value to reduce x by
			double d = (double)fx/(double)fp;

			//Reduce x and find new f(x) value
			x = x - d;
			fx = f(x);

			//If distance is withing tolerance root found
			if(std::abs(d) < tol)
			{
				if(show_iterates)
				{
					std::cout << "Convergence\n";
				}
				break;
			}

			//Print each value if wanted
			if(show_iterates)
			{
				std::cout << "Iter=" << i << "  ::  x=" << x << "  ::  d=" << std::abs(d) << "  ::  fx=" << std::abs(fx) <<"\n";
			}
		}

		//Return root
		return x;
	}
};



#endif
