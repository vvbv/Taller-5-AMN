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

// double Mathematica::norm_2(double y[3]){
// 	return sqrt( pow(y[0], 2) + pow(y[1], 2) + pow(y[2], 2) );
// };

void Mathematica::matrixVectorProduct(int n, int matrix[][3],double  *x,double *y){
    for(int i=0;i<n;i++){
			y[i]= ( matrix[i][0]*x[0] )+(matrix[i][1]*x[1])+(matrix[i][2]*x[2]);
	}
};

// double* Mathematica::matrix_x_vector(double matrix[3][3], double x[3]){
//     double *y = new double[ 3 ];
//     for( int i = 0; i < 3; i++ ){
//         for( int j = 0; j < 3; j++ ){
//             y[ i ] = y[ i ] + matrix[ i ][ j ] * (double) x[j];
//         }
//     }
//     return y;
// };

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
        for(int i=0;i<3;i++){
        }
    }else{
        x[2] = ( b[2] ) / (double) matrix[2][2];
        x[1] = ( b[1] - ( matrix[1][2] * (double) x[2] ) ) /  (double) matrix[1][1];
        x[0] = ( b[0] - ( matrix[0][2] * (double) x[2] ) - ( matrix[0][1] * (double) x[1] ) ) / (double) matrix[0][0];
        for(int i=0;i<3;i++){
            cout << "bien" << endl;
            cout << x[i] << endl;
        }
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


void Mathematica::factorLU(double matrix[3][3],double **matrix_L,double **matrix_U,int n){
    double suma = 0;
    for(int k=0;k<n;k++){
        for(int s=0;s<k;s++){
            suma = suma + matrix_L[k][s]*matrix_U[s][k];
        }
        matrix_U[k][k] = matrix[k][k]-suma;
        for(int j=k;j<n;j++){
            suma = 0;
            for(int s=0; s<k;s++){
                suma = suma + matrix_L[k][s]*matrix_U[s][j];
            }
            matrix_U[k][j] = (matrix[k][j]-suma)/matrix_L[k][k]; 
        }
        for(int i=k;i<n;i++){
            suma = 0;
            for(int s=0;s<k;s++){
                suma = suma + matrix_L[i][s]*matrix_U[s][k];
            }
            matrix_L[i][k] = (matrix[i][k]-suma)/matrix_U[k][k];
        }
    }
};

double* Mathematica::solveTriangularMatrix(double **matrix, double b[3]){
    //si el elemento en la esquina superior derecha es cero es triangular inferior (tomando un elemento en la parte triangular superior)
    double *x= new double[3];
    double suma;
    int n=3;
    cout << "que tipo de matriz es " << endl;
    if(matrix[0][2] == 0){
        cout << "triangular inferior" << endl;
        for(int i=0;i<n;i++){
            suma=0;
            for(int j=0;j<i;j++){
                suma = suma + (matrix[i][j]*x[j]);
            }
            x[i] = (b[i] - suma)/matrix[i][i];
        }
    }
    else{
        //si el elemento en la esquina inferior izq es cera es triangular superior
        if(matrix[2][0] == 0){
            cout << "triangular superior" << endl;
            for(int i=n-1;i>-1;i--){
                suma = 0;
                for(int j=i+1;j<n;j++){
                    suma = suma + (matrix[i][j]*x[j]);
                }
                x[i]=(b[i]-suma)/matrix[i][i];

            }
            for(int i=0;i<3;i++){
                cout << "mal" << endl;
                cout << x[i] << endl;
            }
        }
    }
    return x;
}



double* Mathematica::factorSolveLU( double matrix[3][3], double x[3] ){
    //factorizacion lu
    int n=3;
    double *z;
    double *y;
    double *x_=x;
    double **matrix_L = new double*[n];
    double **matrix_U = new double*[n];
    for(int i=0;i<n;i++){
        matrix_L[i]=new double[n];
        matrix_U[i]=new double[n];            
    }
    for(int i=0;i<n;i++){
        matrix_U[i][i]=1.0;
        matrix_L[i][i]=1.0; 
    }
    factorLU(matrix,matrix_L,matrix_U,3);
    //resolver lu
    // Resolution between Lz = x
    z = solveTriangularMatrix( matrix_L, x_ );

    // Resolution between Uy = z
    y = solveTriangularMatrix( matrix_U, z );
    return y;
};