#include <iostream>
using namespace std;

class Tracer {
private:
    int id;

public:
    Tracer(int i) : id(i) {
        cout << "Tracer #" << id << " constructed on heap." << endl;
    }

    ~Tracer() {
        cout << "Tracer #" << id << " destroyed." << endl;
    }
};

int main() {
    for (int i = 1; i <= 3; i++) {
        Tracer* t = new Tracer(i);

        // Comment out the line below to trigger a memory leak with AddressSanitizer
        delete t;
    }

    return 0;
}
