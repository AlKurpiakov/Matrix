#pragma once
#include "Vector.h"

template <class T>
class Matrix: public Vector<Vector<T>>
{
private:
    int _deg = 1;
public:
    Matrix(size_t n): Vector<Vector<T>>(n, 0)
    {
        for(size_t i = 0; i<n; i++){
            this->_array[i] = Vector<T>(n-i,i);
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

    void operator/(const T& elem){
        for (int i = 0; i < this->_size; i++){
            this->_array[i] = this->_array[i]/elem;
        }
    }

    void PowTo_1(){
        _deg = -1;
        T det;
        Vector<T> tmp_vec;
        Matrix<double> res(*this);
        for(size_t i = 0;i < this->_size; i++){
            Vector<double> tmp(this->_array[i].GetSize());
            for (size_t j = 0;j < this->_array[i].GetSize(); j++)
                if(i == j){ tmp[j] = 1/res._array[i].GetElem(0);}                
                else if (i != 0 && i != this->GetSize()) {tmp[j] = res._array[i].GetElem(1)/(res._array[i-1].GetElem(0)*res._array[i].GetElem(0)) ;} 
            this->_array[i] = tmp;
        }

    }

    Matrix operator*(const Matrix& mt) {
        if (this->_size != mt._size) {
            throw invalid_argument("Matrices have incompatible sizes for multiplication.");
        }

        Matrix result(this->_size);

        for (size_t i = 0; i < this->_size; i++) { 
            for (size_t j = i; j < this->_size; j++) { 
                T sum = 0;

                for (size_t k = i; k <= j; k++) {
                    if ((k - i) < this->_array[i].GetSize() && (j - k) < mt._array[k].GetSize()) {
                        sum += this->_array[i][k - i] * mt._array[k][j - k];
                    }
                }

                result._array[i][j - i] = sum; 
            }
        }

        return result;
    }

    // ввод / вывод
    friend istream& operator>>(istream& in, Matrix& mt)
    {
        for (int i = 0; i < mt._size; i++)
            in >> mt._array[i];
        return in;
    }
    friend ostream& operator<<(ostream& os, const Matrix& mt)
    {


        for (int i = 0; i < mt._size; i++){
            os << "|";
            for (size_t j = 0; j < i; j++) os << "0 ";
            os << mt._array[i] << "|" << endl;
        }
        

        return os;
    }
};