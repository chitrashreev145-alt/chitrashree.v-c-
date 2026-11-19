#include <iostream>
#include <memory>
using namespace std;

class Tracer {
private:
    int id;

public:
    Tracer(int i) : id(i) {
        cout << "Tracer #" << id << " constructed via make_unique." << endl;
    }

    ~Tracer() {
        cout << "Tracer #" << id << " destroyed automatically." << endl;
    }
};

int main() {
    for (int i = 1; i <= 3; i++) {
        unique_ptr<Tracer> t = make_unique<Tracer>(i);
        // No delete needed: t's destructor frees the heap memory at the end of each iteration
    }

    return 0;
}
