#include <iostream>
#include <al
using namespace std;
class sterling
{
    protected:
        long  pounds;
        int shillings;
        int pence;
    public:
        long getpounds() const
        {   return pounds;}
        int getshillings() const
        {   return pounds;}
        int getpence() const
        {return pence;}
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
class sterfrac: public sterling
{
    private:
        int eighths;
    public:
        void getsterling()
        {
            sterling::getsterling();
            char ch;
            cin>>ch>>eighths>>ch;
            cin.ignore();
        }
        void putsterling()
        {
            sterling::putsterling();
            cout<<'-'<<eighths<<'/'<<'8'<<endl;
        }
        /*const sterling& m означает, что m — это константный объект.

В C++ у константного объекта можно вызывать только константные методы (помеченные const).

Ваши getpounds(), getshillings(), getpence() не объявлены как const, поэтому компилятор ругается.

*/
        sterfrac& operator=(const sterling& m)
        {
            pounds = m.getpounds();
            shillings = m.getshillings();
            pence = m.getpence();
            return *this;
        }
        sterfrac operator+(sterfrac m)
        {
            sterfrac res;
            (res) = static_cast<sterling> (*this) + static_cast<sterling> (m);
            res.eighths = (m.eighths+ eighths)%8;
            if (m.eighths+ eighths >= 8)
            {
                sterling temp(0,0,(m.eighths+ eighths)/8);
                (res) =  static_cast<sterling> (res) + temp;

            }
            return res;
        }
};

int main()
{

    sterfrac a,b,c;
    a.getsterling();
    b.getsterling();
    c = a+b;
    c.putsterling();


    return 0;
}
