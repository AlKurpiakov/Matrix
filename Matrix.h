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
    //
    Matrix(const Matrix& mt):Vector<Vector<T>>(mt) {}

    Matrix(const Vector<Vector<T>>& vv):Vector<Vector<T>>(mt){}
    Matrix& operator=(const Matrix& mt);
    Matrix operator+(const Matrix& mt){
        return Vector<Vector<T>>::operator+(mt);
    }
    Matrix operator-(const Matrix& mt){
        return Vector<Vector<T>>::operator-(mt);
    }
    Matrix operator*(const Matrix& mt);
};