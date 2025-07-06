#include <iostream>
#include <stdlib.h>
using namespace std;

const int LIMIT = 10;

class safearray
{
    private:
        int arr[LIMIT];
        int start;
        int end;
    public:
        safearray(): start(0), end(LIMIT)
        {       }
        safearray(int s,int e): start(s),end(e)
        {       }
        int& operator[] (int n)
        {
            if (n < start || n >= end)
            {
                cout<<"ERROR out of range"<<endl;
                exit(1);
            }
            return arr[n];
        }
};


int main()
{
    safearray ar(100,175);
    ar[100]  = 5;
    ar[174] = ar[100]+3;
    cout<< ar[174]<<endl;



    return 0;
}
