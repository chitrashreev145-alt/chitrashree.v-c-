#include<iostream>
#include<string>
using namespace std;
class logger{
    logger(){}
    public:
    logger(const logger&) = delete;
    void operator = (const logger&) = delete;
    static logger& get() {
        static logger instance;
        return instance;
    }
    void log(const string &m) {cout << "[LOG]" << m << endl;}
};
int main(){
    logger::get().log("system up");
    logger::get().log("same single instance");
    return 0;
}