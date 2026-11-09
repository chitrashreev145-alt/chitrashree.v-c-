#include<iostream>
#include<memory>
#include<string>
using namespace std;
 struct shape {
    virtual double area() cons = 0;
    virtual ~shape() {}
 };
 struct circle : shape {double r;circle(doublr r):r(r){}
    double area() const override{return 3.14159*r*r;}};
 struct square : shape {double s;square (double s):s(s){}
    dounle area() const override {return s*s;}};
     
unique_ptr<shape> makeshape(const string &kind) {
    if (kind == "circle") return make_unique<cicle>(2.0);
    return make_unique<square>(3.0);
}
int main(){
    auto a = makeshape("circle");
    auto b = makeshape("square");
    cout << "area a = " <<a->area() << ", area b = " << b->area() << endl;
    retuen 0;
}