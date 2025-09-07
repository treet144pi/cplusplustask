#include <iostream>
#include <stdlib.h>
using namespace std;

const int SIZE = 100;
template <class T>
class safearray
{
    private:
        T arr[SIZE];
    public:
        T & operator[] (int n)
        {
            if (n>=SIZE || n < 0)
             {   cout<<"ERROR out of range and error index"<<endl; exit(-1);}
            return arr[n];
        }
};
int main()
{
    safearray<int> ar_int;
    for (int i=0;i<4;i++)
        ar_int[i]= i*i+1;
    safearray<double> ar_double;
    for (int i=0;i<4;i++)
        ar_double[i]= 0.5*i;

    for (int i=0;i<4;i++)
        cout<<ar_int[i]<<endl;
    for (int i=0;i<4;i++)
        cout<<ar_double[i]<<endl;

    return 0;
}
