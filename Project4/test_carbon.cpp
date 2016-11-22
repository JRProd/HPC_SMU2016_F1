#include "matrix.hpp"

double carbon(const double x, const double t, 
	const double T, const double rtol, const double atol);

int main()
{
	Matrix T = Linspace(800,1200, 400);
	Matrix t = Linspace(1, 2880, 600);

	double rtol = pow(10, -11);
	double atol = pow(10, -15);

	Matrix C2(400,600);
	Matrix C4(400,600);

	for(int i = 0; i < 400; i++)
	{
		for(int j = 0; j < 600; j++)
		{
			C2(i,j) = carbon(0.002, t(j), T(i), rtol, atol);
			C4(i,j) = carbon(0.004, t(j), T(i), rtol, atol);
		}
	}

	Matrix C2_800(600);
	Matrix C2_900(600);
	Matrix C2_1000(600);
	Matrix C2_1100(600);
	Matrix C2_1200(600);

	for(int j = 0; j < 600; j++)
	{
		C2_800(j) = carbon(0.002, t(j), 800, rtol, atol);
		C2_900(j) = carbon(0.002, t(j), 900, rtol, atol);
		C2_1000(j) = carbon(0.002, t(j), 1000, rtol, atol);
		C2_1100(j) = carbon(0.002, t(j), 1100, rtol, atol);
		C2_1200(j) = carbon(0.002, t(j), 1200, rtol, atol);
	}

	Matrix C4_800(600);
	Matrix C4_900(600);
	Matrix C4_1000(600);
	Matrix C4_1100(600);
	Matrix C4_1200(600);

	for(int j = 0; j < 600; j++)
	{
		C4_800(j) = carbon(0.004, t(j), 800, rtol, atol);
		C4_900(j) = carbon(0.004, t(j), 900, rtol, atol);
		C4_1000(j) = carbon(0.004, t(j), 1000, rtol, atol);
		C4_1100(j) = carbon(0.004, t(j), 1100, rtol, atol);
		C4_1200(j) = carbon(0.004, t(j), 1200, rtol, atol);
	}

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