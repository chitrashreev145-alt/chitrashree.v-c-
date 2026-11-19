#include <iostream>
using namespace std;

const double PI = 3.141592653589793;

// 1 argument: Volume of a cube (side^3)
double volume(double side) {
    return side * side * side;
}

// 3 arguments: Volume of a cuboid (length * width * height)
double volume(double length, double width, double height) {
    return length * width * height;
}

// 2 arguments: Volume of a cylinder (pi * radius^2 * height)
double volume(double radius, double height) {
    return PI * radius * radius * height;
}

int main() {
    cout << "Volume of Cube (side = 4): " << volume(4.0) << endl;
    cout << "Volume of Cuboid (3 x 4 x 5): " << volume(3.0, 4.0, 5.0) << endl;
    cout << "Volume of Cylinder (r = 2, h = 7): " << volume(2.0, 7.0) << endl;

    return 0;
}
