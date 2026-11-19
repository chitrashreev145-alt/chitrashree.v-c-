#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <cmath>
using namespace std;

// Abstract Base Class
class Shape {
public:
    virtual double area() const = 0;
    virtual string name() const = 0;
    virtual ~Shape() = default; // Essential virtual destructor for polymorphism
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return M_PI * radius * radius; }
    string name() const override { return "Circle"; }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
    string name() const override { return "Rectangle"; }
};

class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() const override { return 0.5 * base * height; }
    string name() const override { return "Triangle"; }
};

// Factory function returning a unique_ptr<Shape>
unique_ptr<Shape> createShape(const string& type) {
    if (type == "circle") {
        double r;
        cout << "Enter radius: ";
        cin >> r;
        return make_unique<Circle>(r);
    } else if (type == "rectangle") {
        double w, h;
        cout << "Enter width and height: ";
        cin >> w >> h;
        return make_unique<Rectangle>(w, h);
    } else if (type == "triangle") {
        double b, h;
        cout << "Enter base and height: ";
        cin >> b >> h;
        return make_unique<Triangle>(b, h);
    }
    return nullptr;
}

int main() {
    vector<unique_ptr<Shape>> shapes;
    string choice;

    while (true) {
        cout << "\nEnter shape (circle / rectangle / triangle) or 'done': ";
        cin >> choice;
        if (choice == "done") break;

        unique_ptr<Shape> s = createShape(choice);
        if (s) {
            shapes.push_back(move(s)); // Transfer ownership into the vector
        } else {
            cout << "Unknown shape type." << endl;
        }
    }

    cout << "\n--- Created Shapes ---" << endl;
    for (const auto& s : shapes) {
        cout << s->name() << " -> Area: " << s->area() << endl;
    }

    return 0; // All shapes are automatically destroyed here
}
