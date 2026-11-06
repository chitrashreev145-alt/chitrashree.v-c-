#include<iostream>
using namespace std;
class widget{
    int id;
    static int count;
    public:
    widget(){id= ++count;cout<<"created W"<<id<<endl;}
    ~widget(){--count;cout<<"Destroyed W"<<id<<endl;}
    static int alive(){return count;}
};
int main(){
    widget a,b;
    cout<<"alive="<<widget::alive()<<endl;
    {widget c;cout<<"alive="<<widget ::alive()endl;}
    cout<<"alive="<<widget::alive()endl;
    return 0;
}