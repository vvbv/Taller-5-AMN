#include "../include/metodos.hpp"

Metodos::Metodos(){};
Metodos::~Metodos(){};

double Metodos::powerMethod(int n, int matrix[3][3], double *x, int iteraciones, double *y){

    double r=0;
	double norma_y = 0;

	for(int k=1; k<=iteraciones;k++){//iteraciones
		//producto matriz vector
        this->mathematica.matrixVectorProduct(n,matrix,x,y);
		
		//residuo con phi especifico
		r = (y[1])/(x[1]); //phi como de vector al valor en la posicion 2
		//normalizacion
		for(int i=0;i<n;i++){
			x[i] = y[i] / this->mathematica.norma( y );
		}
		//impresion
		
		cout << "Ite: " << k << " => [";

		for(int i=0;i<n;i++){
			cout << setprecision(10) << x[i];
            if(i != (n-1)){
                cout << ", ";
            }else{
                cout << "]" << " R: " 
                     << setprecision(24) << r << endl;
            }
		}
	}
	return r;
};

double Metodos::inverse_power_method( double matrix_L[3][3], double matrix_U[3][3], double x[3], int iterations  ){

    cout << 0 << " => [" << x[0] << ", " << x[1] << ", " << x[2] << "]" << endl;

    double *y;
    double *x_=x;
    double last_residue = 0;
    for( int i = 0; i < iterations; i++ ){

        // Resolution between Lz = x
        double *z = this->mathematica.solve_triangular_system( matrix_L, x_ );
        // Resolution between Uy = z
        y = this->mathematica.solve_triangular_system( matrix_U, z );
        double r = y[0] / (double) x_[0];
        x_[0] = y[0] / (double) this->mathematica.norma( y );
        x_[1] = y[1] / (double) this->mathematica.norma( y );
        x_[2] = y[2] / (double) this->mathematica.norma( y );
        cout << "Ite: " << (i + 1) << " => [" 
             << setprecision(24) << x[0] << ", " 
             << setprecision(24) << x[1] << ", " 
             << setprecision(24) << x[2] << "]" << " R: " 
             << setprecision(24) << r << endl;
        last_residue = r;
    }

    return last_residue;

};

void Metodos::inverse_power_method2( double matrix[3][3], double x[3], int iterations  ){
	double *y;
	double *x_=x;
	for( int i = 0; i < iterations; i++ ){
        // Resolution between Lz = x
        y = this->mathematica.factorSolveLU(matrix,x_);

        double r = y[0] / (double) x_[0];
        x_[0] = y[0] / (double) this->mathematica.norma( y );
        x_[1] = y[1] / (double) this->mathematica.norma( y );
        x_[2] = y[2] / (double) this->mathematica.norma( y );
        cout << "metodo2" << endl;
        cout << i << " => [" 
             << setprecision(24) << x[0] << ", " 
             << setprecision(24) << x[1] << ", " 
             << setprecision(24) << x[2] << "]" << " R: " 
             << setprecision(24) << r << endl;
    }

};