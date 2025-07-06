#include <iostream>
using namespace std;
void swap(int &,int &);
int main()
{
    int a = 1,b = 0;
    cout<<a<<' '<< b<<endl;
    swap(a,b);
    cout<<a<<' '<< b<<endl;

    return 0;
}
void swap(int & a ,int & b)
{
    int c = a;
    a = b;
    b = c;
}
