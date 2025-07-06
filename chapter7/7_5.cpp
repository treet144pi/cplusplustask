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
        time_time operator++ ()
        {
            second++;
            if (second > 59)
            {
                minute++;
                second %=60;
            }
            if (minute > 59)
            {
                hour++;
                minute %= 60;
            }
            return time_time (second,minute,hour);

        }
        time_time operator++ (int)
        {
            time_time temp(second,minute,hour); //  нужно старое значение (так как постфиксное)
            second++;
            if (second > 59)
            {
                minute++;
                second %=60;
            }
            if (minute > 59)
            {
                hour++;
                minute %= 60;
            }
            return temp;   // возвращаем старое значение а не новое так как постфиксное
        }
        time_time operator-- ()
        {
            second--;
            if (second < 0)
            {
                minute--;
                second = 59;
            }
            if (minute < 0)
            {
                hour--;
                minute = 59;
            }
            return time_time (second,minute,hour);
        }
        time_time operator-- (int)
        {
            time_time temp(second,minute,hour);// нужно старое значение (так как постфиксное)
            second--;
            if (second < 0)
            {
                minute--;
                second = 59;
            }
            if (minute < 0)
            {
                hour--;
                minute = 59;
            }
            return temp;  // возвращаем старое значение а не новое так как постфиксное
        }
};

int main()
{
    time_time t1(0,0,20), t3(1,0,0);
    time_time t2;

    t2 = --t1;
    t2.output_time();
    t1.output_time();
    int a=1;
    int c;
    c = (++a)++; // не имеет однозначного поведения
    cout<<c<<endl<<a<<endl;


    return 0;
}
