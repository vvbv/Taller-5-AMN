#include "../include/main.hpp"

int main( int argc, const char* argv[] ){

    Metodos metodos;
    if( argc == 1 ){
        cout << "\n Help:\n\n       bin [ power_method || inverse_power_method ]    \n\n" << endl;
        return 0;
    };

    if( ( std::string ) argv[1] == "power_method" ){

            int n = 3; double *y = new double[n]; double *x= new double[n]; int iteraciones = 200;
            int matrix[3][3] = {{6,5,-5},{2,6,-2},{2,5,-1}}; 
            x[0]=1;
            x[1]=2;
            x[2]=3;
            cout << endl;
            cout << "Ultimo r: " << metodos.powerMethod(n,matrix,x,iteraciones,y) << endl;

    }else if( ( std::string ) argv[1] == "inverse_power_method" ){ 

            double *x= new double[3];
            int iteraciones = 200;
            x[0]=3;
            x[1]=7;
            x[2]=-13;
            iteraciones = 25;
            double matrix_L[3][3] = {{1, 0, 0},{(1/(double)3), 1, 0},{(1/(double)3), (10/(double)13), 1}}; 
            double matrix_U[3][3] = {{6, 5, -5},{0, (13/(double)3), (-1/(double)3)},{0, 0, (12/(double)13)}}; 
            metodos.inverse_power_method( matrix_L, matrix_U, x, iteraciones );

    }

    return 0;
}
