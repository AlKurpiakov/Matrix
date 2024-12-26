#include "Matrix.h"

template <typename T>
class NOTriangleMatrix : public Vector<Vector<T>>{
private:

    
    // NOTriangleMatrix<T> GetSubMatrix(const NOTriangleMatrix<T>& mt, int excludedRow, int excludedCol) {
    //     NOTriangleMatrix<T> subMatrix(mt._size - 1);
    //     for (size_t i = 0; i < mt._size; i++) {
    //         if (i == excludedRow) continue;
    //         Vector<T> row;
    //         for (size_t j = 0; j < mt._size; j++) {
    //             if (j == excludedCol) continue;
    //             row[j] = mt._array[i].GetElem(j);
    //         }
    //         subMatrix._array[i] = row;
    //     }
    //     return subMatrix;
    // }
    
    // double CalculateDeterminant(const NOTriangleMatrix<double> &mt) {
    //     if (mt._size == 1) {
    //         return mt._array[0].GetElem(0);
    //     }

    //     if (mt._size == 2) {
    //         return mt._array[0].GetElem(0) * mt._array[0].GetElem(1) - mt._array[1].GetElem(0) * mt._array[1].GetElem(1);
    //     }

    //     double determinant = 0.0;
    //         for (int j = 0; j < mt._size; ++j) {
    //             NOTriangleMatrix<T> subMatrix = GetSubMatrix(mt, 0, j);
    //             determinant += pow(-1, j) * mt._array[0].GetElem(j) * CalculateDeterminant(subMatrix);
    //         }

    //     return determinant;
    // }
    void getMinor(const NOTriangleMatrix<double>&matrix, int row, int col) {
    int size = matrix.GetSize();
    NOTriangleMatrix<double> minor(size - 1);
    int minorRow = 0;
    for (int i = 0; i < size; ++i) {
        if (i == row) continue;
        int minorCol = 0;
        for (int j = 0; j < size; ++j) {
            if (j == col) continue; 
            minor[i][j] = matrix._array[i].GetElem(j);
        }
    }
    
    for(size_t i = 0; i < minor.GetSize(); i++){
        this->_array[i] = minor._array[i];
    }
}

double determinant(){
    int size = this->GetSize();
    
    if (size == 1) return  this->_array[0].GetElem(0);
    
    if (size == 2) 
        return this->_array[0].GetElem(0) * this->_array[0].GetElem(1) - this->_array[1].GetElem(0) * this->_array[1].GetElem(1);
    
    double det = 0;
    for (int j = 0; j < size; ++j) {
        double cofactor =  this->_array[0].GetElem(j);
        NOTriangleMatrix<double> minor(this->GetSize());
        minor.getMinor(*this, 0, j);
        det += (j % 2 == 0 ? 1 : -1) * cofactor * minor.determinant();
    }
    return det;
}

public:

    NOTriangleMatrix(size_t n): Vector<Vector<T>>(n, 0){
        for(size_t i = 0; i < n; i++){
            this->_array[i] = Vector<T>(n, 0);
        }
    }

    NOTriangleMatrix(const NOTriangleMatrix& n): Vector<Vector<T>>(n.GetSize(), 0){
        for(size_t i = 0; i < n.GetSize(); i++){
            this->_array[i] = n._array[i];
        }
    }
    NOTriangleMatrix(const Vector<Vector<T>>& vv):Vector<Vector<T>>(vv) {}

    NOTriangleMatrix(const Matrix<T>& mt): Vector<Vector<T>>(mt.GetSize(), 0) {
        for(size_t i = 0; i < mt.GetSize(); i++){
            this->_array[i] = Vector<T>(mt.GetSize(), 0);
        }
        Vector<T> tmp(this->_size);
        for (size_t i = 0; i < this->_size; i++){
            for (size_t j = 0; j < this->_size; j++){
                if (i <= j) tmp[j] = mt._array[i].GetElem(this->_size  - 1 - j);
                else tmp[j] = 0;
            }
            this->_array[i] = tmp;
        }
    }


    NOTriangleMatrix<T> operator=(const Matrix<T>& mt){
        NOTriangleMatrix res(*mt)
        Vector tmp(res._size);
        for (size_t i = 0; i < res._size; i++){
            for (size_t j = 0; j < res._size; j++){
                if (i >= j) tmp[j] = mt._array[i].GetElem();
                else tmp[j] = 0;
            }
            res._array[i] = tmp;
        }

        return res
    }

    NOTriangleMatrix<T> operator=(const NOTriangleMatrix<T>& nmt){
        NOTriangleMatrix<T> res(nmt.GetSize());
        Vector<T> tmp(res._size);
        for (size_t i = 0; i < res._size; i++){
            res[i] = this->_array[i];
        }
        return res;
    }

    
    
    void PowTo_1(){
        NOTriangleMatrix<double> res(*this);
        NOTriangleMatrix<double> DetMat(this->_size - 1);
        double det = 1, detTmp = 1;

        for (size_t i = 0; i < this->_size; i++){ det *= res._array[i][i]; }

        for (size_t i = 0; i < this->_size; i++) {
            Vector<T> tmp(this->_array[i].GetSize());

            for (size_t j = 0; j < this->_array[i].GetSize(); j++) {
                if (j == i) {
                    tmp[i] = 1 / res._array[i].GetElem(i); 
                    continue; 
                }
                
                DetMat.getMinor(*this, this->_size - i, this->_size - j);
                cout<<"bebra";
                detTmp = DetMat.determinant();
                tmp[j] = 0/det;
            }
            this->_array[i] = tmp;
        }
        
    }

};
