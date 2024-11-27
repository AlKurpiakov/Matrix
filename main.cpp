 #include "Matrix.h"

int main(){
    Vector<int> arr(5, 0);
    for (int i = 0; i < 5; i++) arr[i] = i;
    Vector<int> arr2(arr);
    cout << arr << endl << arr2 << endl;
    Vector<int> arr3(move(arr));
    cout << arr3 << "\n";
    Matrix<int> x(3);
    Matrix<int> y(3);
    cin >> x;
    cin >> y;
    cout << x << endl << y << endl;
    cout << x * y;
    return 0;
} 