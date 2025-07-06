#include <iostream>
using namespace std;
long hms_to_secs(int, int , int);
int main()
{
    cout<<"enter hour minutes and seconds use /"<<endl;
    int m,h,s;
    char ch = '/';
    cin>> h>>ch>>m>>ch>>s;
    long total_seconds = hms_to_secs(h,m,s);

    cout<<total_seconds;
    return 0;
}
long hms_to_secs(int hour,int minute,int seconds )
{

    return minute+hour*60*60+minute*60;
}
