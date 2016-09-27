// Starting Project 2

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include "matrix.hpp"

int main() {
	std::vector<int> n = {5, 9, 17, 33, 65};
	std::ofstream residOut("residual.txt", std::ios::out);
	std::ofstream errorOut("error.txt", std::ios::out);
	std::ofstream nOut("n.txt", std::ios::out);

	for(int i = 0; i < n.size(); i++)
	{
		Matrix v = Linspace(0, 1, n[i]);
		Matrix A(n[i],n[i]);

		double power = 0;

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

		Matrix Acopy1 = A;
		Matrix Bcopy1 = B;
		
		//Approximate value of x
		Matrix xHat = LinearSolve(Acopy1,Bcopy1);

		//Approximate value of b
		Matrix bHat = A*xHat;

		Matrix residual = B - bHat;
		Matrix error = xMat - xHat;

		double residualNorm = Norm(residual);
		double errorNorm = Norm(error);

		residOut <<  residualNorm << "\n";
		errorOut << errorNorm << "\n";
		nOut << n[i] << "\n";
	}
}