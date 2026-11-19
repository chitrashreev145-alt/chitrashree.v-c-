#include<iostream>
#include<string>
using namespace std;

template <typename K, typename V>
struct Pair{
    K key; V value;
    void show() const{cout << key <<"->" << value << endl;}
};
 template<typename A, typename B>
 auto bigger(A a,B b) {return (a>b)? a:b;}

 int main(){
    Pair<string,int>P{"ECE",121};
    P.show();
    Pair<int,double> q{7, 3.5};
    q.show();
    cout<<"bigger(3, 9.5) =" << bigger(3, 9.5)<<endl;
    return 0; 
 }