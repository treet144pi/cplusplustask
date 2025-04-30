#include <iostream>
using namespace std;

struct date{
    int month;
    int day;
    int year;
};

enum etype { laborer, secretary, manager, accountant, executive, researcher };

struct employee{
    int number_empl;
    float earning_empl;
    etype role;
    date start;
};
int main()
{
    char slash;
    cout<<"enter date employee: number,earning,first symbol role and when he start work date"<<endl;
    employee employee_user;
    cin<<employee_user.number_empl<<employee_user.earning_empl<<employee_user.role
        <<employee_user.start.day<<slash<<employee_user.start.month<<slash
        <<employee_user.start.year;
    cout<<"date of employee: \n"<<"number employee: "<<employee_user.number_empl<<endl
        <<"employee earning: "<<employee_user.earning_empl<<endl
        <<"employee start working"<<employee_user.start.day<<slash<<employee_user.start.month
        <<slash<<employee_user.start.year<<endl<<"employee role: ";
switch (user_type)
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





    return 0;
}
