#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <fstream>
using namespace std;

class fraction
{
    private:
        int num;
        int den;

    public:
        fraction() // после создания конструктора с аргументами у нас перестает генерироваться конструктор
        {       } // по умолчания поэтому мы должны сделать если мы используем без аргументов обьекты
//Если вы создаёте любой конструктор, компилятор перестаёт генерировать конструктор по умолчанию.
//Если вам нужно создавать объекты без аргументов, добавьте MyClass() {}.
//Можно использовать параметры по умолчанию, чтобы избежать дублирования кода.
        fraction (int n,int d=1): num(n), den(d)
        {               } //делаем конструктор по одному чтобы в будущем расширить программу для дружественных функций такой конструткор будет работать и с одним аргументом остадбные параметры автоматически вставляются по умолчанию
        void lowterms();
        bool operator== (fraction);
        bool operator!= (fraction);
        void input_fraction_user()
        {

            cout<<"input your number in format n1/n2"<<endl;
            char ch;
            cin>> num>>ch>>den;
            if (den == 0)
            {
                cout<<"ERROR(0 in denominator)"<<endl;
                exit(1);
            }
        }
        void output_fraction() const
        {   cout<< "your number: "<<num<<'/'<<den<<endl;}
        fraction operator+ (fraction n1)
        {
            int num_ret = n1.num*den+num*n1.den;
            int den_ret = n1.den*den;
            fraction new_num(num_ret,den_ret);
            new_num.lowterms();
            return fraction(new_num.num,new_num.den);
        }
        fraction operator- (fraction n1)
        {
            int num_ret = num*n1.den-n1.num*den;
            int den_ret = n1.den*den;
            fraction new_num(num_ret,den_ret);
            new_num.lowterms();
            return fraction(new_num.num,new_num.den);
        }
        fraction operator* (fraction n1)
        {
            int num_ret = num*n1.num;
            int den_ret = den*n1.den;
            fraction new_num(num_ret,den_ret);
            new_num.lowterms();
            return fraction(new_num.num,new_num.den);
        }
        fraction operator/ (fraction n1)
        {
            int num_ret = num*n1.den;
            int den_ret = den*n1.num;
            fraction new_num(num_ret,den_ret);
            new_num.lowterms();
            return fraction(new_num.num,new_num.den);
        }
        friend istream& operator>> (istream&, fraction&);
        friend ostream& operator<< (ostream&, fraction&);

};
ostream& operator<< (ostream& s,fraction & our_number)
{
    s<<our_number.num<<'/'<<our_number.den;
    return s;
}
istream& operator>> (istream& s,fraction&  our_number)
{
    char ch;
    while (true)
    {
        s>>our_number.num>>ch>>our_number.den;
        if (!s.good())// проверяет failbit badbit eofbit усли кто то из них установлен возратит !0(отрицание)
        {
            s.clear(); // очищаем флаги
            cout<<"ENTER input repeat(ERROR input)"<<endl;
            cout<<our_number.den<<our_number.num;
            s.ignore(30,'\n');
            continue;
        }

        if (our_number.den == 0)
            {
            cout<<"Denominator cant be 0 enter repeat"<<endl;
            s.ignore(30,'\n');
            continue;
            }
        break;
    }
    return s;
}
void fraction::lowterms() // сокращение дроби
{
    if (num)
    {
        int num_copy = num;
        int den_copy = den;
        while (num_copy != den_copy)
        {
            if (num_copy > den_copy)
                num_copy -= den_copy;
            else
                den_copy -= num_copy;
        }
        num /= num_copy;
        den /= num_copy;
    }
    else
    {
        num = 0;
        den = 1;
    }
};
bool fraction::operator== (fraction n1)
{
    fraction n2(num,den);
    n2.lowterms();
    n1.lowterms();
    if (n1.num == n2.num && n1.den == n2.den)
        return true;
    else
        return false;
};
bool fraction::operator!= (fraction n1)
{
    fraction n2(num,den);
    n2.lowterms();
    n1.lowterms();
    if (n1.num != n2.num || n1.den != n2.den)
        return true;
    else
        return false;
};


int main()
{
    fraction a=5,b(5,2),c=9;
    b = a+3;
    cin>>a;
    cin>>b;
    c = a*b;
    cout<<c;

    return 0;
}
