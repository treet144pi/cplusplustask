#include <iostream>
using namespace std;


double power(double, int =2 ); // параметры по умолчанию
int main()
{
    cout<<"enter your number and power or 0 0 to quit"<<endl;
    double n;
    int p;
    cin >> n>> p;
    while (n!= 0 && p!=0)
    {
        cout<< power(n)<<endl;
        cout<< power(n,p)<<endl;
        cout<<"enter your number and power or 0 0 to quit"<<endl;
        cin >> n>> p;
    }



    return 0;
}
double power(double n, int p )
{
    double res=1;
    for (int i=0;i<p;i++)
        res*=n;
    return res;



}
