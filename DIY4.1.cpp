#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int** data;

public:
    // Parameterized constructor: allocates m x n grid
    Matrix(int m, int n) : rows(m), cols(n) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols]{0};
        }
    }

    // Deep copy constructor
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
        cout << "[Deep Copy Constructor Called]" << endl;
    }

    // Destructor: frees each row, then the row-pointer array
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
        cout << "[Matrix Destructor Freed Memory]" << endl;
    }

    void set(int r, int c, int val) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            data[r][c] = val;
        }
    }

    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix m1(2, 2);
    m1.set(0, 0, 10);
    m1.set(1, 1, 20);

    // Invokes deep copy constructor
    Matrix m2 = m1;
    m2.set(0, 0, 99); // Modifying m2 does not affect m1

    cout << "Matrix 1:" << endl;
    m1.print();

    cout << "Matrix 2 (Modified Copy):" << endl;
    m2.print();

    return 0;
}
