#include <iostream>
#include <iomanip>
using namespace std;

struct time_time{
    int seconds;
    int minutes;
    int hours;
};
int main()
{
    time_time t1,t2,sum_time;
    char two_point;
    cout<<"enter the first time: ";
    cin>>t1.hours>>two_point
        >>t1.minutes>>two_point
        >>t1.seconds;
    cout<<"enter the second time: ";
    cin>>t2.hours>>two_point
        >>t2.minutes>>two_point
        >>t2.seconds;
    long sum = t1.seconds+t2.seconds
                +(t1.minutes+t2.minutes)*60
                +(t1.hours+t2.hours)*3600;
    sum_time.hours =sum/3600;
    sum %= 3600;
    sum_time.minutes = sum/60;
    sum %= 60;
    sum_time.seconds = sum;


    cout<<"your sum time:"<<sum_time.hours<<two_point<<
        setw(2)<<setfill('0')<<sum_time.minutes<<two_point
        <<setw(2)<<setfill('0')<<sum_time.seconds<<endl;

    return 0;
}
