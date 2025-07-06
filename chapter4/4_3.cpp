#include <iostream>
using namespace std;
void zeroSmaller(int &,int &);
int main()
{
    int a=90,b = 145;
    zeroSmaller(a,b);
    cout<< a<<"  "<< b<<endl;
    return 0;
}
void zeroSmaller(int & a,int & b)
{
    if (a>b)
        b =0;
    else
        a = 0;
}
