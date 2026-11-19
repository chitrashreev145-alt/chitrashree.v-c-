#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex() : real(0.0), imag(0.0) {}

    void setData(double r, double i) {
        real = r;
        imag = i;
    }

    void display() const {
        if (imag >= 0) {
            cout << real << " + " << imag << "i" << endl;
        } else {
            cout << real << " - " << -imag << "i" << endl;
        }
    }
};

int main() {
    const int SIZE = 3;
    Complex nums[SIZE];

    nums[0].setData(3.5, 2.0);
    nums[1].setData(4.0, -1.5);
    nums[2].setData(-2.0, 5.0);

    cout << "Complex Numbers:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Number " << i + 1 << ": ";
        nums[i].display();
    }

    return 0;
}
