#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
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
        string ldtoms( long double n)
        {
            ostringstream n_str; // поток вывода в строку
            n_str << n; // запись в поток

            string bufstring = n_str.str(); // получение строки
            size_t point_ind = bufstring.find('.');

            string frac_part = "";
            if (point_ind != string::npos)
            {
                frac_part = bufstring.substr(point_ind);
            }
            else
                point_ind = bufstring.size();

            int indent_number = point_ind%3;
            string whole_part = bufstring.substr(0, indent_number);
            if (indent_number != 0 )
                whole_part += ' ';

            for (int i= indent_number; i<point_ind;i+= 3)
                whole_part+= bufstring.substr(i,3)+" ";
            whole_part.pop_back();

            return "$"+whole_part+frac_part;
        }
};

class bMoney
{
    private:
        long double money_b;
    public:
        bMoney();
        bMoney(const char s[]);
//Ключевое слово explicit в C++ используется для указания, что конструктор или оператор преобразования
// не должен участвовать в неявных преобразованиях типов.
        explicit bMoney(long double l): money_b(l)
            {}
        void getmoney()
        {
            char number_money[20];
            cin>>number_money;
            money str_to_num;
            money_b = str_to_num.mstold(number_money);
        }
/*Да, в вашем случае использование explicit для конструктора с параметром
long double поможет избежать неоднозначности при вызове перегруженного оператора деления.*/

        void putmoney()
        {   cout<<money_b<<endl;}
        bMoney operator+(bMoney m1)
        {   return bMoney (money_b+m1.money_b);}
        bMoney operator-(bMoney m1)
        {   return bMoney (money_b-m1.money_b);}
        bMoney operator*(long double m1)
        {   return bMoney (money_b*m1);}
        bMoney operator/(long double m1)
        {   cout<<"THIS one"<<endl; return bMoney (money_b/m1);}
        bMoney operator/(bMoney m1)
        {   cout<<"THIS second"<<endl; return bMoney (money_b/m1.money_b);}

};
bMoney::bMoney(): money_b(0)
    {}
bMoney::bMoney(const char s[])
{
    money str_to_num;
    money_b = str_to_num.mstold(s);
}




int main()
{
    bMoney m1("$1235.23"),m2("$333.22"),m3;
    long double l = 12.5;

    m3 = m1/12.5;
    m3.putmoney();

    m3 = m1/m2;



    return 0;
}
/*Ключевое слово explicit в C++ используется для указания, что конструктор или оператор преобразования не должен участвовать в неявных преобразованиях типов.

📌 Где применяется:
Конструкторы с одним параметром
Без explicit компилятор может неявно преобразовывать типы, что иногда приводит к неочевидному поведению.

Пример без explicit:

cpp
class MyClass {
public:
    MyClass(int x) : value(x) {}
private:
    int value;
};

void func(MyClass obj) {}

int main() {
    func(42);  // Неявное преобразование int → MyClass
    return 0;
}
Здесь 42 автоматически преобразуется в MyClass, что может быть нежелательно.

С explicit:

cpp
class MyClass {
public:
    explicit MyClass(int x) : value(x) {}
private:
    int value;
};

void func(MyClass obj) {}

int main() {
    // func(42);  // Ошибка компиляции – требуется явное преобразование
    func(MyClass(42));  // OK
    return 0;
}
Операторы преобразования (C++11 и новее)
Позволяет запретить неявное приведение типа класса к другому типу.

Пример:

cpp
class MyClass {
public:
    explicit operator bool() const {
        return value != 0;
    }
private:
    int value;
};

int main() {
    MyClass obj{10};
    // bool b = obj;  // Ошибка – требуется явное преобразование
    bool b = static_cast<bool>(obj);  // OK
    return 0;
}
🔹 Вывод:
Используйте explicit, чтобы предотвратить неявные преобразования, которые могут привести к неожиданному поведению программы. Это улучшает безопасность типов и делает код более читаемым.*/
