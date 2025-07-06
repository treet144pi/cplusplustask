#include <iostream>
using namespace std;
#include <string.h> // для функций strcpy, strcat
#include <stdlib.h> // для функции exit
///////////////////////////////////////////////////////////
class String // наш класс для строк
{
    private:
        static const int SZ = 80; // максимальный размер строки
        char str[SZ]; // массив для строки
    public:
 // конструктор без параметров
    String()
        { strcpy(str, ""); }
 // конструктор с одним параметром
    String(const char s[] )
        { strcpy(str, s); }
 // показ строки
    void display() const
        { cout << str; }
 // оператор сложения
    String operator+(String ss) const
    {
        String temp; // временная переменная
        if(strlen(str) + strlen(ss.str) < SZ)
        {
            strcpy(temp.str, str); // копируем содержимое первой строки
            strcat(temp.str, ss.str); // добавляем содержимое второй строки
        }
        else
        {
            cout << "\nПереполнение!";
            exit(1);
        }
        return temp; // возвращаем результат
    }
    String operator +=(String s)
    {
        if (strlen(str)+strlen(s.str) <SZ)
        {
            strcat(str,s.str);
        }
        else
        {
            cout << "\nПереполнение!";
            exit(1);
        }
        return str;
    }
};
///////////////////////////////////////////////////////////
int main()
{
    String s1,s2("tralale ");
    String s3 = "tralala!";
    s1 = s2+s3;
    s1.display();
    cout<<endl;
    s1 += s2+=s3;
    s1.display();


    return 0;
}
