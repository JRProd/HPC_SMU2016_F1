
#include <iostream>
#include "fcn.hpp"
#include <cmath>

double composite_int(Fcn& f, const double a, const double b, const int n)
{
	if (b < a) {
    std::cerr << "error: illegal interval, b < a\n";
    return 0.0;
  }
  if (n < 1) {
    std::cerr << "error: illegal number of subintervals, n < 1\n";
    return 0.0;
  }

  // set subinterval width
  double h = (b-a)/n;

  // set nodes/weights defining the quadrature method
  double x1 = -sqrt((1.0/7.0) * (3.0 - 4.0 * sqrt(0.3)));
  double x2 = -sqrt((1.0/7.0) * (3.0 + 4.0 * sqrt(0.3)));
  double x3 =  sqrt((1.0/7.0) * (3.0 - 4.0 * sqrt(0.3)));
  double x4 =  sqrt((1.0/7.0) * (3.0 + 4.0 * sqrt(0.3)));
  double w1 =  1.0/2.0 + 1.0/12.0 * sqrt(10.0/3.0);
  double w2 =  1.0/2.0 - 1.0/12.0 * sqrt(10.0/3.0);
  double w3 =  1.0/2.0 + 1.0/12.0 * sqrt(10.0/3.0);
  double w4 =  1.0/2.0 - 1.0/12.0 * sqrt(10.0/3.0);

  // initialize result
  double F = 0.0;

  // loop over subintervals, accumulating result
  double xmid, node1, node2, node3, node4;
  for (int i=0; i<n; i++) {
   
    // determine evaluation points within subinterval
    xmid  = a + (i+0.5)*h;
    node1 = xmid + 0.5*h*x1;
    node2 = xmid + 0.5*h*x2;
    node3 = xmid + 0.5*h*x3;
    node4 = xmid + 0.5*h*x4;

    // add Gauss2 approximation on this subinterval to result
    F += w1*f(node1) + w2*f(node2) + w3*f(node3) + w4*f(node4);

  } // end loop

  // return final result
  return (0.5*h*F);
}