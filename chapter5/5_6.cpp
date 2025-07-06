#include <iostream>
using namespace std;


enum etype { laborer, secretary, manager, accountant, executive, researcher };

class date
{
    int month;
    int day;
    int year;
    public:
    void get_date()
    {
        char ch;
        cout<< "enter your date in format mm/dd/yy:"<<endl;
        cin>> month>>ch>>day>>ch>>year;
    }
    void show_date() const
    {   cout<<month<<'/'<<day<<'/'<<year<<endl; }
};

class employee
{
    private:
        etype status;
        date start;
        int number;
        float earn;
    public:
        void input_data()
        {
            cout<< "input number and earn"<<endl;
            cin>>number>>earn;
        }
        void show_data() const
        {
            cout<<"your nubmber employee: "<<number<<endl;
            cout<<"your earning employee: "<<earn<<endl;

        }
        void getemploy()
        {
            char ch;
            cout<<"enter the first symbol (laborer, secretary, manager, accountant,executive, researcher): ";
            cin>>ch;
            switch (ch)
            {
            case 'l':
                status =laborer;
                break;
            case 's':
                status = secretary;
                break;
            case 'm':
                status =manager;
                break;
            case 'a':
                status = accountant;
                break;
            case 'e':
                status =executive;
                break;
            case 'r':
                status = researcher;
            default:
                break;
            }
            start.get_date();
        }
        void putemploy() const
            {
            cout<<"full name status: ";
            switch (status)
            {
                case 0:
                    cout<<"laborer"<<endl;;
                    break;
                case 1:
                    cout<<"secretary"<<endl;
                    break;
                case 2:
                    cout<<"manager"<<endl;
                    break;
                case 3:
                    cout<<" accountant"<<endl;
                    break;
                case 4:
                    cout<<"executive"<<endl;
                    break;
                case 5:
                    cout<< "researcher"<<endl;
                default:
                    break;
            }
                start.show_date();

            }
};
int main()
{
    employee e1;
    e1.input_data();
    e1.getemploy();

    e1.show_data();
    e1.putemploy();


    return 0;
}
