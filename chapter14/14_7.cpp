#include <iostream>
#include <list>
#include <numeric> // для accumulate()
using namespace std;
///////////////////////////////////////////////////////////
class airtime
 {
 private:
 int hours; // от 0 до 23
 int minutes; // от 0 до 59
  public:
 // конструктор по умолчанию
 airtime() : hours(0), minutes(0)
 { }
 // конструктор с двумя аргументами
 airtime(int h, int m) : hours(h), minutes(m)
 { }
 void display() const // вывод на экран
 { cout << hours << ':' << minutes; }
 void get() // ввод данных пользователем
 {
 char dummy;
 cout << "\nВведите время (формат 12:59): ";
 cin >> hours >> dummy >> minutes;
 }
 // перегружаемая операция +
 airtime operator+(const airtime right) const
 { // добавить компоненты
 int temph = hours + right.hours;
 int tempm = minutes + right.minutes;
 if(tempm >= 60) // проверка наличия переноса
 { temph++; tempm -= 60; }
 return airtime(temph, tempm); // возврат суммы
 }
 // перегруженный оператор ==
 bool operator==(const airtime& at2) const
 { return (hours == at2.hours) &&
 (minutes == at2.minutes); }
 // перегруженный оператор <
 bool operator<(const airtime& at2) const
 { return (hours < at2.hours) ||
 (hours == at2.hours && minutes < at2.minutes); }
 // перегружаемая операция !=
 bool operator!=(const airtime& at2) const
 { return !(*this == at2); }
 // перегружаемая операция >
 bool operator>(const airtime& at2) const
 { return !(*this< at2) && !(*this == at2); }
 }; // конец класса airtime
///////////////////////////////////////////////////////////
int main()
{
 char answer;
 airtime temp, sum;
 list<airtime> airlist; // список типа airtime
 do { // получить значения от пользователя
 temp.get();
 airlist.push_back(temp);
 cout << "Продолжить (y/n)? ";
 cin >> answer;
 } while(answer != 'n');
 // суммировать все элементы
 sum = accumulate(airlist.begin(), airlist.end(),
        airtime(0, 0));
/*
Существуют две версии этой функции. Версия с тремя аргументами всегда суммирует (с помощью перегруженного +) значения из заданного диапазона. Если же у алгоритма четыре аргумента, как в нашем примере, то может
быть использован любой функциональный объект
sum = accumulate(airlist.begin(), airlist.end(),
 airtime(0, 0), plus<airtime>());
 Да, в std::accumulate можно опустить четвёртый аргумент (функтор), если:

Тип элементов поддерживает оператор +

Вы хотите использовать стандартную операцию сложения
По умолчанию accumulate использует std::plus<>()

Начальное значение (третий аргумент) обязательно

Для сложения чисел можно опускать функтор

Для сложения объектов - нужен либо operator+, либо явный функтор
*/
  cout << "\nСумма = ";
 sum.display(); // вывод суммы на экран
 cout << endl;
 return 0;
}
