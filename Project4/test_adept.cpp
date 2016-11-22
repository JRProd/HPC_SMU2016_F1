/* Daniel R. Reynolds
   SMU Mathematics
   Math 3316
   31 October 2015 */

// Inclusions
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
#include "fcn.hpp"

using namespace std;

// function prototypes
int adaptive_int(Fcn& f, const double a, const double b, const double rtol, 
              const double atol, double& R, int& n, int& Ntot);

// Integrand
class fcn : public Fcn {
public:
  double c, d;
  double operator()(double x) {   // function evaluation
    return (exp(c*x) + sin(d*x));
  }
  double antiderivative(double x) { // function evaluation
    return (exp(c*x)/c - cos(d*x)/d);
  }
};


// This routine tests the Gauss-2 method on a simple integral
int main(int argc, char* argv[]) {

  // limits of integration
  double a = -3.0;
  double b = 5.0;

  // integrand
  fcn f;
  f.c = 0.5;
  f.d = 25.0;

  // true integral value
  double Itrue = f.antiderivative(b) - f.antiderivative(a);
  printf("\n True Integral = %22.16e\n", Itrue);


  // test the Gauss-2 rule
  cout << "\n Adaptive Method approximation:\n";
  cout << "     n(nTol),   rtol           R(f)                |I(f) - R(f)|          rtol|I(f)| + atol\n";
  cout << "  -------------------------------------------------------------------------------------------\n";
  vector<double> rtol = {pow(10,-2), pow(10,-4), pow(10,-6), pow(10,-8), pow(10,-10), pow(10,-12)};

  // iterate over n values, computing approximations, error, convergence rate
  double Iapprox;
  int n;
  int nTol;
  for (int i=0; i<rtol.size(); i++) {

    int worked = adaptive_int(f, a, b, rtol[i], rtol[i]/1000.0, Iapprox, n, nTol);
    printf("    %3i(%3i), %5.1e", n, nTol, rtol[i]);
    if (worked == 0) 
      printf("  %22.16e  %22.16e  %22.16e\n", Iapprox, abs(Itrue - Iapprox), (rtol[i]) * abs(Itrue) + rtol[i]/1000);
    else 
      printf("Did not solve!");
    
  }
  cout << "  -------------------------------------------------------------------------------------------\n";
}


