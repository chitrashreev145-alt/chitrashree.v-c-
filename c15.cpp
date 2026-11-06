#include<iostream>
using namespace std;
class distance {
    int feet, inch;
    public:
    distance add (const distance&a,const distance&b){
        int total inch =(a.feet+b.feet)*12+a.inch+b.inch;
        return distance(total inch/12,total inch %12);
    }
};
int main(){
    distance d1(5,8),d2(3,7);
    distance d3 = add(d1,d2);
    d3.show();
    return 0;
}