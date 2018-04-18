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
			y[i]= ( matrix[i][0]*x[0] )+(matrix[i][1]*x[1])+(matrix[i][2]*x[2]);
	}
};

double* Mathematica::matrix_x_vector(double matrix[3][3], double x[3]){
    double *y = new double[ 3 ];
    for( int i = 0; i < 3; i++ ){
        for( int j = 0; j < 3; j++ ){
            y[ i ] = y[ i ] + matrix[ i ][ j ] * (double) x[j];
        }
    }
    return y;
};

double* Mathematica::solve_triangular_system( double matrix[3][3], double b[3] ){

    bool is_lower_triangular = true;
    if( ( matrix[2][0] + matrix[1][0] + matrix[2][1] ) == 0 ){
        is_lower_triangular = false;
    }

    double *x = new double[ 3 ];
    if( is_lower_triangular ){
        x[0] = ( b[0] ) / (double) matrix[0][0];
        x[1] = ( b[1] - ( matrix[1][0] * (double) x[0] ) ) /  (double) matrix[1][1];
        x[2] = ( b[2] - ( matrix[2][0] * (double) x[0] ) - ( matrix[2][1] * x[1] ) ) / (double) matrix[2][2];
    }else{
        x[2] = ( b[2] ) / (double) matrix[2][2];
        x[1] = ( b[1] - ( matrix[1][2] * (double) x[2] ) ) /  (double) matrix[1][1];
        x[0] = ( b[0] - ( matrix[0][2] * (double) x[2] ) - ( matrix[0][1] * (double) x[1] ) ) / (double) matrix[0][0];
    }

    return x;

};

void Mathematica::print_matrix( double matrix[3][3] ){

    for( int i = 0; i < 3; i++ ){
        for( int j = 0; j < 3; j++ ){
            cout << matrix[ i ][ j ] << " ";
        }
        cout << endl;
    }

};