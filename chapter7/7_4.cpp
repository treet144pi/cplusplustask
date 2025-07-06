#include <iostream>
#include <stdlib.h>
using namespace std;

class Int
{
    private:
        long double data;
    public:
        Int (): data(0)
        {       }
        Int (long double i): data(i)
        {       }
        Int operator+ (Int d)
        {
            if (abs(data+d.data) >  2147483648)
            {
                cout<<"ERROR"<<endl;
                exit(1);
            }
            else
                return Int (data+d.data);
        }
        Int operator- (Int d)
        {
            if (abs(data-d.data) >  2147483648)
            {
                cout<<"ERROR"<<endl;
                exit(1);
            }
            else
                return Int (data-d.data);
        }
        Int operator* (Int d)
        {
            if (abs(data*d.data) >  2147483648)
            {
                cout<<"ERROR"<<endl;
                exit(1);
            }
            else
                return Int (data*d.data);
        }
        Int operator/ (Int d)
        {
            if (abs(data/d.data) >  2147483648)
            {
                cout<<"ERROR"<<endl;
                exit(1);
            }
            else
                return Int (data/d.data);
        }
        operator long double()
        { return data;}


};


int main()
{
    Int a = 2341;
    Int b = 23,c;
    c = a/b;
    cout<<c;


    return 0;
}
