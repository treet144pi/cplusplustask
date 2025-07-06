#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class fraction
{
    private:
        int num;
        int den;
    public:
        fraction(): num(0), den(1)
        {                   }
        fraction(int n,int d): num(n),den(d)
        {                   }

        void lowterms();
        void input_fraction_user()
        {
            cout<<"input your number in format n1/n2"<<endl;
            char ch;
            cin>> num>>ch>>den;
        }
        void output_fraction() const
        {   cout<<setw(3)<<num<<'/'<<den<<endl;}
        void sum_fraction(const fraction &,const fraction & );
        void sub_fraction(const fraction &,const fraction & );
        void mul_fraction(const fraction &,const fraction & );
        void div_fraction(const fraction &,const fraction & );
        void average_fraction ( const int,const fraction []);

};
void fraction::lowterms() // сокращение дроби
{
    long tnum, tden, temp, gcd;
    tnum = labs(num); // используем неотрицательные
    tden = labs(den); // значения (нужен cmath)
        if(tden == 0) // проверка знаменателя на 0
            { cout << "Недопустимый знаменатель!"; exit(1); }
        else if(tnum == 0) // проверка числителя на 0
        { num = 0; den = 1; return; }
    // нахождение наибольшего общего делителя
    while(tnum != 0)
    {
        if(tnum < tden)    // если числитель больше знаменателя,
        { temp = tnum; tnum = tden; tden = temp; } // меняем их местами
        tnum = tnum - tden;    // вычитание
    }
    gcd = tden;     // делим числитель и знаменатель на
    num = num / gcd;    // полученный наибольший общий делитель
    den = den / gcd;
};
void fraction:: sum_fraction(const fraction& n1,const fraction & n2) //функция определнная вне класса
{
    num = n1.num*n2.den+n2.num*n1.den;
    den = n1.den*n2.den;
    fraction new_num(num,den);
    new_num.lowterms();
    num = new_num.num;
    den = new_num.den;
};
void fraction:: sub_fraction(const fraction& n1,const fraction & n2) //функция определнная вне класса
{
    num = n1.num*n2.den-n2.num*n1.den;
    den = n1.den*n2.den;
    fraction new_num(num,den);
    new_num.lowterms();
    num = new_num.num;
    den = new_num.den;
};
void fraction:: mul_fraction(const fraction& n1,const fraction & n2) //функция определнная вне класса
{
    num = n1.num*n2.num;
    den = n2.den*n1.den;
    fraction new_num(num,den);
    new_num.lowterms();
    num = new_num.num;
    den = new_num.den;
};

void fraction:: div_fraction(const fraction& n1,const fraction & n2) //функция определнная вне класса
{
    num = n1.num*n2.den;
    den = n1.den*n2.num;
    fraction new_num(num,den);
    new_num.lowterms();
    num = new_num.num;
    den = new_num.den;
};
void fraction:: average_fraction(const int size,const fraction arr[])
{
    fraction sum;
    for (int i=0;i<size;i++)
        sum.sum_fraction(sum,arr[i]);
    sum.den *= size;
    sum.lowterms();
    den  = sum.den; num = sum.num;
};






const int size = 5;
int main()
{
    fraction arr[size];
    for (int i =0;i<size;i++)
        arr[i].input_fraction_user();

    fraction sum;
    sum.average_fraction(size,arr);


    sum.output_fraction();



    return 0;
}
