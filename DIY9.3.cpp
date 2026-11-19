#include <iostream>
#include <exception>

class MathError : public std::exception {
public:
    const char* what() const noexcept override {
        return "Caught Base Class: General MathError";
    }
};

class DivideByZero : public MathError {
public:
    const char* what() const noexcept override {
        return "Caught Derived Class: DivideByZero Error";
    }
};

double divide(double a, double b) {
    if (b == 0) {
        throw DivideByZero();
    }
    return a / b;
}

int main() {
    // 1. INCORRECT ORDER: Base class catches first and hides Derived class
    std::cout << "--- Wrong Catch Order ---\n";
    try {
        divide(10, 0);
    } catch (const MathError& e) {        // Base class intercepts first!
        std::cout << e.what() << '\n';
    } catch (const DivideByZero& e) {     // Unreachable for DivideByZero
        std::cout << e.what() << '\n';
    }

    // 2. FIXED ORDER: Derived class catches first
    std::cout << "\n--- Fixed Catch Order ---\n";
    try {
        divide(10, 0);
    } catch (const DivideByZero& e) {     // Specific handler runs first
        std::cout << e.what() << '\n';
    } catch (const MathError& e) {        // General fallback handler
        std::cout << e.what() << '\n';
    }

    return 0;
}
