#include <iostream>
using namespace std;
#include <string.h>

class String
{
    protected:
        enum { SZ = 10 }; // размер массива
        char str[SZ]; // массив для хранения строки
    public:
 // конструктор без параметров
        String()
            { str[0] = '\x0'; }
 // конструктор с одним параметром
        String(const char s[])
            { strcpy(str, s); } // сохраняем строку в массиве
 // показ строки
         void display() const
            { cout << str; }
         // перевод строки к обычному типу
         operator  char*()
            { return str; }
};
class pString: public String
{
    public:
        pString()
            { }
        pString(const char s[])
        {
            if (strlen(s) >= SZ )
            {
                strncpy(str,s,SZ-1);
                str[SZ-1] = '\x0';
            }
            else
            {
                strcpy(str,s);
            }
        }
};
int main()
{
    pString s1 = "HEllo ";
    cout<<s1;



    return 0;
}
