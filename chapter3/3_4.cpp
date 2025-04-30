#include <iostream>
using namespace std;

struct employee{
    int number_empl;
    float earning_empl;
};

int main()
{
    employee emp1,emp2,emp3;

    cout<< "enter data first (number and earning employee) please: ";
    cin>>emp1.number_empl>>emp1.earning_empl;

    cout<< "enter data second (number and earning employee) please: ";
    cin>>emp2.number_empl>>emp2.earning_empl;

    cout<< "enter data third (number and earning employee) please: ";
    cin>>emp3.number_empl>>emp3.earning_empl;

    cout<< "employee data (number and earning employee) : "<<endl;
    cout<<"number first employee: "<< emp1.number_empl
        <<"  employee earning:"<<emp1.earning_empl<<endl;

    cout<<"number second employee: "<< emp2.number_empl
        <<"  employee earning:"<<emp2.earning_empl<<endl;

    cout<<"number third employee: "<< emp3.number_empl
        <<"  employee earning:"<<emp3.earning_empl<<endl;




    return 0;
}
