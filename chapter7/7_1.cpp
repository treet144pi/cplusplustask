#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class Distance // класс английских мер длины
{
    private:
         int feet;
         float inches;
    public:
     // конструктор без параметров
    Distance() : feet(0), inches(0.0)
    { }
        // конструктор с двумя параметрами
    Distance(int ft, float in) : feet(ft), inches(in)
         { }
     // получение информации от пользователя
     void getdist()
     {
        cout << "\nВведите футы: "; cin >> feet;
        cout << "Введите дюймы: "; cin >> inches;
    }
     // показ информации
     void showdist()
        { cout << feet << "\'-" << inches << '\"'<<endl; }
     // сложение двух длин
     Distance operator+(Distance) const;
     Distance operator-(Distance) const;
    };
///////////////////////////////////////////////////////////
    // сложение двух длин
Distance Distance::operator+(Distance d2) const
    {
     int f = feet + d2.feet; // складываем футы
     float i = inches + d2.inches; // складываем дюймы
     if(i >= 12.0) // если дюймов стало больше 12
     {
        i -= 12.0; // то уменьшаем дюймы на 12
        f++; // и увеличиваем футы на 1
        }
        return Distance(f, i); // создаем и возвращаем временную переменную
    };
Distance Distance::operator-(Distance d2) const
{
    int f = feet-d2.feet;
    float i = inches - d2.inches;
    if (i< 0)
    {
        f--;
        i+=12;
    }
    return Distance (f,i);

};
int main()
{
    Distance d1(13,12.54),d3;
    Distance d2(34,23.222);
    d3 = d1;
    d3.showdist();
    d3 = d2 - d1;
    d3.showdist();

    return 0;
}
