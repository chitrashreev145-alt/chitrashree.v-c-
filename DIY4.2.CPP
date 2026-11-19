#include <iostream>
using namespace std;

class Stack {
private:
    int* buffer;
    int capacity;
    int topIndex;

public:
    Stack(int cap) : capacity(cap), topIndex(-1) {
        buffer = new int[capacity];
        cout << "Stack allocated with capacity " << capacity << endl;
    }

    ~Stack() {
        delete[] buffer;
        cout << "Stack destructor released buffer." << endl;
    }

    void push(int val) {
        if (topIndex == capacity - 1) {
            cout << "Stack Overflow! Cannot push " << val << endl;
            return;
        }
        buffer[++topIndex] = val;
    }

    int pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return buffer[topIndex--];
    }

    bool isEmpty() const {
        return topIndex == -1;
    }
};

int main() {
    Stack s(3);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40); // Triggers overflow check

    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;

    return 0;
}
