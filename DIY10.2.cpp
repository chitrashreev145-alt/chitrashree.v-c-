#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile("in.txt");
    ofstream outFile("out.txt");

    if (!inFile) {
        cerr << "Error: Could not open in.txt" << endl;
        return 1;
    }
    if (!outFile) {
        cerr << "Error: Could not create out.txt" << endl;
        return 1;
    }

    string line;
    int lineNum = 1;

    while (getline(inFile, line)) {
        outFile << lineNum << ": " << line << "\n";
        lineNum++;
    }

    inFile.close();
    outFile.close();

    cout << "Successfully copied " << (lineNum - 1) << " lines to out.txt." << endl;

    return 0;
}
