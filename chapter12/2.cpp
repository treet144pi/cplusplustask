//покажем зачем нужнв библиотеки
/*В C++ namespace (пространство имён) — это механизм для организации кода, который позволяет группировать сущности (функции, классы, переменные) под уникальными именами,
избегая конфликтов именования. Особенно полезно при работе с большими проектами или библиотеками*/
#include <iostream>
using namespace std;
namespace MyLib {
    void print() { std::cout << "MyLib print\n"; }
}

namespace OtherLib {
    void print() { std::cout << "OtherLib print\n"; }
}
namespace Math {
    int add(int,int);
    double add( double,double);

}
double Math::add(double a,double b)
{   return a+b;}
int Math::add(int a,int b)
{   return a+b;}

//Функции с одинаковыми именами (print) не конфликтуют, так как принадлежат разным пространствам.
/*
MyLib::print(); // Вызов функции из MyLib
OtherLib::print(); // Вызов функции из OtherLib
using namespace MyLib;
print(); // Теперь print() ищется в MyLib

namespace ML = MyLib; // Создание псевдонима
ML::print();
namespace помогает избежать конфликтов имён.
Избегайте using namespace ... в глобальной области видимости.

Анонимное пространство имён (unnamed namespace)
Эквивалент static в C (ограничивает видимость файлом):

namespace {
    void helper() { ... } // Видна только в этом .cpp файле
}

*/

//float add(float a,float b)
//{   return a+b;} // can be create

using namespace Math; // теперь сможем без оператора разрешения ::
int main()
{
    MyLib::print();
    OtherLib::print();
    float a=5,b=4;
    cout<<add(42.2,4.2);

}
