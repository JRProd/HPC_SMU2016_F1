/* Project - Project 3
 * Professor - Dr. Xu
 * Date - 11/3/16
 * Author - Jake Rowland
*/

#include <iostream>

#include "matrix.hpp"

#ifndef LANGRANG_2D
#define LANGRANG_2D

class Lagrange2D
{
private:
	//Get the lagrange_basis
	static double Lagrange_basis(Matrix& x, int i, double z)
	{
		  double l = 1.0;              // initialize basis function

		  for (size_t j=0; j<x.Size(); j++)
		     if (j != i)
		       l *= (z - x(j)) / (x(i) - x(j));

		  return l;
	}

	//Get the 2D Lagrange basis
	static double Lagrange2D_Basis(Matrix& xnodes, Matrix& ynodes, int i, int j, double x, double y)
	{
		//Get the lagrange basis for x and y
		double xLagrangeBasis = Lagrange_basis(xnodes, i, x);
		double yLagrangeBasis = Lagrange_basis(ynodes, j, y);

		//Combine them
		return xLagrangeBasis * yLagrangeBasis;
	}

public:

	//Get the value for 2D lagrange
	static double lagrange2D(Matrix& x, Matrix& y, Matrix& f, double a, double b)
	{
		//Define computed
		double computedPoint = 0.0;

		//Get the sum of x Rows
		for(int i = 0; i < x.Rows(); i++)
		{
			//Get the sum of y Rows
			for(int j = 0; j < y.Rows(); j++)
			{
				//Calculate the lagrange2D
				computedPoint += f(i,j) * Lagrange2D_Basis(x,y,i,j,a,b);
			}
		}
		return computedPoint;
	}
};

#endif