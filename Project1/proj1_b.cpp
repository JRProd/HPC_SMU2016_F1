#include <vector>
#include <cmath>
#include <iostream>


double fx(double x)
{
	return pow(x,-3);
}

double fPrime(double x)
{
	return -3 * pow(x,-4);
}

double fDoublePrime(double x)
{
	return 12 * pow(x, -5);
}

int main()
{
	std::cout << "Starting Code!\n";
	std::vector<int> n;
	std::vector<double> h;

	for(int i = 1; i <= 52; i++)
	{
		n.push_back(i);
		h.push_back(pow(2,-i));
	}

	std::vector<double> r;
	std::vector<double> R;

	double fConst = fx(3);
	double fPrimeConst = fPrime(3);
	double fDoubleConst = fDoublePrime(3);

	double u = pow(2,-52)/2;

	double c1 = std::abs( fDoubleConst / ( 2 * fPrimeConst ) );
	double c2 = std::abs( ( fConst * pow(2,-52) / fPrimeConst));

	std::cout << u << "=u\n";
	std::cout << fConst << "=fConst\n" << fPrimeConst << "=fPrimeConst\n" << fDoubleConst << "=fDoulbeConst\n";
	std::cout << c1 << "=c1\n" << c2 << "=c2\n";

	for (int i = 0; i < h.size(); ++i)
	{
		std::cout << i << "=i  :  " << h[i] << "=h[i]\n";
		r.push_back(std::abs(-h[i]*(fDoubleConst/(2*fPrimeConst)) + (1/h[i])*(u*fConst + u*fConst)/fPrimeConst));
		R.push_back(c1*h[i] + c2*(1/h[i]));
	}

	for(int i = 0; i < R.size(); i++)
	{
		std::cout << r[i] << "  :  ";
		std::cout << R[i] << std::endl;
	}
}
