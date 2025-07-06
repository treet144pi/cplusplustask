#include <iostream>
#include <cmath>
using namespace std;

class Polar
{
    private:
        float degree;
        float radius;
    public:
        Polar() {   }

        Polar (float r,float d): degree(d), radius(r)
        {       }

        Polar operator+ (Polar t2)
        {
            float x1 = radius*cos(degree), y1 = radius*sin(degree);
            float x2 = t2.radius* cos(t2.degree), y2 = t2.radius*sin(t2.degree);
            float x,y;
            x = x1+x2;
            y = y1+y2;
            float rad = sqrt(x*x+y*y);
            if (rad == 0)
                return Polar (0,0);
            return Polar (rad,acos(x/rad));
        }
        void show()
        {
            cout<<radius<<" "<<degree<<endl;
        }

};
int main()
{
    Polar t1(0,0),t2(0,5);
    Polar t3;
    t3 = t1+t2;
    t3.show();

    return 0;
}
