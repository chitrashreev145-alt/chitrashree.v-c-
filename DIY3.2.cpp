#include <iostream>
using namespace std;

class Counter {
private:
    int count;

public:
    // Default constructor initializes count to 0
    Counter() : count(0) {}

    void increment() {
        count++;
    }

    void reset() {
        count = 0;
    }

    int get() const {
        return count;
    }
};

int main() {
    Counter counters[3]; // Array of 3 Counter objects

    // Exercise Counter 0
    counters[0].increment();
    counters[0].increment();

    // Exercise Counter 1
    counters[1].increment();
    counters[1].increment();
    counters[1].increment();
    counters[1].reset();
    counters[1].increment();

    // Exercise Counter 2
    for (int i = 0; i < 5; i++) {
        counters[2].increment();
    }

    // Display values of all 3 counters
    for (int i = 0; i < 3; i++) {
        cout << "Counter[" << i << "] value: " << counters[i].get() << endl;
    }

    return 0;
}
