#include <iostream>
#include <numeric>   // For std::gcd
#include <stdexcept>
using namespace std;

class Fraction {
private:
    int num;
    int den;

    void simplify() {
        if (den == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        // Keep negative sign in the numerator
        if (den < 0) {
            num = -num;
            den = -den;
        }
        int common = gcd(abs(num), abs(den));
        num /= common;
        den /= common;
    }

public:
    Fraction(int n = 0, int d = 1) : num(n), den(d) {
        simplify();
    }

    // Overload << for output
    friend ostream& operator<<(ostream& out, const Fraction& f) {
        if (f.den == 1) {
            out << f.num;
        } else {
            out << f.num << "/" << f.den;
        }
        return out;
    }

    // Overload >> for input (expects format: numerator denominator)
    friend istream& operator>>(istream& in, Fraction& f) {
        in >> f.num >> f.den;
        f.simplify();
        return in;
    }
};

int main() {
    Fraction f1(12, 18); // Automatically simplifies to 2/3
    cout << "Constructed fraction (12/18): " << f1 << endl;

    Fraction f2;
    cout << "Enter numerator and denominator (e.g., 15 25): ";
    cin >> f2;
    cout << "Simplified input fraction: " << f2 << endl;

    return 0;
}
