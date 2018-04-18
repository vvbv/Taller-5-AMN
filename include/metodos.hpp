#ifndef METODOS_HPP_
#define METODOS_HPP_

#include "../src/mathematica.cpp"

using namespace std; 

class Metodos{

    private:
        Mathematica mathematica;
    public:
        Metodos();
        ~Metodos();
        int powerMethod(int n, int matrix[3][3], double *x, int iteraciones, double *y);

};

#endif