#include <iostream>
using namespace std;
const int LEN = 80;


class employee
{
    private:
        char name[LEN];
        unsigned long number;
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
class manager : public employee // менеджер
{
     private:
     char title[LEN]; // должность, например вице-президент
     double dues; // сумма взносов в гольф-клуб
     public:
        void getdata()
     {
        employee::getdata();
        cout << " Введите должность: "; cin >> title;
        cout << " Введите сумму взносов в гольф-клуб: "; cin >> dues;
     }
        void putdata() const
     {
        employee::putdata();
        cout << "\n Должность: " << title;
        cout << "\n Сумма взносов в гольф-клуб: " << dues;
     }
};

class scientist : public employee // ученый
{
    private:
    int pubs; // количество публикаций
    public:
        void getdata()
    {
        employee::getdata();
        cout << " Введите количество публикаций: "; cin >> pubs;
    }
        void putdata() const
    {
        employee::putdata();
        cout << "\n Количество публикаций: " << pubs;
    }
};
class laborer : public employee // рабочий
{
};
class compensation
{
    private:
        enum earn_time {hour,week,month,non};
        earn_time period;
        double compensat;
    public:
        void getdata()
        {
            cout<<"введите оплату:";
            char ch;
            cin>>compensat;
            cout<<"время ее получение (часовая,недельная, месячная) (h,w,m): ";
            cin>>ch;
            switch (ch)
            {
                case 'h':
                {
                    period = hour;
                    break;
                }
                case 'w':
                {
                    period = week;
                    break;
                }
                case 'm':
                {
                    period = month;
                    break;
                }
                default:
                    period = non;
                    break;

            }
        }
        void putdata()
        {
            cout<<"\nоплата:" << compensat;
            switch (period)
            {
                case hour:
                {
                    cout<<"/hour";
                    break;
                }
                case week:
                {
                    cout<<"/week";
                    break;
                }
                case month:
                {
                    cout<<"/month";
                    break;
                }
                default:
                    break;
            }
            cout<<endl;
        }
};
class manager2: public compensation, public manager
{
    public:
        void getdata()
        {
            manager::getdata();
            compensation::getdata();
        }
        void putdata()
        {
            manager::putdata();
            compensation::putdata();
        }
};
class scientist2: public compensation, public scientist
{
    public:
        void getdata()
        {
            scientist::getdata();
            compensation::getdata();
        }
        void putdata()
        {
            scientist::putdata();
            compensation::putdata();
        }
};
class laborer2: public compensation, public laborer
{
    public:
        void getdata()
        {
            laborer::getdata();
            compensation::getdata();
        }
        void putdata()
        {
            laborer::putdata();
            compensation::putdata();
        }
};


int main()
{
    manager2 d1;
    laborer2 d2;
    scientist2 d3;

    d1.getdata();
    d2.getdata();
    d3.getdata();

    d1.putdata();
    d2.putdata();
    d3.putdata();


    return 0;
}
