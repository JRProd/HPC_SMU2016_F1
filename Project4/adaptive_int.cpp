/* Project - Project 4
 * Professor - Dr. Xu
 * Author - Jake Rowland
 * Date - 12/1/2016
 * Purpose - Make my integration method adaptive
*/

#include "fcn.hpp"
#include <cmath>

double composite_int(Fcn& f, const double a, 
			const double b, const int n);

//Function to find k by
int increment(int x)
{
	double w = 0.4;
	double xD = 0.4;
	double yD = 0;
	return (int) round(exp(w * x + xD) + yD);
}

int adaptive_int(Fcn& f, const double a, const double b, const double rtol, const double atol, double& R, int& n, int& Ntot)
{
	//Nodes to start with
	int startN = 10;

	//Number of runs
	int runCount = 1;

	//While still under the node limit
	while(startN <= 10000)
	{
		//Get the first approximation
		double Rn = composite_int(f, a, b, startN);
		//Get the second approximation with k+1 nodes
		double RnIncr = composite_int(f, a, b, 10 * increment(runCount));

		//Check if in bounds
		if(std::abs(RnIncr - Rn) < rtol * std::abs(RnIncr) + atol)
		{
			//Store values
			R = RnIncr;
			n = startN;
			Ntot = runCount;
			//Return 0 if successful
			return 0;
		}

		//Increment nodes and run counter
		startN = 10 * increment(runCount);
		runCount ++;
	}
	//Return 1 if failed
	return 1;
}