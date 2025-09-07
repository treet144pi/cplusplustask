#include <iostream>
#include <stdlib.h>
using namespace std;

const int SIZE = 4;
template <class T>
class safearray
{
    private:
        T arr[SIZE];
    public:
        class Range {};
        T & operator[] (int n)
        {
            if (n>=SIZE || n < 0)
                throw Range();
            return arr[n];
        }
};
int main()
{
    try {
    safearray<int> ar_int;
        // ar_int[4] = 5;
    for (int i=0;i<4;i++)
        ar_int[i]= i*i+1;

    for (int i=0;i<4;i++)
        cout<<ar_int[i]<<endl;

    }
    catch (safearray<int>::Range)
    {
        cout<<"ERROR in index"<<endl;
    }
    cout<<"ALL"<<endl;
    return 0;
}
