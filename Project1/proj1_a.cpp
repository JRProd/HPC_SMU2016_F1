#include "matrix.hpp"
#include "Nest.cpp"
#include <math.h>

int main()
{
    double e = 2.71828182845904523536;

    Matrix z = Linspace(-1,1,201);

    Matrix t4(4);
    Matrix p4(201);

    Matrix t8(8);
    Matrix p8(201);

    Matrix t12(12);
    Matrix p12(201);

    Matrix f(201);

    Matrix err4(201);
    Matrix err8(201);
    Matrix err12(201);

    t4(0,0) = 1;
    t4(1) = 1;
    t4(2) = (double)1/2;
    t4(3) = (double)1/6;

    t8.Insert(t4,0,3,0,0);

    t8(4) = (double)1/24;
    t8(5) = (double)1/120;
    t8(6) = (double)1/720;
    t8(7) = (double)1/5040;

    t12.Insert(t8,0,7,0,0);

    t12(8) = (double)1/40320;
    t12(9) = (double)1/367880;
    t12(10) = (double)1/3678800;
    t12(11) = (double)1/39916800;

    for(int i = 0; i < z.Rows(); i++)
    {
        p4(i) = Nest::nest(t4,z(i));
        p8(i) = Nest::nest(t8,z(i));
        p12(i) = Nest::nest(t12,z(i));

        f(i) = pow(e,z(i));

        err4(i) = (double)f(i)-(double)p4(i);
        err8(i) = (double)f(i)-(double)p8(i);
        err12(i) = (double)f(i)-(double)p12(i);
	//std::cout << f(i) - p4(i) << " = " << f(i) << " - " << p4(i) << "\n";
    }

    z.Write("z.txt");
    p4.Write("p4.txt");
    p8.Write("p8.txt");
    p12.Write("p12.txt");
    f.Write("f.txt");
    err4.Write("err4.txt");
    err8.Write("err8.txt");
    err12.Write("err12.txt");
}
