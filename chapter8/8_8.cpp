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

class pString2: public pString
{
    public:
        pString2()
        { }
        pString2(const char s[]): pString(s)
        {   }
        char* left(const char s[],int n)
        {
            for (int i =0;i<n;i++)
                str[i] = s[i];
            str[n] = '\x0';
            return str;
        }
        char* right(const char s[],int n)
        {
            int len_ind= strlen(s);
            for (int i= n-1,j=1;i>=0;i--,j++)
                str[i] = s[len_ind-j];
            str[n] = '\x0';
            return str;
        }
        char* mid(const char strin[],int s,int n)
        {
            for (int i =0;i<n;i++)
                str[i] = strin[s+i];
            str[n] = '\x0';
            return str;
        }
};

int main()
{
    pString2 s1;
    pString2 s2 = s1.mid("hello friend",5,4);

    s1.display();
    s2.display();

    return 0;
}
