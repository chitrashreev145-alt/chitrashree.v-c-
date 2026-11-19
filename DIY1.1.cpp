#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    cout << "Enter a sentence: ";
    getline(cin, s);

    int vowels = 0, consonants = 0;

    for (char ch : s) {
        if (isalpha(ch)) {
            char lower = tolower(ch);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;

    return 0;
}
