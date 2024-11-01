#pragma once   

#include <iostream>
#include <vector>

template <class T>
class Vector{
private:
    T* _array;
    size_t _size;
    size_t _startIndex;
public:
    Vector(size_t size, size_t startIndex=0){
    _array = new T[size];
    _size = size;
    _startIndex = startIndex;
    };
    Vector(const Vector& tmp){
        _size = tmp._size;
        _startIndex = tmp._startIndex;
        _array = new T [tmp._size];
        for(int i = 0; i < tmp._size; i++){
            _array[i] = tmp._array[i] ;
        }
    };
    Vector(Vector&& tmp); 
    ~Vector();
    size_t GetSize() const{
       return _size; 
    };
    size_t GetStartIndex() const{
        return _startIndex;
    };
    T& operator[](size_t i){
        return _array[i];
    };
    T& GetElem(size_t i){
        if (i >= _size){
            throw "Out of range";
        }
        return _array[i];
    };
    Vector& operator=(const Vector& tmp);

    bool operator==(const Vector& tmp);

    Vector operator+(const T& tmp) const{
        Vector ans(*this);
        for (size_t i = 0; i < _size; i++)
            ans[i] += tmp;
        return ans;
    };
    Vector operator-(const T& tmp) const{
        Vector ans(*this);
        for (size_t i = 0; i < _size; i++)
            ans[i] -= tmp;
        return ans;
    };
    Vector operator*(const T& tmp) const{
        Vector ans(*this);
        for (size_t i = 0; i < _size; i++)
            ans[i] *= tmp;
        return ans;
    };

    Vector operator+(const Vector& tmp) const;
    Vector operator-(const Vector& tmp) const;
    T operator*(const Vector& tmp) const;
    
};