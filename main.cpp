 #include "NOTriangleMatrix.h"


Matrix<double> Converter(NOTriangleMatrix<double> ntm){
    Matrix<double> resmt(ntm.GetSize());
    for(size_t i = 0; i < ntm.GetSize(); i++){
        Vector<double> tmp(ntm.GetSize() - i);
        for (size_t j = i; j < ntm.GetSize(); j++){
            tmp[j-i] = ntm._array[i].GetElem(j);
        }
        resmt[i] = tmp;
    }
    return resmt;
}



int main(){
    Matrix<double> y(4);
    cin >> y;
    NOTriangleMatrix<double> x(y);
    cout << y << endl;
    x.PowTo_1();
    cout << Converter(x) << endl;
    return 0;
} 
    