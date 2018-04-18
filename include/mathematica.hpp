#ifndef MATHEMATICA_HPP_
#define MATHEMATICA_HPP_

#include <cmath>

using namespace std;

class Mathematica{

    private:

    public:
        Mathematica();
        ~Mathematica();
        double norma(double *y);
        void matrixVectorProduct(int n, int matrix[][3],double  *x,double *y);
        double* matrix_x_vector(double matrix[3][3], double x[3]);
        double* solve_triangular_system( double matrix[3][3], double b[3] );
        double norm_2(double y[3]);
        void print_matrix( double matrix[3][3] );
 
};

#endif