#include <iostream>
using namespace std;

// Function with default exponent = 2
long long power(int base, int exp = 2) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int main() {
    cout << "power(5) = " << power(5) << endl;       // Uses default exp = 2
    cout << "power(2, 10) = " << power(2, 10) << endl; // Uses provided exp = 10

    return 0;
}
