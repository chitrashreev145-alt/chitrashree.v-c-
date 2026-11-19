#include <iostream>

class Account {
protected:
    double balance;

public:
    Account(double initialBalance) : balance(initialBalance) {}
    virtual ~Account() {} // Virtual destructor for safe cleanup

    // Pure virtual function
    virtual double calculateInterest() const = 0;

    double getBalance() const { return balance; }
};

class Savings : public Account {
private:
    double interestRate; // e.g., 0.04 for 4%

public:
    Savings(double initialBalance, double rate = 0.04)
        : Account(initialBalance), interestRate(rate) {}

    double calculateInterest() const override {
        return balance * interestRate;
    }
};

class Current : public Account {
private:
    double interestRate; // e.g., 0.01 for 1%

public:
    Current(double initialBalance, double rate = 0.01)
        : Account(initialBalance), interestRate(rate) {}

    double calculateInterest() const override {
        return balance * interestRate;
    }
};

int main() {
    const int SIZE = 3;
    Account* accounts[SIZE];

    accounts[0] = new Savings(1000.0);        // 4% interest
    accounts[1] = new Current(2500.0);        // 1% interest
    accounts[2] = new Savings(5000.0, 0.05);  // Custom 5% interest

    for (int i = 0; i < SIZE; ++i) {
        std::cout << "Account " << i + 1
                  << " | Balance: $" << accounts[i]->getBalance()
                  << " | Interest: $" << accounts[i]->calculateInterest() << '\n';
    }

    // Free allocated memory
    for (int i = 0; i < SIZE; ++i) {
        delete accounts[i];
    }

    return 0;
}
