#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<string, int>> items = {
        {"Alice", 85},
        {"Bob", 72},
        {"Charlie", 95},
        {"Diana", 68}
    };

    // Sort ascending by the second (int) field
    sort(items.begin(), items.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second;
    });

    cout << "Sorted pairs (ascending by integer):" << endl;
    for (const auto& p : items) {
        cout << p.first << ": " << p.second << endl;
    }

    return 0;
}
