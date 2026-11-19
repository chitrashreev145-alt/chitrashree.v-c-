#include <iostream>
#include <string>
using namespace std;

// Common Base class
class Person {
protected:
    string name;

public:
    Person(string n = "Unknown") : name(n) {
        cout << "Person constructor called for " << name << endl;
    }

    void showName() const {
        cout << "Name: " << name << endl;
    }
};

// Virtual inheritance ensures only one shared instance of Person
class Student : virtual public Person {
protected:
    int studentId;

public:
    Student(string n, int sId) : Person(n), studentId(sId) {}
};

// Virtual inheritance ensures only one shared instance of Person
class Employee : virtual public Person {
protected:
    int empId;

public:
    Employee(string n, int eId) : Person(n), empId(eId) {}
};

// Most derived class (Diamond bottom)
class TA : public Student, public Employee {
private:
    string course;

public:
    // The most derived class directly initializes the virtual base class
    TA(string n, int sId, int eId, string c) 
        : Person(n), Student(n, sId), Employee(n, eId), course(c) {}

    void display() const {
        showName(); // Unambiguous because Person appears only once
        cout << "Student ID: " << studentId << endl;
        cout << "Employee ID: " << empId << endl;
        cout << "Assisting Course: " << course << endl;
    }
};

int main() {
    TA ta("Rahul Verma", 20245, 908, "Object-Oriented Programming");
    cout << "\n--- TA Details ---" << endl;
    ta.display();

    return 0;
}
