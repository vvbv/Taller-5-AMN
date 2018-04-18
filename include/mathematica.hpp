#ifndef MATHEMATICA_HPP_
#define MATHEMATICA_HPP_

#include <math.h>

using namespace std;

class Mathematica{

    private:

    public:
        Mathematica();
        ~Mathematica();
        double norma(double *y);
        void matrixVectorProduct(int n, int matrix[][3],double  *x,double *y);

};

#endif