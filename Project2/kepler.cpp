/* Project - Project 2_Part c
 * Prof - Dr Xu
 * Name - Jake Rowland
 * Date - 10/6/16
 * Purpuse - Use Newton's method of root finding for orbital path prediction
*/

#include <cmath>
#include <iostream>
#include <fstream>

#include "fcn.hpp"
#include "newton.cpp"

//Create the function f(x) = e * sin(w) - w - t
class Kepler: public Fcn
{
private:
	//define variables needed for each iteration of f(x)
	double t[10001];
	double e;
	int run;

	//Function to find all values of t
	void defT()
	{
		std::ofstream tOut("t.txt", std::ios::out);
		for(int i = 0; i < 10001; i++)
		{
			t[i] = (double)i / 1000;
			tOut << t[i] << "\n";
		}
	}

public:
	//Constructor to create constant e
	Kepler(double a, double b)
	{
		e = sqrt(1 - (pow(b,2)/pow(a,2)));
		run = 0;
		defT();
	}

	//Operation that calculates the fuction f(x)
	double operator()(double w)
	{
		return e * sin(w) - w - t[run];
	}

	//Increment run for next run
	void runIncr()
	{
		run = run + 1;
	}
};

//Derivative of f(x)
class KeplerDerv: public Fcn
{
private:
	//Definition of e for f'(x)
	double e;

public:
	//Constructor which defines e
	KeplerDerv(double a, double b)
	{
		e = sqrt(1 - (pow(b,2)/pow(a,2)));
	}

	//Operation that calculates f'(x)
	double operator()(double w)
	{
		return e * cos(w) - 1;
	}
};

int main()
{
	//Define a and b
	double a = 2.0;
	double b = 1.25;

	//Define the two values
	Kepler f(a,b);
	KeplerDerv fd(a, b);

	//Define tolerance
	double tol = pow(10,-5);

	//Define x and y array
	double x[10001];
	double y[10001];

	//Define first guess
	double w = 0.0;

	//Define .txt writers
	std::ofstream xOut("x.txt", std::ios::out);
	std::ofstream yOut("y.txt", std::ios::out);

	//For all spots in x[] and y[]
	for(int i = 0; i < 10001; i++)
	{
		//Define w' as root of newton(w)
		double w = Newton::newton(f, fd, w, 6, tol, false);

		//Calculate r with w
		double r = (a*b) / (sqrt( pow((b * cos(w)),2) + pow((a * sin(w)),2) ));

		//Calc (x,y) cordinates with r and w
		x[i] = r * cos(w);
		y[i] = r * sin(w);

		//Write to file
		xOut << x[i] << "\n";
		yOut << y[i] << "\n";

		//Increment t in function f
		f.runIncr();
	}
}