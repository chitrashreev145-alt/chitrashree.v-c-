#include <iostream>
#include <fstream>
#include <string>

class Logger {
public:
    virtual ~Logger() {}
    virtual void write(const std::string& message) = 0;
};

class ConsoleLogger : public Logger {
public:
    void write(const std::string& message) override {
        std::cout << "[Console] " << message << '\n';
    }
};

class FileLogger : public Logger {
private:
    std::ofstream outFile;

public:
    FileLogger(const std::string& filename) {
        outFile.open(filename, std::ios::app);
    }

    ~FileLogger() override {
        if (outFile.is_open()) {
            outFile.close();
        }
    }

    void write(const std::string& message) override {
        if (outFile.is_open()) {
            outFile << "[File] " << message << '\n';
        } else {
            std::cerr << "Error: Unable to write to log file.\n";
        }
    }
};

int main() {
    ConsoleLogger consoleLog;
    FileLogger fileLog("app.log");

    // Start with ConsoleLogger
    Logger* activeLogger = &consoleLog;
    activeLogger->write("Application started.");

    // Switch to FileLogger at runtime
    int choice;
    std::cout << "Enter 1 for Console or 2 for File logging: ";
    std::cin >> choice;

    if (choice == 2) {
        activeLogger = &fileLog;
    } else {
        activeLogger = &consoleLog;
    }

    activeLogger->write("User selected logging mode.");

    return 0;
}
