#include <iostream>
#include <math.h>

#include "matrix.hpp"
#include "Lagrange2D.cpp"

double func(double x, double y)
{
	double top = 1;
	double bottom = 1 + pow(x,2) + pow(y, 2);

	return top / bottom;
}

double chev(int L, int i, int m)
{
	double top = (2*i +1)*M_PI;
	double bottom = 2*m + 2;

	return L * cos(top/bottom);
}

int main()
{
	std::cout << "Hello World\n";
	int m = 24;
	int n = 24;

	Matrix x(m+1);
	Matrix y(n+1);
	for(int i = 0; i < m+1; i ++)
	{
		x(i) = chev(4, i, m + 1);
		y(i) = chev(4, i, n + 1);
	}

	Matrix f(m+1, n+1);

	for(int i = 0; i < m + 1; i++)
	{
		for(int j = 0; j < n + 1; j++)
		{
			f(i,j) = func(x(i), y(j));
		}
	}

	Matrix a = Linspace(-4, 4, 201);
	a.Write("avals.txt");
	Matrix b = Linspace(-4, 4, 101);
	b.Write("bvals.txt");

	Matrix p6(201, 101);
	Matrix runge(201, 101);

	for(int i = 0; i < 201; i++)
	{
		for(int j = 0; j < 101; j++)
		{
			runge(i,j) = func(a(i), b(j));
			p6(i,j) = Lagrange2D::lagrange2D(x, y, f, a(i), b(j), false);
		}
	}

	std::cout << "Hello World\n";

	p6.Write("p24_Cheb.txt");
	runge.Write("Runge.txt");
}