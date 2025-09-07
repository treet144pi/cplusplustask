
const int sizelift = 10;
#include "classpack.h"
#include <iostream>

void Complex::display()
{
    std::cout<<real<<'+'<<imagine<<'i'<<std::endl;
}
Complex::Complex()
{   real=0; imagine =0;}
Complex::Complex(int a,int b=1): real(a), imagine(b)
{   }
Complex operator+ (Complex &x,Complex& y)
{
    return Complex (x.real+y.real,y.imagine+x.imagine);
}
int tick(int a, int b, int c)
{
    if (a>b)
    {
        return a+b+c+sizelift;
    }
    if (b>c)
        return sizelift;
    return c+a-1;
}

