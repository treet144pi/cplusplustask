#include <iostream>
using namespace std;
#include <string.h> // для функций strcpy, strcat
#include <stdlib.h> // для функции exit
///////////////////////////////////////////////////////////
class String // наш класс для строк
{
    private:
        enum { SZ =2 }; // максимальный размер строки
        char str[SZ]; // массив для строки
    public:
    class RangeError
    {
        public:
        string string_error;
        RangeError(string str): string_error(str)
        {   }

    };
    // конструктор без параметров
    String()
        { strcpy(str, ""); }
    // конструктор с одним параметром
    String(const char  s[])
        {
            if (strlen(s) >SZ)
                throw RangeError("Строка превышает лимит");
            strcpy(str, s);

         }
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
            throw RangeError("Сумма превышает лимит");
        return temp; // возвращаем результат
 }
};
//////
int main()
{
    try
    {
        String stree("HELLO myddddddddd freing"),sss("snake solid"),res;
        res  = stree+sss;
    }
    catch (String::RangeError lim)
    {
        cout<<lim.string_error<<endl;
    }
    cout<<endl;
    return 0;
}
