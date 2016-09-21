/* Project - Project 1: Part B
 * Professor - Dr. Xu
 * Date - 9/15/16
 * Author - Jake Rowland
 * Purpose - Find the relative error and upper bounds in approximating a fuctions derivative.
*/


#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>

//Represents f(x) = x^{-3}
double fx(double x)
{
	return pow(x,-3);
}

//Represents f'(x) = -3x^{-4}
double fPrime(double x)
{
	return -3 * pow(x,-4);
}

//Represents f"(x) = 12x^{-5}
double fDoublePrime(double x)
{
	return 12 * pow(x, -5);
}

//Calcuates the error in approximating the derivative of a fuction
int main()
{
	//Create the decreasing interaval for the standard derivative formula
	std::vector<int> n;
	std::vector<double> h;

	for(int i = 1; i <= 52; i++)
	{
		n.push_back(i);
		h.push_back(pow(2,-i));
	}

	//Create vector for approximate error(r) and upper bound error(R)
	std::vector<double> r;
	std::vector<double> R;

	//Create three constants to reduce arithmatic overhead
	double fConst = fx(3);
	double fPrimeConst = fPrime(3);
	double fDoubleConst = fDoublePrime(3);

	//Create constant u to represnt error in rounding to dpMachine numbers
	double u = pow(2,-52)/2;

	//Create constant for the upper bound error
	double c1 = std::abs( fDoubleConst / ( 2 * fPrimeConst ) );
	double c2 = std::abs( ( fConst * pow(2,-52) / fPrimeConst));

	//Calculate the errors for decreasing values of h
	for (int i = 0; i < h.size(); ++i)
	{
		r.push_back(std::abs((fPrimeConst - ((fx(3+h[i]) - fConst) / h[i])) / fPrimeConst));
		R.push_back(c1*h[i] + c2*(1/h[i]));
	}

	//Create file objects to trasnfer r and R to txt files
	std::ofstream nFile;
	std::ofstream hFile;
	std::ofstream rFile;
	std::ofstream RFile;

	//Open txt files
	nFile.open("n.txt");
	hFile.open("h.txt");
	rFile.open("r.txt");
	RFile.open("R.txt");

	//Write to txt files
	for (int i = 0; i < r.size(); ++i)
	{
		nFile << n[i] << "\n";
		hFile << h[i] << "\n";
		rFile << r[i] << "\n";
		RFile << R[i] << "\n";
	}

	//Clsoe files
	nFile.close();
	hFile.close();
	rFile.close();
	RFile.close();
}
