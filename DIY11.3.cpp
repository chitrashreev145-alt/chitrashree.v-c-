#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

int main() {
    string line;
    cout << "Enter words separated by spaces: ";
    getline(cin, line);

    unordered_map<string, int> freq;
    stringstream ss(line);
    string word;

    while (ss >> word) {
        freq[word]++;
    }

    if (freq.empty()) {
        cout << "No words entered." << endl;
        return 0;
    }

    cout << "\nWord Frequencies:" << endl;
    string mostFreqWord;
    int maxCount = 0;

    for (const auto& pair : freq) {
        cout << pair.first << ": " << pair.second << endl;
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostFreqWord = pair.first;
        }
    }

    cout << "\nMost frequent word: \"" << mostFreqWord
         << "\" (" << maxCount << " times)" << endl;

    return 0;
}
