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
        class Range
         {
            public:
                int index;
                Range(int i): index(i)
                {   }// конструктор
        };
        T & operator[] (int n)
        {
            if (n>=SIZE || n < 0)
                throw Range(n);
            return arr[n];
        }
};
int main()
{
    try {
    safearray<int> ar_int;
    ar_int[100] = 5;
    for (int i=0;i<4;i++)
        ar_int[i]= i*i+1;

    for (int i=0;i<4;i++)
        cout<<ar_int[i]<<endl;

    }
    catch (safearray<int>::Range er) // обработчик ошибок
    {
        cout<<"ERROR in index:"<<er.index<<endl;
    }
    cout<<"ALL"<<endl;
    return 0;
}
