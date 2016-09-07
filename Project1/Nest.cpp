#include <iostream>
#include "matrix.hpp"

class Nest
{
public:
    static double nest(Matrix& a, double x)
    {
        //Gets the size of the vector and stores it locally
        int size = a.Rows();
        //Gets the highest power coefficient first
        double poly = a(size -1);
        //Loops from the highest power to the lowest
        for(int i = size -2; i >= 0; i--)
        {
            //Add the new coefficient to the poly scaled by x
            poly = a(i) + (poly * x);
        }
        //return the result
        return poly;
    }
};


