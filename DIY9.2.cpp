#include <iostream>
#include <exception>

class Overflow : public std::exception {
public:
    const char* what() const noexcept override {
        return "Stack Exception: Overflow (Stack is full)";
    }
};

class Underflow : public std::exception {
public:
    const char* what() const noexcept override {
        return "Stack Exception: Underflow (Stack is empty)";
    }
};

class Stack {
private:
    static const int MAX = 3;
    int arr[MAX];
    int top;

public:
    Stack() : top(-1) {}

    void push(int val) {
        if (top >= MAX - 1) {
            throw Overflow();
        }
        arr[++top] = val;
        std::cout << "Pushed: " << val << '\n';
    }

    int pop() {
        if (top < 0) {
            throw Underflow();
        }
        int val = arr[top--];
        std::cout << "Popped: " << val << '\n';
        return val;
    }
};

int main() {
    Stack s;

    // Test Overflow
    try {
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40); // Triggers Overflow
    } catch (const Overflow& e) {
        std::cerr << e.what() << '\n';
    }

    // Test Underflow
    try {
        s.pop();
        s.pop();
        s.pop();
        s.pop(); // Triggers Underflow
    } catch (const Underflow& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
