#pragma once

#include "Vector.h"

template <class T>
class Matrix: public Vector<Vector<T>>
{
public:
    Matrix(size_t n): Vector<Vector<T>>(n, 0)
    {
        for(size_t i = 0; i<n; i++){
            _array[i] = Vector<T>(n-i,i);
        }
    }
    
    Matrix(const Matrix& mt):Vector<Vector<T>>(mt) {}

    Matrix(const Vector<Vector<T>>& vv):Vector<Vector<T>>(vv) {}

    
    Matrix& operator=(const Matrix& mt){
        return Vector<Vector<T>>::operator=(mt);
    }

    Matrix operator+(const Matrix& mt){
        return Vector<Vector<T>>::operator+(mt);
    }
    Matrix operator-(const Matrix& mt){
        return Vector<Vector<T>>::operator-(mt);
    }

    Matrix operator*(const Matrix& mt){    
        Matrix res(this->_size);
        for (int i = 0; i < this->_size; ++i) {
            for (int j = i; j < this->_size; ++j) { 
                for (int k = i; k <= j; ++k) {
                   res[i][j] += mt[i][k] * this[k][j];
                }
            }
        }
        return res;
    }


    friend istream& operator>>(istream& in, Matrix& mt)
    {
        for (int i = 0; i < mt._size; i++)
            for (int j = 0; j < mt._size; j++){
                in >> mt[i][j];
                if (i > j && mt[i][j] != 0){
                    throw "WRONG MATRIX";
                }
            }
        return in;
    }
    
    friend ostream& operator<<(ostream& os, const Matrix& mt)
    {
        for (int i = 0; i < mt._size; i++){
            os << mt[i];
        }
        return os;
    }
};
