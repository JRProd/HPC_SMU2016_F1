// Starting Project 2

#include <iostream>
#include <vector>
#include <cmath>
#include "matrix.hpp"

int main() {
	std::vector<int> n = {5, 9, 17, 33, 65};

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

		Matrix x = Random(n[i]);

		Matrix B = A*x;

		Matrix xHat = LinearSolve(A,B);

		xHat.Write();
		x.Write();
		std::cout << "\n";
	}
}