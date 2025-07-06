#include <iostream>
using namespace std;

int power(char,int=2);

long power(long,int=2);

long power(int, int=2);

double power(double, int =2 ); // параметры по умолчанию
int main()
{
    char ch = 10;
    double db = 700;
    int i = 88;
    long l = 100;
    cout << power(ch)<< ' '<< power(ch,1)<<endl;
    cout << power(i)<< ' '<< power(i,5)<<endl;
    cout << power(db)<< ' '<< power(db,4)<<endl;
    cout << power(l)<< ' '<< power(l,3)<<endl;


    return 0;
}
double power(double n, int p )
{
    double res=1;
    for (int i=0;i<p;i++)
        res*=n;
    return res;
}
int power(char n, int p )
{
    int res=1;
    for (int i=0;i<p;i++)
        res*=n;
    return res;
}
long power(long n, int p )
{
    long res=1;
    for (int i=0;i<p;i++)
        res*=n;
    return res;
}
long power(int n, int p )
{
    long res=1;
    for (int i=0;i<p;i++)
        res*=n;
    return res;
}
