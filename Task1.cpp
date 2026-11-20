#include <iostream>
#include <cstring>

using namespace std;

class Student {
private:
    // Encapsulated private data members
    char* name;        // Dynamic memory allocation for name
    int rollNo;
    float marks;

    // Static member to count total number of Student objects
    static int studentCount;

public:
    // Parameterized Constructor
    Student(const char* studentName, int roll, float studentMarks) {
        name = new char[strlen(studentName) + 1]; // Dynamic memory allocation
        strcpy(name, studentName);
        rollNo = roll;
        marks = studentMarks;
        studentCount++; // Increment count when a student is created
    }

    // Destructor to free dynamically allocated memory
    ~Student() {
        delete[] name;
        studentCount--;
    }

    // Function Overloading: Display basic details
    void display() const {
        cout << "Roll No: " << rollNo << " | Name: " << name << endl;
    }

    // Function Overloading: Display details with or without marks
    void display(bool showMarks) const {
        cout << "Roll No: " << rollNo << " | Name: " << name;
        if (showMarks) {
            cout << " | Marks: " << marks;
        }
        cout << endl;
    }

    // Static member function to access static variable
    static int getStudentCount() {
        return studentCount;
    }

    // Operator Overloading (>) to compare two students based on marks
    bool operator>(const Student& other) const {
        return this->marks > other.marks;
    }

    // Friend function declaration to access private members
    friend void showStudentSummary(const Student& s);
};

// Initialize static member outside the class
int Student::studentCount = 0;

// Friend function definition
void showStudentSummary(const Student& s) {
    cout << "[Friend Function Report] Student '" << s.name 
         << "' (Roll #" << s.rollNo << ") scored " << s.marks << " marks." << endl;
}

int main() {
    cout << "Initial Student Count: " << Student::getStudentCount() << "\n\n";

    // Creating Student objects using parameterized constructor
    Student s1("Aarav Sharma", 101, 88.5);
    Student s2("Diya Patel", 102, 92.0);

    cout << "Total Students Enrolled: " << Student::getStudentCount() << "\n\n";

    // Demonstrating Function Overloading
    cout << "--- Basic Info (Overloaded Function 1) ---" << endl;
    s1.display();
    s2.display();

    cout << "\n--- Detailed Info (Overloaded Function 2) ---" << endl;
    s1.display(true);
    s2.display(true);

    // Demonstrating Friend Function
    cout << "\n--- Friend Function Output ---" << endl;
    showStudentSummary(s1);
    showStudentSummary(s2);

    // Demonstrating Overloaded '>' Operator
    cout << "\n--- Comparing Marks using '>' Operator ---" << endl;
    if (s1 > s2) {
        cout << "Student 1 has higher marks than Student 2." << endl;
    } else if (s2 > s1) {
        cout << "Student 2 has higher marks than Student 1." << endl;
    } else {
        cout << "Both students have equal marks." << endl;
    }

    return 0;
}
