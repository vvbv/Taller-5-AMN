#ifndef METODOS_HPP_
#define METODOS_HPP_

#include "../src/mathematica.cpp"
#include <iomanip>

using namespace std; 

class Metodos{

    private:
        Mathematica mathematica;
    public:
        Metodos();
        ~Metodos();
        double powerMethod(int n, int matrix[3][3], double *x, int iteraciones, double *y);
        double inverse_power_method( double matrix_L[3][3], double matrix_U[3][3], double x[3], int iterations  );
        double inverse_power_method2( double matrix[3][3], double x[3], int iterations  );

};

#endif