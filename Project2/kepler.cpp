#include <cmath>
#include <iostream>
#include <fstream>

#include "fcn.hpp"
#include "newton.cpp"

class Kepler: public Fcn
{
private:
	double t[10001];
	double e;
	int run;
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
	Kepler(double a, double b)
	{
		e = sqrt(1 - (pow(b,2)/pow(a,2)));
		run = 0;
		defT();
	}


	double operator()(double w)
	{
		return e * sin(w) - w - t[run];
	}

	void runIncr()
	{
		run = run + 1;
	}
};

class KeplerDerv: public Fcn
{
private:
	double e;

public:
	KeplerDerv(double a, double b)
	{
		e = sqrt(1 - (pow(b,2)/pow(a,2)));
	}

	double operator()(double w)
	{
		return e * cos(w) - 1;
	}
};

int main()
{
	double a = 2.0;
	double b = 1.25;

	Kepler f(a,b);
	KeplerDerv fd(a, b);

	double tol = pow(10,-5);

	double x[10001];
	double y[10001];

	double w = 0.0;

	std::ofstream xOut("x.txt", std::ios::out);
	std::ofstream yOut("y.txt", std::ios::out);

	for(int i = 0; i < 10001; i++)
	{
		double w = Newton::newton(f, fd, w, 6, tol, false);

		double r = (a*b) / (sqrt( pow((b * cos(w)),2) + pow((a * sin(w)),2) ));

		x[i] = r * cos(w);
		y[i] = r * sin(w);

		xOut << x[i] << "\n";
		yOut << y[i] << "\n";

		f.runIncr();
	}

	for(int i = 0; i < 10001; i++)
	{
//		std::cout <<"("<<x[i]<<","<<y[i]<<")\n";
	}

}