#include <iostream>
using namespace std;

template <class T>
T amax(T ar[],int size)
{
    T maxi = ar[0];
    for (int i=0; i<size;i++)
        maxi = ar[i] > maxi ? ar[i]: maxi;
    return maxi;
}


int main()
{
    int ar_int[8] = {1,2,3,4,1,2,3,4};
    char ar_char[3] = {'a','b','c'};
    long ar_long[4] = {2,2,5,6443};
    double ar_double[5] ={1.2,1.2,0,45.223,0};
    cout<<amax(ar_int,8)<<endl;
    cout<<amax(ar_char,3)<<endl;
    cout<<amax(ar_long,4)<<endl;
    cout<<amax(ar_double,5)<<endl;


    return 0;
}
