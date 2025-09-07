#include <iostream>
using namespace std;


template <class Type>
class frac
{
    private:
        Type num;
        Type den;
    public:
        frac()
        {   }
        frac(Type n,Type d=1): num(n),den(d)
        {   }
        frac operator+ (frac&);
        frac operator- (frac&);
        frac operator* (frac&);
        frac operator/ (frac&);
        void display()
        {   cout<<num<<'/'<<den<<endl;}
};

template <class Type>
frac<Type> frac<Type>::operator+(frac& a)
{
    return frac (num*a.den+a.num*den,den*a.den);
}

template <class Type>
frac<Type> frac<Type>::operator-(frac& a)
{
    return frac (num*a.den-a.num*den,den*a.den);
}

template <class Type>
frac<Type> frac<Type>::operator*(frac& a)
{
    return frac (num*a.num,den*a.den);
}
template <class Type>
frac<Type> frac<Type>::operator/(frac& a)
{
    return frac (num*a.den,den*a.num);
}
int main()
{
    frac<short> a(1,2),b(1,2),c;
    c = a-b;
    c.display();
    frac<char> ac('a','b'),bc('a','c'),cc;
    cc =ac+bc;
    cc.display();
    cout<<'2'-1;


    return 0;
}
