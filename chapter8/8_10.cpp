#include <iostream>
using namespace std;
const int LEN = 80; // максимальная длина имени
///////////////////////////////////////////////////////////
class student // сведения об образовании
{
     private:
         char school[LEN]; // название учебного заведения
         char degree[LEN]; // уровень образования
     public:
        void getedu()
        {
            cout << " Введите название учебного заведения: ";
            cin >> school;
            cout << " Введите степень высшего образования\n";
            cout << " (неполное высшее, бакалавр, магистр, кандидат наук): ";
            cin >> degree;
        }
         void putedu() const
        {
        cout << "\n Учебное заведение: " << school;
        cout << "\n Степень: " << degree;
        }
};
////
class employee // некий сотрудник
{
     private:
        char name[LEN]; // имя сотрудника
        unsigned long number; // номер сотрудника
     public:
        void getdata()
     {
        cout << "\n Введите фамилию: "; cin >> name;
        cout << " Введите номер: "; cin >> number;
     }
        void putdata() const
     {
        cout << "\n Фамилия: " << name;
        cout << "\n Номер: " << number;
     }
};

class manager : private employee, private student // менеджер
{
     private:
        char title[LEN]; // должность сотрудника
        double dues; // сумма взносов в гольф-клуб
     public:
        void getdata()
        {
            employee::getdata();
            cout << " Введите должность: "; cin >> title;
            cout << " Введите сумму взносов в гольф-клуб: "; cin >> dues;
            student::getedu();
        }
        void putdata() const
        {
            employee::putdata();
            cout << "\n Должность: " << title;
            cout << "\n Сумма взносов в гольф-клуб: " << dues;
            student::putedu();
        }
};

class executive: private manager
{
    private:
        double earn;
        int number_ak;
    public:
        void getdata()
        {
            manager::getdata();
            cout<<"напишите количество акции: ";
            cin>>number_ak;
            cout<<"годовая премия: ";
            cin>>earn;
        }
        void putdata() const
        {
            manager::putdata();
            cout<<"\nколичество акции: "<<number_ak
                <<"\nгодовой премия: "<<earn<<endl;
        }
};

int main()
{
    executive emp;
    emp.getdata();

    emp.putdata();



    return 0;
}
