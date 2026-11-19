#include <iostream>
#include <string>
using namespace std;

class Order {
private:
    int orderId;
    string item;
    static int nextId;

public:
    Order(string itemName) : item(itemName) {
        orderId = nextId++;
    }

    void showOrder() const {
        cout << "Order ID: " << orderId << " | Item: " << item << endl;
    }
};

// Start ID sequence at 1001
int Order::nextId = 1001;

int main() {
    Order o1("Mechanical Keyboard");
    Order o2("Wireless Mouse");
    Order o3("USB-C Hub");

    o1.showOrder();
    o2.showOrder();
    o3.showOrder();

    return 0;
}
