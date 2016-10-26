#include <iostream>

#include "matrix.hpp"
#include "func_Newtonform.cpp"

//Create a fuction for the Project 3 test
double function(double x)
{
	return 3.1*pow(x,4) + 2.3*pow(x,3) - 6.6*pow(x,2) + 8.7*x + 7.9;
}

//Main function
int main ()
{
	//Create matrix for Newton's
	Matrix xnode(5);
	Matrix ynode(5);

	//Set the diffrent points
	xnode(0) = -2;
	ynode(0) = function(-2);

	xnode(1) = -1;
	ynode(1) = function(-1);

	xnode(2) = 0;
	ynode(2) = function(0);

	xnode(3) = 1;
	ynode(3) = function(1);

	xnode(4) = 2;
	ynode(4) = function(2);

	//Get the a values
	Matrix a = func_Newtonform::Newton_coefficients(xnode, ynode, false);

	//Create matrix for data points
	Matrix fOfX(201);
	Matrix p_4OfX(201);

	//Get the x coords
	Matrix x = Linspace(-3, 3, 201);

	//Get the coordinates
	for(int i = 0; i < x.Rows(); i++)
	{
		fOfX(i) = function(x(i));
		p_4OfX(i) = func_Newtonform::Newton_nestedform(a, xnode, x(i), false);
	}

	//Write to file
	x.Write("x.txt");
	fOfX.Write("f.txt");
	p_4OfX.Write("p.txt");
}
