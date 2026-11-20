#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

// Function Template to calculate total marks
template <typename T>
T calculateTotal(T m1, T m2, T m3) {
    return m1 + m2 + m3;
}

// Base Class: Student
class Student {
protected:
    int rollNo;
    string name;

public:
    Student(int r = 0, string n = "") : rollNo(r), name(n) {}

    // Virtual function for Runtime Polymorphism
    virtual void display() const {
        cout << "Roll No: " << rollNo << " | Name: " << name;
    }

    int getRollNo() const { return rollNo; }
    string getName() const { return name; }

    virtual ~Student() {} // Virtual destructor
};

// Derived Class: Result (Inheritance)
class Result : public Student {
private:
    float sub1, sub2, sub3;
    float totalMarks;
    string status;

public:
    Result(int r, string n, float m1, float m2, float m3) : Student(r, n) {
        // Exception Handling for invalid marks
        if (m1 < 0 || m1 > 100 || m2 < 0 || m2 > 100 || m3 < 0 || m3 > 100) {
            throw invalid_argument("Marks must be between 0 and 100!");
        }
        sub1 = m1;
        sub2 = m2;
        sub3 = m3;
        totalMarks = calculateTotal(sub1, sub2, sub3); // Using Template
        status = (sub1 >= 40 && sub2 >= 40 && sub3 >= 40) ? "PASS" : "FAIL";
    }

    // Overriding virtual function
    void display() const override {
        Student::display();
        cout << " | Marks: [" << sub1 << ", " << sub2 << ", " << sub3 << "]"
             << " | Total: " << totalMarks << "/300"
             << " | Result: " << status << endl;
    }

    float getTotalMarks() const { return totalMarks; }

    // Format data for saving to file
    string toFileString() const {
        return to_string(rollNo) + " " + name + " " + 
               to_string(sub1) + " " + to_string(sub2) + " " + to_string(sub3);
    }
};

// File Handling: Save records to file
void saveToFile(const vector<Result>& records, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        throw runtime_error("Unable to open file for writing.");
    }
    for (const auto& rec : records) {
        outFile << rec.toFileString() << endl;
    }
    outFile.close();
}

// File Handling: Retrieve records from file
vector<Result> loadFromFile(const string& filename) {
    vector<Result> loadedRecords;
    ifstream inFile(filename);
    if (!inFile) {
        throw runtime_error("Unable to open file for reading.");
    }
    int r;
    string n;
    float m1, m2, m3;
    while (inFile >> r >> n >> m1 >> m2 >> m3) {
        loadedRecords.emplace_back(r, n, m1, m2, m3);
    }
    inFile.close();
    return loadedRecords;
}

int main() {
    // STL Container: vector to store student records
    vector<Result> studentRecords;
    string filename = "student_results.txt";

    cout << "--- Adding Student Records ---" << endl;
    try {
        studentRecords.emplace_back(101, "Aarav", 85.0, 90.0, 88.0);
        studentRecords.emplace_back(102, "Diya", 92.0, 95.0, 94.0);
        studentRecords.emplace_back(103, "Rohan", 65.0, 70.0, 68.0);
        
        // Triggering Exception Handling with invalid marks
        studentRecords.emplace_back(104, "Sneha", 105.0, 80.0, 75.0); 
    } catch (const exception& e) {
        cout << "[Exception Caught] Error adding record: " << e.what() << "\n\n";
    }

    // Saving and Retrieving via File Handling
    try {
        saveToFile(studentRecords, filename);
        cout << "Records successfully saved to '" << filename << "'.\n\n";

        vector<Result> retrievedRecords = loadFromFile(filename);

        // Demonstrating Runtime Polymorphism using Base class pointer
        cout << "--- All Student Results (Retrieved from File) ---" << endl;
        for (const auto& rec : retrievedRecords) {
            const Student* basePtr = &rec;
            basePtr->display(); // Calls Result::display() dynamically
        }

        // Using STL Algorithm (for_each) + Lambda Expression to filter high scorers
        float threshold = 250.0;
        cout << "\n--- Students Scoring Above " << threshold << " Marks ---" << endl;
        for_each(retrievedRecords.begin(), retrievedRecords.end(), [threshold](const Result& r) {
            if (r.getTotalMarks() > threshold) {
                r.display();
            }
        });

    } catch (const exception& e) {
        cout << "[File Error] " << e.what() << endl;
    }

    return 0;
}
