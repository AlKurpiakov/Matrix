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

     T& At(size_t row, size_t col) {
        if (row > col) {
            throw out_of_range("Accessing elements below the diagonal is not allowed in an upper triangular matrix.");
        }
        return this->_array[row].GetElem(col);
    }

    const T& At(size_t row, size_t col) const {
        if (row > col) {
            throw out_of_range("Accessing elements below the diagonal is not allowed in an upper triangular matrix.");
        }
        return this->_array[row].GetElem(col);
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
    
    Matrix<double> Inverse() const {
        if (this->_size == 0) {
            throw logic_error("Matrix is empty");
        }

        for (size_t i = 0; i < this->_size; ++i) {
            if (At(i, i) == 0) {
                throw logic_error("Matrix is singular and cannot be inverted");
            }
        }

        Matrix<double> inverse(this->_size);
        Vector<double> tmp(this->_size);
        for (int i = this->_size - 1; i >= 0; --i) {
            tmp[i] = 1 / At(i, i);
            for (int j = i + 1; j < this->_size; ++j) {
                T sum = 0;
                for (int k = i + 1; k <= j; ++k) {
                    sum += At(i, k) * inverse.At(k, j);
                }
                inverse.At(i, j) = -sum / At(i, i);
            }
        }

        return inverse;
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