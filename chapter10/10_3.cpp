// frengl.cpp
// Дружественная перегружаемая операция +
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class Distance // Класс английских расстояний
 {
     private:
         int feet;
         float inches;
     public:
         Distance() // конструктор без аргументов
            { feet = 0; inches = 0.0; }
        Distance(float fltfeet) // конструктор (1 арг.)
            { // Переводит float в Distance
        feet = int(fltfeet); // feet - целая часть
        inches = 12*(fltfeet - feet);// слева - дюймы
        }
        Distance(int ft, float in) // конструктор (2 арг.)
        { feet = ft; inches = in; }
        void showdist() // Вывести длину
            { cout << feet << "\'-" << inches << '\"'; }
        friend Distance operator+(Distance, Distance); // дружественный
        friend Distance operator*(Distance,Distance);
 };
//---------
Distance operator+(Distance d1, Distance d2) // d1 + d2
 {
 int f = d1.feet + d2.feet; // + футы
 float i = d1.inches + d2.inches; // + дюймы
 if(i >= 12.0) // если больше 12 дюймов,
 { i -= 12.0; f++; } // уменьшить на 12 дюймов,
 // прибавить 1 фут
 return Distance(f, i); // Новая длина с суммой
 }
Distance operator*(Distance d1,Distance d2)
{
    int f =d1.feet*d2.feet;
    float i = d1.inches*d2.inches;
    while (i>= 12.0)
    {
        i -=12.0;
        f++;
    }
    return Distance(f,i);
}
int main()
{
    Distance d1= 45,d2;
    d2 = 4*d1;
    d1.showdist();
    d2.showdist();

}
