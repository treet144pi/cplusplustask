#include <iostream>
using namespace std;

struct time_time{
    int seconds;
    int minutes;
    int hours;
};
int main()
{
    time_time user_time;
    char two_point;

    cout<<"enter your time: ";
    cin>>user_time.hours>>two_point
        >>user_time.minutes>>two_point
        >>user_time.seconds;

    long seconds_user = 3600*user_time.hours+60*user_time.minutes+user_time.seconds;
    cout<<"your time in seconds: "<<seconds_user<<endl;



    return 0;
}
