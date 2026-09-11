#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
vector <string> msg{"hello","c++","world", "from","vscode","and the c++ extension!"};
for(const string&word: msg)
{
cout<<word<<"";
}
cout<<endl;
}   