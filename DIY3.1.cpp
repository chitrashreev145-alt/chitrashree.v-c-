#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    // Default constructor
    Rectangle() : length(0.0), width(0.0) {}

    // Setter for length with validation
    void setLength(double l) {
        if (l >= 0) {
            length = l;
        } else {
            cout << "Error: Length cannot be negative (" << l << " rejected)." << endl;
        }
    }

    // Setter for width with validation
    void setWidth(double w) {
        if (w >= 0) {
            width = w;
        } else {
            cout << "Error: Width cannot be negative (" << w << " rejected)." << endl;
        }
    }

    // Getters for area and perimeter
    double area() const {
        return length * width;
    }

    double perimeter() const {
        return 2 * (length + width);
    }
};

int main() {
    Rectangle rect;

    rect.setLength(10.5);
    rect.setWidth(4.0);
    rect.setWidth(-3.0); // Rejected by validation

    cout << "Area: " << rect.area() << endl;
    cout << "Perimeter: " << rect.perimeter() << endl;

    return 0;
}
