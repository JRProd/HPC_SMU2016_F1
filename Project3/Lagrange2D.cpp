#include <iostream>

#include "matrix.hpp"

#ifndef LANGRANG_2D
#define LANGRANG_2D

class Lagrange2D
{
private:
	//Get the lagrange_basis
	static double Lagrange_basis(Matrix& x, int i, double z, bool show_iterates)
	{
		//For debug
		if(show_iterates)
			std::cout << "Lagrange_basis\n";
		  double l = 1.0;              // initialize basis function

		  for (size_t j=0; j<x.Size(); j++)
		     if (j != i)
		       l *= (z - x(j)) / (x(i) - x(j));

		  return l;
	}

	//Get the 2D Lagrange basis
	static double Lagrange2D_Basis(Matrix& xnodes, Matrix& ynodes, int i, int j, double x, double y, bool show_iterates)
	{
		//For Debug
		if(show_iterates)
			std::cout << "Lagrange2D_Basis\n";

		//Get the lagrange basis for x and y
		double xLagrangeBasis = Lagrange_basis(xnodes, i, x, show_iterates);
		double yLagrangeBasis = Lagrange_basis(ynodes, j, y, show_iterates);

		//Combine them
		return xLagrangeBasis * yLagrangeBasis;
	}

public:

	//Get the value for 2D lkagrange
	static double lagrange2D(Matrix& x, Matrix& y, Matrix& f, double a, double b, bool show_iterates)
	{
		//For debug
		if(show_iterates)
			std::cout << "Lagrange2D\n";

		//Define computed
		double computedPoint = 0.0;

		//Get the sum of x Rows
		for(int i = 0; i < x.Rows(); i++)
		{
			//Get the sum of y Rows
			for(int j = 0; j < y.Rows(); j++)
			{
				//For Debug
				if(show_iterates)
					std::cout << "(i, j) :: (" << i << ", " << j << ")\n(a, b) :: " << "(" << a << ", " << b << ")\n\n";

				//Calculate the lagrange2D
				computedPoint += f(i,j) * Lagrange2D_Basis(x,y,i,j,a,b,false);
			}
		}
		return computedPoint;
	}
};

#endif