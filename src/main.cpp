#include "../include/main.hpp"

int main( int argc, const char* argv[] ){

    Metodos metodos;
    string option = "";
    cout << "\n   Opciones:\n" << endl;
    cout << "       1: 13 [ power_method (1,2,3)T ], 200 Iteraciones" << endl;
    cout << "       2: 26(a) [ power_method (-1,1,1)T ], 28 Iteraciones" << endl;
    cout << "       3: 27(a) [ inverse_power_method ], 25 Iteraciones\n" << endl;
    cout << "Selección: ";
    getline (cin, option);;
     
    if( option == "1" ){

            int n = 3; double *y = new double[n]; double *x= new double[n]; int iteraciones = 200;
            int matrix[3][3] = {{6,5,-5},{2,6,-2},{2,5,-1}}; 
            x[0]=1;
            x[1]=2;
            x[2]=3;
            cout << endl;
            cout << "\n     último r: " << metodos.powerMethod(n,matrix,x,iteraciones,y) << endl;

    }else if( option == "2" ){

            int n = 3; double *y = new double[n]; double *x= new double[n]; int iteraciones = 28;
            int matrix[3][3] = {{6,5,-5},{2,6,-2},{2,5,-1}}; 
            x[0]=-1;
            x[1]=1;
            x[2]=1;
            cout << endl;
            cout << "\n     último r: " << metodos.powerMethod(n,matrix,x,iteraciones,y) << "\n" << endl;

    }else if( option == "3" ){ 
            double matrix[3][3] = {{6,5,-5},{2,6,-2},{2,5,-1}};
            double *x= new double[3];
            int iteraciones = 25;//////////////////////
            x[0]=3;
            x[1]=7;
            x[2]=-13;
            double matrix_L[3][3] = {{1, 0, 0},{(1/(double)3), 1, 0},{(1/(double)3), (10/(double)13), 1}}; 
            double matrix_U[3][3] = {{6, 5, -5},{0, (13/(double)3), (-1/(double)3)},{0, 0, (12/(double)13)}}; 
            //cout << "\n     último r: " << metodos.inverse_power_method( matrix_L, matrix_U, x, iteraciones ) << "\n" << endl;
            cout << "\n     último r: " << metodos.inverse_power_method2( matrix, x, iteraciones ) << "\n" << endl;

    }

    return 0;
}
