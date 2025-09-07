#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

class time_time
{
    private:
        int hour;
        int minute;
        int second;
    public:
        time_time(): hour(0), minute(0), second(0)
        {       }
        time_time(int s,int m,int h): hour(h),minute(m),second(s)
        {       }
        void output_time()
        {   cout<<hour<<":"<<minute<<':'<<second<<endl;}
        void get_time ();
        void sum_time(time_time t1,time_time t2)
        {
            second = (t1.second+t2.second);
            minute = t1.minute+t2.minute + second/60;
            second %= 60;
            hour = t2.hour+t1.hour+minute/60;
            minute %= 60;
        }
};
void time_time::get_time ()
{
    while (true)
    {
        cout<<"ENTER hour:";
        cin>>hour;

        if (!cin.good())
        {
            cerr << "ERROR in input hour "<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (hour >23 || hour<0)
        {
            cout<<"enter time in limit (0> or <23)"<<endl;
            continue;
        }
        break;
    }
    while (true)
    {
        cout<<"ENTER minute:";
        cin>>minute;

        if (!cin.good())
        {
            cerr << "ERROR in input minute "<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (minute >59 || minute<0)
        {
            cout<<"enter time in limit (0> or <59)"<<endl;
            continue;
        }
        break;
    }
    while (true)
    {
        cout<<"ENTER second:";
        cin>>second;
        if (!cin.good())
        {
            cerr << "ERROR in input second "<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (second >59 || second<0)
        {
            cout<<"enter time in limit (0> or <59)"<<endl;
            continue;
        }

        break;

    }

}
int main()
{
    time_time t(3,2,1);
    t.get_time();
    t.output_time();



    return 0;
}
