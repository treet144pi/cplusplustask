#include <iostream>

using namespace std;

class sterling
{
    private:
        long  pounds;
        int shillings;
        int pence;
    public:
        sterling(): pounds(0),shillings(0),pence(0)
        {       }
        sterling(long pound,int s,int p):pounds(pound),shillings(s),pence(p)
        {       }
        explicit sterling(double decimal_pounds)
        {
            pounds = static_cast<long> (decimal_pounds); decimal_pounds -= pounds;
            decimal_pounds *= 20;
            shillings = static_cast<int> (decimal_pounds); decimal_pounds -= shillings;
            if (shillings >= 20) {
                pounds += shillings/20;
                shillings %= 20;
            }
            pence = static_cast<int> (decimal_pounds*12+0.5);
            if (pence >=12)
            {
                shillings += pence/12;
                pence %= 12;

            }
        }
        void getsterling()
        {
            char ch;
            cin>>ch>>pounds>>ch>>shillings>>ch>>pence;
        }
        void putsterling()
        {
            cout<<'%'<<pounds<<'.'<<shillings<<'.'<<pence;
        }
        operator double ()
        {
            return static_cast<double> (pence)/240.0 + static_cast<double> (shillings)/20.0 + static_cast<double>(pounds);
        }
        sterling operator+(sterling m)
        {
            return sterling(double(*this)+ double(m));
        }
        sterling operator-(sterling m)
        {
            return sterling(double(*this)- double(m));
        }
        sterling operator*(double share)
        {   return sterling(double(*this)*share);}
        double operator/(sterling m)
        {   return (double(*this) / double(m));}
        sterling operator/(double share)
        {   return sterling(double(*this) / share);}
};

int main()
{
    sterling m(1.625),f(0,5,8),s(0,7,4),t;
    // m.putsterling();
    //f.putsterling();
    t = f+s;
    t.putsterling();

    return 0;
}
