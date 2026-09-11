#include<iostream>
#include<string>
using namespace std;
class BankAccount{
    private:
    string owner;
    double balance;
    public:
    void open(const string &name,double initial){
        owner=name;
        balance=(initial>0)?initial:0;
    }
    void deposite(double amt){
        if(amt>0)
        balance+=amt;
    }
    bool withdraw(double amt){
        if(amt>0&&amt<=balance){
            balance-=amt;
            return true;
        }
        return false;
    }
    double getBalance()const{return balance;}
    string getOwner()const{return owner;}
};
int main(){
    BankAccount a;
    a.open("maxine",2000);
    a.deposite(1000);
    if(!a.withdraw(4000));
    cout<<"withdraw denied(insufficient)\n";
    a.withdraw(700);
    cout<<a.getOwner()<<"balance ="<<a.getBalance()<<endl;
    return 0;
}