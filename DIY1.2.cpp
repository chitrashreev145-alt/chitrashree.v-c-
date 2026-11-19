#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string word1, word2;
    cout << "Enter first word: ";
    cin >> word1;
    cout << "Enter second word: ";
    cin >> word2;

    if (word1.length() != word2.length()) {
        cout << "Not anagrams." << endl;
        return 0;
    }

    // Convert both words to lowercase for case-insensitive comparison
    for (char &c : word1) c = tolower(c);
    for (char &c : word2) c = tolower(c);

    // Sort characters in both strings
    sort(word1.begin(), word1.end());
    sort(word2.begin(), word2.end());

    if (word1 == word2) {
        cout << "Yes, they are anagrams!" << endl;
    } else {
        cout << "No, they are not anagrams." << endl;
    }

    return 0;
}
