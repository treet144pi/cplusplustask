#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class Distance
{
 private:
 int feet;
 float inches;
 public:
 Distance(int f=0,int i=0): feet(f), inches(i)
 {  }

 void getdist() // получение информации
 {
 cout << "\n Введите футы: "; cin >> feet;
 cout << " Введите дюймы: "; cin >> inches;
 }
 void showdist() const // показ информации
 { cout << feet << "\'-" << inches << '\"'; }
 void div_dist(Distance,int);
Distance add_dist(Distance);
};
/////
void Distance::div_dist(Distance d2, int divisor)
{
float fltfeet = d2.feet + d2.inches / 12.0;
float temp = fltfeet /= divisor;
feet = int(fltfeet);
inches = (temp - feet) * 12.0;
}


Distance Distance::add_dist(Distance d2)
{
 Distance temp; // временная переменная
 temp.inches = inches + d2.inches; // сложение дюймов
 if(temp.inches >= 12.0) // если сумма больше 12.0,
 { // то уменьшаем ее на
 temp.inches -= 12.0;
  temp.feet = 1; // число футов на 1
 }
 temp.feet += feet + d2.feet; // сложение футов
 feet = temp.feet;
 inches = temp.inches;
 return temp;
}
/////
const int LEN=2;
int main()
{
    Distance ar[LEN],summa,average;
    for (int i=0;i<LEN;i++)
    {
        ar[i].getdist();
        summa.add_dist(ar[i]);
    }
    summa.showdist();
    average.div_dist(summa,LEN);
    average.showdist();

    return 0;
}
