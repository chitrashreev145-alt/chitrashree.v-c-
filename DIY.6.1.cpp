#include <iostream>
#include <iomanip>
using namespace std;

class Money {
private:
    int rupees;
    int paise;

    // Helper to normalize paise into [0, 99]
    void normalize() {
        int totalPaise = rupees * 100 + paise;
        rupees = totalPaise / 100;
        paise = totalPaise % 100;
        if (paise < 0) {
            paise += 100;
            rupees -= 1;
        }
    }

public:
    Money(int r = 0, int p = 0) : rupees(r), paise(p) {
        normalize();
    }

    // Overload + operator (carry paise >= 100 into rupees)
    Money operator+(const Money& other) const {
        return Money(rupees + other.rupees, paise + other.paise);
    }

    // Overload - operator (borrow 1 rupee = 100 paise if needed)
    Money operator-(const Money& other) const {
        return Money(rupees - other.rupees, paise - other.paise);
    }

    void display() const {
        cout << "Rs. " << rupees << "." << setfill('0') << setw(2) << paise << endl;
    }
};

int main() {
    Money m1(15, 75);
    Money m2(8, 50);

    Money sum = m1 + m2;   // 15.75 + 8.50 = 24.25 (carries 1 rupee)
    Money diff = m1 - m2;  // 15.75 - 8.50 = 7.25
    Money diff2 = m2 - m1; // 8.50 - 15.75 = -7.25 (borrows properly)

    cout << "Sum: ";
    sum.display();

    cout << "Difference (m1 - m2): ";
    diff.display();

    cout << "Difference (m2 - m1): ";
    diff2.display();

    return 0;
}
