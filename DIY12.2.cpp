#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main() {
    int n;
    cout << "Enter count of numbers (N): ";
    cin >> n;

    // Min-heap to keep track of the 3 largest numbers seen so far
    priority_queue<int, vector<int>, greater<int>> minHeap;

    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        minHeap.push(val);
        if (minHeap.size() > 3) {
            minHeap.pop(); // Evict the smallest of the 4
        }
    }

    cout << "Top 3 largest numbers: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;

    return 0;
}
