#include<iostream>
#include<string>
using namespace std;
class device{
    protected:
    string id;
    device(string i):id(i){cout <<"device"<<id<<"ctor\n";}
    ~device(){cout<<"device dtor\n";}
    void info() const{cout <<"ID="<<id;}
};
class sensor : public device{
    string type;
    public:
    sensor(string i, string t): device(i),type(t){cout<<"sensor ctor\n";}
    void info() const{device :: info(); cout<<"type="<<type;}
};
class TempSensor : public sensor{
    double celsius;
    public:
    TempSensor(string i, double c): sensor(i,"TEMP"),celsius(c)
        {cout<<"TempSensor ctor\n";}
        void show() const{info(); cout<<"val="<<celsius<<"C\n";}
};
int main(){
    TempSensor t("U1",36.5);
    t.show();
    return 0;
}