/* Project - Project 3
 * Professor - Dr. Xu
 * Date - 11/3/16
 * Author - Jake Rowland
*/

#include <iostream>
#include <math.h>

#include "matrix.hpp"
#include "Lagrange2D.cpp"

//Function to interpolate
double func(double x, double y)
{
	double top = 1;
	double bottom = 1 + pow(x,2) + pow(y, 2);

	return top / bottom;
}

int main()
{
	//Create a and b
	Matrix a = Linspace(-4, 4, 201);
	a.Write("avals.txt");
	Matrix b = Linspace(-4, 4, 101);
	b.Write("bvals.txt");

	//Set m and n
	int m = 6;
	int n = 6;

	//Get uniform nodes
	Matrix x = Linspace(-4, 4, m+1);
	Matrix y = Linspace(-4, 4, n+1);

	//Get function nodes
	Matrix f(m+1, n+1);

	for(int i = 0; i < m + 1; i++)
	{
		for(int j = 0; j < n + 1; j++)
		{
			f(i,j) = func(x(i), y(j));
		}
	}

	//Setup interpolating polynomial and function grid
	Matrix p6(201, 101);
	Matrix runge(201, 101);

	//Calculate both
	for(int i = 0; i < 201; i++)
	{
		for(int j = 0; j < 101; j++)
		{
			runge(i,j) = func(a(i), b(j));
			p6(i,j) = Lagrange2D::lagrange2D(x, y, f, a(i), b(j));
		}
	}

	//Write to file
	p6.Write("p6_uni.txt");
	runge.Write("Runge.txt");

	//Get new m and n
	m = 24;
	n = 24;

	//Get new nodes
	Matrix x2 = Linspace(-4, 4, m+1);
	Matrix y2 = Linspace(-4, 4, n+1);

	//Get new function nodes
	Matrix f2(m+1, n+1);

	for(int i = 0; i < m + 1; i++)
	{
		for(int j = 0; j < n + 1; j++)
		{
			f2(i,j) = func(x2(i), y2(j));
		}
	}

	//Get new interpolating polynomial
	Matrix p24(201, 101);

	//Calculate it
	for(int i = 0; i < 201; i++)
	{
		for(int j = 0; j < 101; j++)
		{
			p24(i,j) = Lagrange2D::lagrange2D(x2, y2, f2, a(i), b(j));
		}
	}

	//Write to file
	p24.Write("p24_uni.txt");
}