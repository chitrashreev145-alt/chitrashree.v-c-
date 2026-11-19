#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue {
private:
    T* data;
    int capacity;
    int frontIdx;
    int rearIdx;
    int count;

public:
    Queue(int cap = 10) : capacity(cap), frontIdx(0), rearIdx(-1), count(0) {
        data = new T[capacity];
    }

    ~Queue() {
        delete[] data;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    void enqueue(const T& val) {
        if (isFull()) {
            throw overflow_error("Queue is full!");
        }
        rearIdx = (rearIdx + 1) % capacity;
        data[rearIdx] = val;
        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty!");
        }
        frontIdx = (frontIdx + 1) % capacity;
        count--;
    }

    T front() const {
        if (isEmpty()) {
            throw underflow_error("Queue is empty!");
        }
        return data[frontIdx];
    }
};

int main() {
    Queue<string> q(5);

    q.enqueue("Task 1: Compile");
    q.enqueue("Task 2: Link");
    q.enqueue("Task 3: Execute");

    cout << "Front element: " << q.front() << endl;

    q.dequeue();
    cout << "Front after dequeue: " << q.front() << endl;

    q.dequeue();
    cout << "Front after second dequeue: " << q.front() << endl;

    return 0;
}
