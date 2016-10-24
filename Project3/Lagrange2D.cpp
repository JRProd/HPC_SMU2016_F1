#include <iostream>

#include "matrix.hpp"

#ifndef LANGRANG_2D
#define LANGRANG_2D

class Lagrange2D
{
private:
	static double Lagrange_basis(Matrix& x, int i, double z, bool show_iterates)
	{
		if(show_iterates)
			std::cout << "Lagrange_basis\n";
		  double l = 1.0;              // initialize basis function
		  for (size_t j=0; j<x.Size(); j++)
		     if (j != i)
		       l *= (z - x(j)) / (x(i) - x(j));
		  return l;
	}

	static double Lagrange2D_Basis(Matrix& xnodes, Matrix& ynodes, int i, int j, double x, double y, bool show_iterates)
	{
		if(show_iterates)
			std::cout << "Lagrange2D_Basis\n";
		double xLagrangeBasis = Lagrange_basis(xnodes, i, x, show_iterates);
		double yLagrangeBasis = Lagrange_basis(ynodes, j, y, show_iterates);
		return xLagrangeBasis * yLagrangeBasis;
	}

public:
	static double lagrange2D(Matrix& x, Matrix& y, Matrix& f, double a, double b, bool show_iterates)
	{
		if(show_iterates)
			std::cout << "Lagrange2D\n";
		double computedPoint = 0.0;
		for(int i = 0; i < x.Rows(); i++)
		{
			for(int j = 0; j < y.Rows(); j++)
			{
				if(show_iterates)
					std::cout << "(i, j) :: (" << i << ", " << j << ")\n(a, b) :: " << "(" << a << ", " << b << ")\n\n";
				computedPoint += f(i,j) * Lagrange2D_Basis(x,y,i,j,a,b,false);
			}
		}
		return computedPoint;
	}
};

#endif