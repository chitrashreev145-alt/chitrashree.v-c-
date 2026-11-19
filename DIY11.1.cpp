#include <iostream>
using namespace std;

// Template function to swap two values
template <typename T>
void swapVals(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Template function to find the maximum element in an array
template <typename T>
T findMax(T arr[], int n) {
    T maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    // Test with int
    int x = 10, y = 25;
    cout << "Before swap (int): x = " << x << ", y = " << y << endl;
    swapVals(x, y);
    cout << "After swap (int):  x = " << x << ", y = " << y << endl;

    int intArr[] = {14, 72, 35, 91, 48};
    cout << "Max in int array: " << findMax(intArr, 5) << "\n" << endl;

    // Test with double
    double d1 = 3.14, d2 = 9.81;
    cout << "Before swap (double): d1 = " << d1 << ", d2 = " << d2 << endl;
    swapVals(d1, d2);
    cout << "After swap (double):  d1 = " << d1 << ", d2 = " << d2 << endl;

    double dblArr[] = {4.5, 12.75, 8.2, 19.6};
    cout << "Max in double array: " << findMax(dblArr, 4) << endl;

    return 0;
}
