/* Project - Project 3
 * Professor - Dr. Xu
 * Date - 11/3/16
 * Author - Jake Rowland
*/

#include <iostream>

#include "matrix.hpp"


#ifndef FUNC_NEWTON_FORM
#define FUNC_NEWTON_FORM

class func_Newtonform
{
public:
	//Finds a0, a1, ... , an with (x0,y0), (x1,y1), ... (xn,yn)
	static Matrix Newton_coefficients(Matrix& xnodes, Matrix& ynodes, bool show_iterates)
	{
		//Create a matrix of the same side
		Matrix a(xnodes.Rows());

		//Get the first a node
		a(0) = ynodes(0);

		//For debug
		if(show_iterates)
			std::cout << "a_0 = " << a(0) << "\n\n";

		for(int i = 1; i < xnodes.Rows(); i++)
		{
			//For debug
			if(show_iterates)
				std::cout << "a_" << i << " = " << ynodes(i) << " - ";

			//Get the top part of the Newton function
			double top = ynodes(i) - Newton_nestedform(a, xnodes, xnodes(i), show_iterates);

			//For debug
			if(show_iterates)
				std::cout << "\n/\n";

			//Get the bottem part of the Newton function
			double bottom = Newton_basis(xnodes, i-1, xnodes(i), show_iterates);

			//Divide the two
			a(i) = top/bottom;

			//For debug
			if(show_iterates)
				std::cout << "\n= " << a(i) << "\n\n";
		}
		return a;
	}

	//Solves P_n(x) = a_0 + a_1(Newton_basis(0)) + a_2(Newton_basis(1)) + ... + a_n(Newton_basis(n))
	static double Newton_nestedform(Matrix& a, Matrix& xnodes, double x, bool show_iterates)
	{
		//For debug
		if(show_iterates)
			std::cout <<"P_4" << "(" << x << ") = ";

		//Get the first value
		double PofX = a(0);

		//For debug
		if(show_iterates)
			std::cout << PofX;

		for(int i = 1; i < a.Rows(); i++)
		{
			//For debug
			if(show_iterates)
				std::cout << " + " << a(i) << " * ";

			//Calculate the value for the x value
			PofX += a(i) * Newton_basis(xnodes, i - 1, x, show_iterates);
		}
		return PofX;
	}

private:
	//Solves (x - x_0)(x - x_1)...(x - x_n)
	static double Newton_basis(Matrix& xnodes, int n, double x, bool show_iterates)
	{
		//Set start value
		double xPlusOne = 1.0;

		//Get the x_n value of the basis
		for(int i = 0; i <= n; i++)
		{
			//Calculate the basis
			xPlusOne = xPlusOne * (x - xnodes(i));
			//For debug
			if(show_iterates)
				std::cout <<"(" << x << " - " << xnodes(i) << ")";
		}

		//Return the basis
		return xPlusOne;
	}
};

#endif