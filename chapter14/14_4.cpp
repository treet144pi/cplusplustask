#include <iostream>
#include <set>
#include <algorithm>
/*Контекст	Скобки	Пример
Шаблон контейнера	Нет	set<int, MyCompare>
Передача в алгоритм	Да	sort(..., MyCompare{})
Создание объекта	Да	MyCompare(true)*/
using namespace std;
class person
 {
 private:
 string lastName;
 string firstName;
 long phoneNumber;
 public:
 person() : // конструктор по умолчанию
 lastName("пусто"), firstName("пусто"), phoneNumber(0L)
 { }
 // конструктор с тремя аргументами
 person(string lana, string fina, long pho) :
 lastName(lana), firstName(fina), phoneNumber(pho)
 { }
 void input()
 {
    cin>>firstName>>lastName>>phoneNumber;
    cout<<"RESULT write"<<endl;
 }
 friend bool operator<(const person&, const person&);
 friend bool operator==(const person&, const person&);
 void display() const // вывод персональных данных
 {
 cout << endl << lastName << ",\t" << firstName
 << "\t\tТелефон: " << phoneNumber;
 }
 long get_phone() const // вернуть телефонный номер
 { return phoneNumber; }
 string get_name() const
 {  return firstName; }
 }; // end class person
//---------------------------------------------------------
// перегруженный < для класса person
bool operator<(const person& p1, const person& p2)
 {
 if(p1.lastName == p2.lastName)
 return (p1.firstName < p2.firstName) ? true : false;
 return (p1.lastName < p2.lastName) ? true : false;
 }
//---------------------------------------------------------
// перегруженный == для класса person
bool operator==(const person& p1, const person& p2)
 {
 return (p1.lastName == p2.lastName &&
 p1.firstName == p2.firstName) ? true : false;
 }
//---------------------------------------------------------
// функциональный объект для сравнивания содержимого
// указателей на объекты person
class comparePersons
 {
 public:
 bool operator()(const person* ptrP1,
 const person* ptrP2) const
 { return *ptrP1 < *ptrP2; }
 };
//---------------------------------------------------------
// функциональный объект для вывода персональных данных,
// хранимых в указателях
class displayPerson
 {
 public:
 void operator()(const person* ptrP) const
 { ptrP->display(); }
 };
/////////


int main()
{
    person*  arr_person[7];
    for (int i=0;i<7;i++)
    {
        arr_person[i] = new person;
        arr_person[i]->input();
    }
    multiset <person* ,comparePersons > multiset_person(arr_person,arr_person+7);
    multiset <person* ,comparePersons >::iterator m_iter;
    for_each(multiset_person.begin(),multiset_person.end(),displayPerson());

    for (int i=0;i<7;i++)
        delete arr_person[i];
    return 0;
}
