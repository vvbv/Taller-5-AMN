#include "../include/mathematica.hpp"

Mathematica::Mathematica(){};
Mathematica::~Mathematica(){};
double Mathematica::norma(double *y){
    double y1=fabs(y[0]);
	double y2=fabs(y[1]);
	double y3=fabs(y[2]);
	double norma_y=fmax(fabs(y[0]),fmax(fabs(y[1]),fabs(y[2])));
	return norma_y;
};
void Mathematica::matrixVectorProduct(int n, int matrix[][3],double  *x,double *y){
    for(int i=0;i<n;i++){
			y[i]= (matrix[i][0]*x[0])+(matrix[i][1]*x[1])+(matrix[i][2]*x[2]);
	}
};