 #include "Matrix.h"

int main(){
    Matrix<double> x(3);
    cin >> x;
    x = x.PowTo_1();    
    cout << x << endl;
    return 0;
} 