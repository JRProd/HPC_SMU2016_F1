/* Project - Project 2_Part a
 * Prof - Dr Xu
 * Name - Jake Rowland
 * Date - 10/6/16
 * Purpuse - Create vandermonde matrix to show ill-conditioning
*/

#include <iostream>


#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include "matrix.hpp"

int main() {

	//Defining the different n's for the project and the files to write to
	std::vector<int> n = {5, 9, 17, 33, 65};
	std::ofstream residOut("residual.txt", std::ios::out);
	std::ofstream errorOut("error.txt", std::ios::out);
	std::ofstream nOut("n.txt", std::ios::out);

	//For all values of n
	for(int i = 0; i < n.size(); i++)
	{
		//Create a vector of equally spaced n entries between 0 and 1
		Matrix v = Linspace(0, 1, n[i]);

		//Create a nXn matrix
		Matrix A(n[i],n[i]);

		//Define the power
		double power = 0;

		//A(i,j) = v(i)^(i-1)
		for(int x = 0; x < n[i]; x++)
		{
			for(int y = 0; y < n[i]; y++)
			{
				A(y,x) = pow(v(y), power);
			}
			power ++;
		}

		//True value of x
		Matrix xMat = Random(n[i]);

		//True value of b with value of x
		Matrix B(n[i]);

		//Find the value of b
		for(int x = 0; x < n[i]; x++)
		{
			double bi = 0;
			for(int y = 0; y < n[i]; y++)
			{
				double tempA = A(x,y);
				double tempX = xMat(y);
				bi += tempA * tempX;
			}
			B(x) = bi;
		}

		//Copy matrix because they are modified
		Matrix Acopy1 = A;
		Matrix Bcopy1 = B;
		
		//Approximate value of x
		Matrix xHat = LinearSolve(Acopy1,Bcopy1);

		//Approximate value of b
		Matrix bHat = A*xHat;

		//Find the residual vector
		Matrix residual = B - bHat;

		//Find the error vector
		Matrix error = xMat - xHat;

		//Calculate the norm of each vector
		double residualNorm = Norm(residual);
		double errorNorm = Norm(error);

		//Print to text file
		residOut <<  residualNorm << "\n";
		errorOut << errorNorm << "\n";
		nOut << n[i] << "\n";
	}
}