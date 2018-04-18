#include "../include/metodos.hpp"

Metodos::Metodos(){};
Metodos::~Metodos(){};
int Metodos::powerMethod(int n, int matrix[3][3], double *x, int iteraciones, double *y){
    double r=0;
	double norma_y = 0;
	for(int k=1; k<=iteraciones;k++){//iteraciones
		//producto matriz vector
        mathematica.matrixVectorProduct(n,matrix,x,y);
		
		//residuo con phi especifico
		r = (y[1])/(x[1]); //phi como de vector al valor en la posicion 2
		//normalizacion
		for(int i=0;i<n;i++){
			x[i] = y[i] / mathematica.norma( y );
		}
		//impresion
		cout << endl;
		cout << "Iteracion:" << k << endl;
		cout << "Residuo: " << r << endl;
		cout << "x("<<k<<"): ";
		for(int i=0;i<n;i++){
			cout << x[i] << " ";
		}
		cout << endl;
	}
	return r;
};