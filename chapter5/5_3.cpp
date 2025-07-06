#include <iostream>
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
        void sum_time(time_time t1,time_time t2)
        {
            second = (t1.second+t2.second);
            minute = t1.minute+t2.minute + second/60;
            second %= 60;
            hour = t2.hour+t1.hour+minute/60;
            minute %= 60;
        }
};

int main()
{
    time_time t1(34,43,20),t2(32,2,3),t3;
    t3.sum_time(t1,t2);
    t3.output_time();

    return 0;
}
