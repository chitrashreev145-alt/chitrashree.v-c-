#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int marks;

public:
    Student() : name(""), marks(0) {}
    Student(string n, int m) : name(n), marks(m) {}

    void setData(string n, int m) {
        name = n;
        marks = m;
    }

    string getName() const { return name; }
    int getMarks() const { return marks; }
};

int main() {
    // Step 1: Store name-marks pairs in a file
    ofstream outFile("students.txt");
    if (!outFile) {
        cerr << "Error creating students.txt" << endl;
        return 1;
    }
    outFile << "Ananya 88\n";
    outFile << "Rohan 95\n";
    outFile << "Meera 91\n";
    outFile << "Vikram 84\n";
    outFile.close();

    // Step 2: Read records back into an array of Student objects
    const int MAX_STUDENTS = 50;
    Student students[MAX_STUDENTS];
    int count = 0;

    ifstream inFile("students.txt");
    if (!inFile) {
        cerr << "Error opening students.txt" << endl;
        return 1;
    }

    string name;
    int marks;
    while (count < MAX_STUDENTS && (inFile >> name >> marks)) {
        students[count].setData(name, marks);
        count++;
    }
    inFile.close();

    // Step 3: Find and print the topper
    if (count > 0) {
        int topperIndex = 0;
        for (int i = 1; i < count; i++) {
            if (students[i].getMarks() > students[topperIndex].getMarks()) {
                topperIndex = i;
            }
        }

        cout << "Topper: " << students[topperIndex].getName()
             << " with " << students[topperIndex].getMarks() << " marks." << endl;
    }

    return 0;
}
