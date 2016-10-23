/* Project - Project 2_Part b
 * Prof - Dr Xu
 * Name - Jake Rowland
 * Date - 10/6/16
 * Purpuse - Test the newton class
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include "newton.cpp"
#include "fcn.hpp"

//Creating the fuction f(x) = x^2 * (x - 3) * (x + 2)
class fnorm: public Fcn 
{
	double operator()(double x)
	{
		return pow(x, 2) * (x - 3) * (x + 2);
	}
};

//Create the derivative of the function f(x)
class fderv: public Fcn 
{
	double operator()(double x)
	{
		return x * ((4 * pow(x, 2)) - (3 * x) - 12); 
	}
};

int main ()
{
	//Creating the starting points and the tolerances
	double x0[3] = {-3, 1, 2};
	double e[3] = {pow(10, -1), pow(10, -5), pow (10, -9)};

	//Create both of the functions
	fnorm f1;
	fderv f2;

	//Loop throught the different starting points
	for(int i = 0; i < 3; i++)
	{
		//Loop throught the different tolerances
		for(int j = 0; j < 3; j++)
		{
			//States what starting point and tolerance used and calls Newton::newton()
			std::cout << "Using " << x0[i] << " to an error of " << e[j] << "\n";
			Newton::newton(f1, f2, x0[i], 50, e[j], true);
			std::cout << "\n\n";
		}
	}
}
