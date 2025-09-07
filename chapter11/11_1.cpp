#include <iostream>
#include <fstream>
using namespace std;
class Distance // длина в английской системе
{
    private:
        int feet;
        float inches;
    public: // конструктор без аргументов
        Distance() : feet(0), inches(0.0)
            { }
 // конструктор с двумя аргументами
        Distance(int ft, float in) : feet(ft), inches(in)
            { }
        void getdist() // ввод длины пользователем
        {
            cout << "\nВведите число футов: "; cin >> feet;
            cout << "Введите число дюймов: "; cin >> inches;
        }
        void showdist() // вывод длины на экран
            { cout << feet << "\'-" << inches << '\"'; }
        void add_dist(Distance, Distance); // прототип
        friend istream& operator>> (istream&, Distance& );
        friend ostream& operator<< (ostream&, Distance& );
        int size ()
        {
            return sizeof(int)+sizeof(float)+3*sizeof(char);
        }
};
/*вы используете операторы << и >>
 для текстового ввода/вывода, которые
  автоматически форматируют данные как текст.
*/
istream& operator>> (istream& file,Distance& d)
{
    char ch;
    file>>d.feet>>ch>>ch>>d.inches>>ch;
    return file;
}
ostream& operator<< (ostream& file,Distance & d)
{
    file << d.feet << "\'-" << d.inches << '\"';
    return file;
}
//--------------------------------------------------------
// сложение длин d1 и d2
void Distance::add_dist(Distance dd1, Distance dd2)
{
    inches = dd1.inches + dd2.inches; // сложение дюймов
    feet = 0; // с возможным заемом
        if(inches >= 12.0) // если число дюймов больше 12.0,
        { // то уменьшаем число дюймов
            inches -= 12.0; // на 12.0 и увеличиваем
            feet++; // число футов на 1
        }
    feet += dd1.feet + dd2.feet; // сложение футов
}
/////////////
int main()
{
    fstream file;
    Distance d;
    file.open("11_1file.txt",ios::binary | ios::app | ios::out);
    int number_dist = file.tellp()/sizeof(Distance);
    cout<<  number_dist;
    for (int i=0; i<3;i++)
    {
        d.getdist();
        file.write(reinterpret_cast<char*>(&d), sizeof(Distance)); // испоьзуем обчные методы файлов
    } // так как они позволяют записывать файлы в двоичным режимы а операции << >> автоматически формируют данные как тект нужно специально их перегружать
    file.close();
    file.open("11_1file.txt",ios::binary |ios::in );
    for (int i=0;i<3+number_dist;i++)
    {
        file.read(reinterpret_cast<char*> (&d), sizeof(Distance));
        cout<<d<<endl;
    }
//Да, использование методов read() и write() для работы с бинарными файлами в C++
//— это корректный и эффективный способ сохранения и загрузки объектов.

    return 0;
}
