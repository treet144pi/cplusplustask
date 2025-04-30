#include <iostream>
using namespace std;

struct date{
    int month;
    int day;
    int year;
};

int main()
{
    date user_date;
    char slash;

    cout<<"enter date in format day/month/year"<<endl;
    cin>>user_date.day>>slash>>user_date.month>>slash>>user_date.year;

    cout<<"your date: "<<user_date.day<<slash
        <<user_date.month<<slash<<user_date.year<<endl;


    return 0;
}
