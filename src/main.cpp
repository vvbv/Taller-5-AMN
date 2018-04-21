#include "../include/main.hpp"

int main( int argc, const char* argv[] ){

    Metodos metodos;
    string option = "";
    cout << "\n   Opciones:\n" << endl;
    cout << "       1: 26(a) [ power_method ]" << endl;
    cout << "       2: 27(a) [ inverse_power_method ]\n" << endl;
    cout << "Selección: ";
    getline (cin, option);;
     
    if( option == "1" ){

            int n = 3; double *y = new double[n]; double *x= new double[n]; int iteraciones = 200;
            int matrix[3][3] = {{6,5,-5},{2,6,-2},{2,5,-1}}; 
            x[0]=1;
            x[1]=2;
            x[2]=3;
            cout << endl;
            cout << "Ultimo r: " << metodos.powerMethod(n,matrix,x,iteraciones,y) << endl;

    }else if( option == "2" ){ 
            double matrix[3][3] = {{6,5,-5},{2,6,-2},{2,5,-1}};
            double *x= new double[3];
            int iteraciones = 200;
            x[0]=3;
            x[1]=7;
            x[2]=-13;
            iteraciones = 1;   
            double matrix_L[3][3] = {{1, 0, 0},{(1/(double)3), 1, 0},{(1/(double)3), (10/(double)13), 1}}; 
            double matrix_U[3][3] = {{6, 5, -5},{0, (13/(double)3), (-1/(double)3)},{0, 0, (12/(double)13)}}; 
            metodos.inverse_power_method( matrix_L, matrix_U, x, iteraciones );
            metodos.inverse_power_method2( matrix, x,iteraciones);

    }

    return 0;
}
