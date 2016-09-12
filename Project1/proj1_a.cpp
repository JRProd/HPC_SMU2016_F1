/* Project - Project 1: Part A
 * Professor - Dr. Xu
 * Date - 9/15/16
 * Author - Jake Rowland
 * Purpose - Find approximations of a funtion and the error in those approximations
*/

#include "matrix.hpp"
#include "Nest.cpp"
#include <math.h>

//Find approximations of e^x for three taylor polynomials and the error of these approximations
int main()
{
    //Create constant e
    const double e = 2.71828182845904523536;

    //Use linspace to create vector [-1, -.99, -.98, ..., -.01, 0, .01, ..., .98, .99, 1]
    Matrix z = Linspace(-1,1,201);

    //Create a 4 element vector for taylor polynomial conastants
    //and create vector for the approximation
    Matrix t4(4);
    Matrix p4(201);

    //Create a 8 element vector for taylor polynomial conastants
    //and create vector for the approximation
    Matrix t8(8);
    Matrix p8(201);

    //Create a 12 element vector for taylor polynomial conastants
    //and create vector for the approximation
    Matrix t12(12);
    Matrix p12(201);

    //Create vector for actual e^x values
    Matrix f(201);

    //Create three vectors for the error of |f(x)-Pn(x)|
    Matrix err4(201);
    Matrix err8(201);
    Matrix err12(201);

    //Define the taylor polynomial for T4
    t4(0,0) = 1;
    t4(1) = 1;
    t4(2) = (double)1/2;
    t4(3) = (double)1/6;

    //Define the taylor polynomial for T8
    t8.Insert(t4,0,3,0,0);
    t8(4) = (double)1/24;
    t8(5) = (double)1/120;
    t8(6) = (double)1/720;
    t8(7) = (double)1/5040;

    //Define the taylor polynomial for T12
    t12.Insert(t8,0,7,0,0);
    t12(8) = (double)1/40320;
    t12(9) = (double)1/367880;
    t12(10) = (double)1/3678800;
    t12(11) = (double)1/39916800;

    //For all elements in vector z
    for(int i = 0; i < z.Rows(); i++)
    {
        //Compute the approximation
        p4(i) = Nest::nest(t4,z(i));
        p8(i) = Nest::nest(t8,z(i));
        p12(i) = Nest::nest(t12,z(i));

        //Compute the actual answer
        f(i) = pow(e,z(i));

        //Compute the error in approximation
        err4(i) = (double)f(i)-(double)p4(i);
        err8(i) = (double)f(i)-(double)p8(i);
        err12(i) = (double)f(i)-(double)p12(i);
    }

    //Write each of the vectors to a text file
    z.Write("z.txt");
    p4.Write("p4.txt");
    p8.Write("p8.txt");
    p12.Write("p12.txt");
    f.Write("f.txt");
    err4.Write("err4.txt");
    err8.Write("err8.txt");
    err12.Write("err12.txt");
}
