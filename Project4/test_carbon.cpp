/* Project - Project 4
 * Professor - Dr. Xu
 * Author - Jake Rowland
 * Date - 12/1/2016
 * Purpose - Test carbon.cpp
*/

#include <iostream>
#include "matrix.hpp"

double carbon(const double x, const double t, 
	const double T, const double rtol, const double atol);

int main()
{
	//Set constants
	int tempSize = 400; //400
	int timeSize = 600; //600
	double rtol = pow(10, -11);
	double atol = pow(10, -15);

	//Get Temperature values
	Matrix T = Linspace(800,1200, tempSize);

	//Get time values
	Matrix t = Linspace(1, 48*3600, timeSize);

	//Get matrix for 2mm
	Matrix C2(tempSize,timeSize);

	//Get matrix for 4mm
	Matrix C4(tempSize,timeSize);

	//For all the temps
	for(int i = 0; i < tempSize; i++)
	{
		//For all the times
		for(int j = 0; j < timeSize; j++)
		{
			//Get the diffusion at time t and temp T
			C2(i,j) = carbon(0.002, t(j), T(i), rtol, atol);
			C4(i,j) = carbon(0.004, t(j), T(i), rtol, atol);

		}
	}

	//Get matrix for diffrent temperatures at 2mm
	Matrix C2_800(timeSize);
	Matrix C2_900(timeSize);
	Matrix C2_1000(timeSize);
	Matrix C2_1100(timeSize);
	Matrix C2_1200(timeSize);

	//For all the times
	for(int j = 0; j < timeSize; j++)
	{
		//Get the diffusion
		C2_800(j) = carbon(0.002, t(j), 800, rtol, atol);
		C2_900(j) = carbon(0.002, t(j), 900, rtol, atol);
		C2_1000(j) = carbon(0.002, t(j), 1000, rtol, atol);
		C2_1100(j) = carbon(0.002, t(j), 1100, rtol, atol);
		C2_1200(j) = carbon(0.002, t(j), 1200, rtol, atol);
	}

	//Get matrix for diffrent temperatures at 4mm
	Matrix C4_800(timeSize);
	Matrix C4_900(timeSize);
	Matrix C4_1000(timeSize);
	Matrix C4_1100(timeSize);
	Matrix C4_1200(timeSize);

	//For all the times
	for(int j = 0; j < t.Size(); j++)
	{
		//Get the diffusion
		C4_800(j) = carbon(0.004, t(j), 800, rtol, atol);
		C4_900(j) = carbon(0.004, t(j), 900, rtol, atol);
		C4_1000(j) = carbon(0.004, t(j), 1000, rtol, atol);
		C4_1100(j) = carbon(0.004, t(j), 1100, rtol, atol);
		C4_1200(j) = carbon(0.004, t(j), 1200, rtol, atol);
	}

	//Wire all the matrixes to files for graphing
	T.Write("Temp.txt");
	t.Write("time.txt");

	C2.Write("C2mm.txt");
	C4.Write("C4mm.txt");


	C2_800.Write("C2mm_800K.txt");
	C2_900.Write("C2mm_900K.txt");
	C2_1000.Write("C2mm_1000K.txt");
	C2_1100.Write("C2mm_1100K.txt");
	C2_1200.Write("C2mm_1200K.txt");

	C4_800.Write("C4mm_800K.txt");
	C4_900.Write("C4mm_900K.txt");
	C4_1000.Write("C4mm_1000K.txt");
	C4_1100.Write("C4mm_1100K.txt");
	C4_1200.Write("C4mm_1200K.txt");
}