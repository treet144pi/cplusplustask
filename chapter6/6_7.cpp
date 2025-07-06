#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;

class money
{
    public:
        long double mstold(char const str[])
        {
            char s[20];
            int n = strlen(str);
            int k = 0;
            for (int i =0;i<n;i++)
            {
                if (str[i] == '.')
                    s[k++]= '.';
                else if (str[i] == '\0' )
                    break;
                else if (str[i]-'0'>=10 || str[i]-'0'<0)
                    continue;
                else
                    s[k++] = str[i];
            }
            s[k] = '\0';
            return stold(s);
        }
};
int main()
{
    money ch;
    long double number = ch.mstold("$1 234 567 890 123.99");
    cout<<setiosflags(ios::fixed) //нормальный неэкспонициальный вид
        <<setiosflags(ios::showpoint) // всегда показывать десятичную точку
        <<setprecision(2)  // два знака после запятой
        <<setw(10) //ширина вывода в 10 символов
        <<number<<endl;



    return 0;
}
