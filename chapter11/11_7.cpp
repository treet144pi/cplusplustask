#include <iostream>
#include <fstream>
using namespace std;

class name
{
    private:
        char name_name[100];
        char surname[100];
        char family_name[100];
        int number;
        static fstream file;
        static int count;
        static void resetfileptr()
        {
            file.clear();
            file.seekg(0);
        }
    public:
        bool isopen(ios::openmode mode) // опенмоуд это тип перечисления
        {
            if (file.is_open())
                file.close();

            file.open("test6.txt",mode);
            count ++;
            return file.is_open();
        }
        void read_name( int ) ; // по умолчанию читаем первую строку
        void write_name();
        void display();
        static int counter()
        {
            cout<<count<<endl;
            return count;
        }
};
void name::display()
{
    cout<<name_name<<' '<<surname<<' '<<family_name<<' '<<number<<endl;
}
void name::write_name()
{

    file<<name_name<<' '<<surname<<' '<<family_name<<' '<<number<<endl;
}
void name::read_name(int number_line = 1)
{
    name::resetfileptr();
    if (number_line <=0)
    {
        cout<<"ERROR your enter number line <0(your get the first line)"<<endl;
        number_line = 1;
    }
    for (int i=0; i<number_line;i++)
    {
        file>>name_name>>surname>>family_name>>number;
    }

}
int name::count = 0;
 fstream name::file; // важно
/* Статические переменные существуют в единственном экземпляре для всех объектов класса.

Объявление в классе (static std::fstream file;) лишь сообщает компилятору о существовании переменной, но не выделяет память.

Определение вне класса (std::fstream FileHandler::file;) выделяет память и создаёт объект.*/
int main()
{
    name first;
    first.isopen(ios:: in);
    first.read_name(3);
    name second;
    second.isopen(ios::in);
    second.read_name(1);
    name third=first;
    third.isopen(ios::out | ios::app);
/*Да, в C++ вы можете комбинировать несколько флагов openmode для файловых потоков с помощью побитового
ИЛИ (|). Это позволяет одновременно задавать несколько режимов работы с файлом.*/
    third.write_name();
    third.display();
    name::counter();
    return 0;
}
