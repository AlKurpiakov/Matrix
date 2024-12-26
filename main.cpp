 #include "Matrix.h"



int main(){
    Matrix<double> y(4);
    cin >> y;
    y.Inverse();
    cout << y << endl;
    return 0;
} 
    