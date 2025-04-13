#include <iostream>
using namespace std;
int main()
{
    int a,b,c,d;
    char drob;
    cout<<"enter you rational number1: ";
    cin>>a>>drob>>b;
    cout<<"enter you rational number2: ";
    cin>>c>>drob>>d;
    cout << "summa number: "<< (a*d+b*c)<<'/'<<(b*d)<<endl;

    return 0;
}
