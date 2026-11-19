#include <iostream>

class Base {
public:
    Base() { std::cout << "Base constructor\n"; }

    // BUGGY VERSION (causes memory leak):
    // ~Base() { std::cout << "Base destructor\n"; }

    // FIXED VERSION (calls Derived destructor first):
    virtual ~Base() { std::cout << "Base destructor\n"; }
};

class Derived : public Base {
private:
    int* data;

public:
    Derived() {
        std::cout << "Derived constructor (allocating memory)\n";
        data = new int[100]; // Dynamic allocation
    }

    ~Derived() {
        std::cout << "Derived destructor (freeing memory)\n";
        delete[] data;
    }
};

int main() {
    Base* ptr = new Derived();
    delete ptr; // Without 'virtual ~Base()', ~Derived() is skipped!
    return 0;
}
