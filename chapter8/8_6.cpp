#include <iostream>
using namespace std;
#include <stdlib.h>

const int LIMIT= 10;

class safearray
{
     protected:
        int arr[LIMIT];
     public:
        int& operator[](int n)
        {
            if(n < 0 || n >= LIMIT)
                { cout << "\nОшибочный индекс!"; exit(1); }
            return arr[n];
        }
};

class safehilo: public safearray
{
    private:
        int start;
        int end;
    public:
        safehilo(): end(LIMIT), start(0)
        {   }
        safehilo(int s,int e): end(e), start(s)
        {   if (s-e> 0) {cout<<"ошибка в начале и конце"; exit(1);}
            if (end-start+1 > LIMIT) {cout << "\nОшибочный индекс!"; exit(1); } }
        int& operator[](int n)
        {
            return safearray::operator[](n-start);
        }

};
int main()
{
    safehilo ar(5,5);
    ar[5]=2;
    ar[5]= ar[5]+2;
    cout<<ar[5];

    return 0;
}
