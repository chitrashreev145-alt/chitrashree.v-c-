#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate
using namespace std;

int main() {
    vector<int> nums = {2, 3, 4, 5, 6};

    // 1. Product of all elements (initial value = 1)
    long long product = accumulate(nums.begin(), nums.end(), 1LL,
        [](long long acc, int x) {
            return acc * x;
        });

    // 2. Sum of only the even elements (initial value = 0)
    int evenSum = accumulate(nums.begin(), nums.end(), 0,
        [](int acc, int x) {
            return (x % 2 == 0) ? acc + x : acc;
        });

    cout << "Product of all elements: " << product << endl;
    cout << "Sum of even elements:    " << evenSum << endl;

    return 0;
}
