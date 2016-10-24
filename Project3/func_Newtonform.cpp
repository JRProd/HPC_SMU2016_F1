#include <iostream>

#include "matrix.hpp"
#include "Nest.cpp"


#ifndef FUNC_NEWTON_FORM
#define FUNC_NEWTON_FORM

class func_Newtonform
{
public:
	//Finds a0, a1, ... , an with (x0,y0), (x1,y1), ... (xn,yn)
	static Matrix Newton_coefficients(Matrix& xnodes, Matrix& ynodes, bool show_iterates)
	{
		Matrix a(xnodes.Rows());
		a(0) = ynodes(0);
		if(show_iterates)
			std::cout << "a_0 = " << a(0) << "\n\n";

		for(int i = 1; i < xnodes.Rows(); i++)
		{
			if(show_iterates)
				std::cout << "a_" << i << " = " << ynodes(i) << " - ";
			double top = ynodes(i) - Newton_nestedform(a, xnodes, xnodes(i), show_iterates);
			if(show_iterates)
				std::cout << "\n/\n";
			double bottom = Newton_basis(xnodes, i-1, xnodes(i), show_iterates);
			a(i) = top/bottom;
			if(show_iterates)
				std::cout << "\n= " << a(i) << "\n\n";
		}
		return a;
	}

	//Solves P_n(x) = a_0 + a_1(Newton_basis(0)) + a_2(Newton_basis(1)) + ... + a_n(Newton_basis(n))
	static double Newton_nestedform(Matrix& a, Matrix& xnodes, double x, bool show_iterates)
	{
		if(show_iterates)
			std::cout <<"P_4" << "(" << x << ") = ";
		double PofX = a(0);
		if(show_iterates)
			std::cout << PofX;
		for(int i = 1; i < a.Rows(); i++)
		{
			if(show_iterates)
				std::cout << " + " << a(i) << " * "; 
			PofX += a(i) * Newton_basis(xnodes, i - 1, x, show_iterates);
		}
		return PofX;
	}

private:
	//Solves (x - x_0)(x - x_1)...(x - x_n)
	static double Newton_basis(Matrix& xnodes, int n, double x, bool show_iterates)
	{
		double xPlusOne = 1.0;
		for(int i = 0; i <= n; i++)
		{
			xPlusOne = xPlusOne * (x - xnodes(i));
			if(show_iterates)
				std::cout <<"(" << x << " - " << xnodes(i) << ")";
		}
		return xPlusOne;
	}
};

#endif