#include "../include/main.hpp"

int main( int argc, const char* argv[] ){
    Metodos metodos;

    int n = 3;
	double *y = new double[n];
	double *x= new double[n]; 
	int iteraciones = 200;
	int matrix[3][3] = {{6,5,-5},{2,6,-2},{2,5,-1}}; 
	x[0]=1;
	x[1]=2;
	x[2]=3;

	cout << endl;
	cout << "Ultimo r: " << metodos.powerMethod(n,matrix,x,iteraciones,y) << endl;
    
    return 0;
}
