#include <iostream>
using namespace std;

// Inline overload for 2 integers
inline int minVal(int a, int b) {
    return (a < b) ? a : b;
}

// Inline overload for 3 integers
inline int minVal(int a, int b, int c) {
    return minVal(minVal(a, b), c);
}

int main() {
    cout << "Smallest of (15, 8): " << minVal(15, 8) << endl;
    cout << "Smallest of (24, 9, 17): " << minVal(24, 9, 17) << endl;

    return 0;
}
