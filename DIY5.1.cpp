#include <iostream>
using namespace std;

class Counter {
private:
    int count;
    static int totalCreated;
    static int currentlyAlive;

public:
    Counter() : count(0) {
        totalCreated++;
        currentlyAlive++;
    }

    // Also track copies if objects are copied
    Counter(const Counter& other) : count(other.count) {
        totalCreated++;
        currentlyAlive++;
    }

    ~Counter() {
        currentlyAlive--;
    }

    void increment() { count++; }
    void reset() { count = 0; }
    int get() const { return count; }

    static int getTotalCreated() { return totalCreated; }
    static int getCurrentlyAlive() { return currentlyAlive; }
};

// Initialize static members outside the class
int Counter::totalCreated = 0;
int Counter::currentlyAlive = 0;

int main() {
    Counter c1, c2;
    cout << "Created: " << Counter::getTotalCreated()
         << ", Alive: " << Counter::getCurrentlyAlive() << endl;

    {
        Counter c3; // Created inside inner block
        cout << "Inside block -> Created: " << Counter::getTotalCreated()
             << ", Alive: " << Counter::getCurrentlyAlive() << endl;
    } // c3 goes out of scope and is destroyed here

    cout << "After block -> Created: " << Counter::getTotalCreated()
         << ", Alive: " << Counter::getCurrentlyAlive() << endl;

    return 0;
}
