#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int hours;
    int minutes;

public:
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {}

    void display() const {
        cout << setfill('0') << setw(2) << hours << ":"
             << setfill('0') << setw(2) << minutes;
    }

    // Friend declaration
    friend Time laterOf(Time t1, Time t2);
};

// Friend function definition
Time laterOf(Time t1, Time t2) {
    if (t1.hours > t2.hours) {
        return t1;
    } else if (t1.hours < t2.hours) {
        return t2;
    } else {
        return (t1.minutes >= t2.minutes) ? t1 : t2;
    }
}

int main() {
    Time morning(9, 45);
    Time afternoon(14, 20);

    Time later = laterOf(morning, afternoon);

    cout << "Comparing ";
    morning.display();
    cout << " and ";
    afternoon.display();
    cout << " -> Later time is: ";
    later.display();
    cout << endl;

    return 0;
}
