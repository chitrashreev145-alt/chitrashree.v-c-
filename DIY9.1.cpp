#include <iostream>
#include <exception>
#include <string>

class InsufficientFunds : public std::exception {
private:
    std::string message;

public:
    InsufficientFunds(double balance, double amount) {
        message = "Error: Insufficient funds! Available: $" + std::to_string(balance) +
                  ", Requested: $" + std::to_string(amount);
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    void deposit(double amount) {
        balance += amount;
        std::cout << "Deposited: $" << amount << " | New Balance: $" << balance << '\n';
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientFunds(balance, amount);
        }
        balance -= amount;
        std::cout << "Withdrew: $" << amount << " | Remaining Balance: $" << balance << '\n';
    }
};

int main() {
    BankAccount account(500.0);

    try {
        account.withdraw(200.0); // Succeeds
        account.withdraw(400.0); // Throws InsufficientFunds
    } catch (const InsufficientFunds& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
