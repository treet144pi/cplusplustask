#include <iostream>
using namespace std;

class fraction
{
    private:
        int numerator;
        int denominator;
    public:
        void input_fraction()
        {
            cout<<"input your number in format n1/n2"<<endl;
            char ch;
            cin>> numerator>>ch>>denominator;
        }
        void output_fraction() const
        {   cout<< "your number: "<<numerator<<'/'<<denominator<<endl;}
        void sum_fraction(const fraction &,const fraction & );
};
void fraction:: sum_fraction(const fraction& n1,const fraction & n2) //функция определнная вне класса
{
    numerator = n1.numerator*n2.denominator+n2.numerator*n1.denominator;
    denominator = n2.denominator*n2.denominator;
};
int main()
{
    fraction a,b,c;
    a.input_fraction();
    b.input_fraction();
    c.sum_fraction(a,b);
    c.output_fraction();

    return 0;
}
