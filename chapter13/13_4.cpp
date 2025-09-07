#include <iostream>
using namespace std;

template <class T>
void swaps(T& a,T& b)
{
    T c = a;
    a= b; b =c;
}

int main()
{
    int a1=5,b1 =3;
    cout<<a1<<' '<<b1<<endl;
    swaps(a1,b1);
    cout<<a1<<' '<<b1<<endl;

    float a2=5.3,b2 =3.3;
    cout<<a2<<' '<<b2<<endl;
    swaps(a2,b2);
    cout<<a2<<' '<<b2<<endl;

    char a3='a',b3 ='b';
    cout<<a3<<' '<<b3<<endl;
    swaps(a3,b3);
    cout<<a3<<' '<<b3<<endl;

    return 0;
}
