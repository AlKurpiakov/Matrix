#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
class Vector{
protected:
    T* _array;
    size_t _size;
    size_t _startIndex;
public:

    Vector() : _size(10), _startIndex(0){
        _array = new T[_size];
        for (int i = 0; i < _size; i++)
            _array[i] = 0;
        
    }

    Vector(size_t size, size_t startIndex){
        _array = new T[size];
        _size = size;
        _startIndex = startIndex;
        for (int i = 0; i < _size; i++){
            _array[i] = 0;
        }
    }

    Vector(size_t size) : _size(size), _startIndex(0){
        _array = new T[_size];
        for (int i = 0; i < _size; i++){
            _array[i] = 0;
        }
    }
    Vector(size_t size, size_t startIndex, T* array) : _size(size), _array(new T[size]), _startIndex(startIndex){
        for (int i = 0; i < _size; i++){
            _array[i] = array[i];
        }
    }

    Vector(const Vector<T>& tmp) : _size(tmp._size), _array(new T[tmp._size]){
        for (int i = 0; i < _size; i++){
            _array[i] = tmp._array[i];
        }
    }

    Vector(Vector<T>&& vec) noexcept : _array(vec._array), _size(vec._size), _startIndex(vec._startIndex) {
        vec._array = nullptr;
        vec._size = 0;
        vec._startIndex = 0;
    }

    ~Vector(){
        delete [] _array;
        _array = nullptr;
    }

    size_t GetSize() const{
       return _size; 
    }

    size_t GetStartIndex() const{
        return _startIndex;
    }

    T& GetElem(size_t i){
        if (i >= _size){
            throw "Out of range";
        }
        return _array[i];
    }

    T& operator[](size_t i){
        return _array[i];
    }

    Vector& operator=(const Vector& tmp){
        _size = tmp._size;
        _startIndex = tmp._startIndex;
        delete [] _array;
        _array = nullptr;
        _array = new T[_size];
        for (int i = 0; i < _size; i++){
            _array[i] = tmp._array[i];
        }
        return *this;
    }

    bool operator==(const Vector& tmp){
        if (_size == tmp._size)
            for (int i = 0; i < size; i++)
            if (tmp._array[i] != _array[i]) return 0;
        else return 0;
        return 1;
    }

    Vector operator+( T& tmp) {
        Vector ans(*this);
        for (size_t i = 0; i < _size; i++)
            ans[i] += tmp;
        return ans;
    }

    Vector operator-( T& tmp) {
        Vector ans(*this);
        for (size_t i = 0; i < _size; i++)
            ans[i] -= tmp;
        return ans;
    }

    Vector operator*( T& tmp) {
        Vector res(*this);
        for (size_t i = 0; i < _size; i++)
            res[i] *= tmp;
        return res;
    }

    Vector operator+(const T& elem) {
        Vector ans(*this);
        for (size_t i = 0; i < _size; i++)
            ans[i] += tmp;
        return ans;
    };
    Vector operator-(const T& elem) {
        Vector res(*this);
        for (size_t i = 0; i < _size; i++)
            res[i] -= tmp;
        return res;
    };

    Vector operator*(const T& elem) {
        Vector res(*this);
        for (size_t i = 0; i < _size; i++)
            res[i] *= tmp;
        return res;
    };


    friend istream& operator>>(istream& in, Vector& vec)
    {
        for (int i = 0; i < vec._size; i++)
            in >> vec._array[i];
        return in;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector& tmp){

        for (int i = 0; i < tmp._size; i++){
            os << tmp._array[i];
            if (i + 1 != tmp._size) os << " ";
        }
        return os;
    }


   
};

