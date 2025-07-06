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
        time_time operator- (time_time t1)
        {
            int second_t2 = (second-t1.second);
            if (second_t2 < 0)
            {
                second_t2 += 60;
                minute--;
            }
            int minute_t2 = minute-t1.minute;
            if (minute_t2 < 0)
            {
                minute_t2 += 60;
                hour--;
            }
            int hour_t2 = hour-t1.hour;
            return time_time (second_t2,minute_t2,hour_t2);
        }
        time_time operator* (float s)
        {
            float res_float = hour*3600+minute*60+second;
            res_float *= s;
            int res = static_cast<int> (res_float);
            hour = res / 3600;
            res %= 3600;
            minute =  res / 60;
            res %= 60;
            second = res;
            return time_time (second,minute,hour);
        }
};


int main()
{
    time_time t1(40,15,30),t2;
    t2 = t1*2;
    t2.output_time();


    return 0;
}

