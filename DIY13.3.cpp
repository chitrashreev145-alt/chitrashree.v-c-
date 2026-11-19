#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

long long counter = 0;
mutex mtx;

void incrementWithLock(int iterations) {
    for (int i = 0; i < iterations; i++) {
        lock_guard<mutex> lock(mtx); // Comment this line out to observe the race condition
        counter++;
    }
}

int main() {
    const int ITERATIONS = 100000;

    thread t1(incrementWithLock, ITERATIONS);
    thread t2(incrementWithLock, ITERATIONS);

    t1.join();
    t2.join();

    cout << "Expected total: " << (2 * ITERATIONS) << endl;
    cout << "Actual total:   " << counter << endl;

    return 0;
}
