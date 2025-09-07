#include <iostream>
using namespace std;

template <class Type>
Type average(Type ar[],int n)
{
    Type sum=0;
    for (int i=0;i<n;i++)
        sum += ar[i];
    return sum/n;
}
int main()
{
    int ar_int[8] = {1,2,3,4,1,2,3,4};
    char ar_char[1] = {'a'};
    long ar_long[2] = {2,2};
    double ar_double[5] ={1.2,1.2,0,0,0};
    // cout<<average(ar_int,8)<<endl;
    cout<<average(ar_char,1)<<endl;
    // cout<<average(ar_long,2)<<endl;
    // cout<<average(ar_double,5)<<endl;






}
