#include <iostream>
#include <iomanip>
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
        {   cout<<setw(2)<<setfill('0')<<hour<<":"
                <<setw(2)<<setfill('0')<<minute<<':'
                <<setw(2)<<setfill('0')<<second<<endl;}
        time_time operator+ (time_time t1)
        {
            int second_t2 = (t1.second+second);
            int minute_t2 = t1.minute+minute + second_t2/60;
            second_t2 %= 60;
            int hour_t2 = hour+t1.hour+minute_t2/60;
            minute_t2 %= 60;
            return time_time (second_t2,minute_t2,hour_t2);
        }
};

int main()
{
    time_time t1(30,45,12),t2(45,45,0),t3;
    t3 = t1+t2;
    t3.output_time();


    return 0;
}
