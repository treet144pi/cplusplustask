#include <iostream>
using namespace std;

struct point{
    int x;
    int y;
};

int main()
{
    point p1,p2,sum;

    cout << "enter coordinate point p1(x,y): ";
    cin >> p1.x>> p1.y;

    cout << "enter coordinate point p2(x,y): ";
    cin >> p2.x>> p2.y;

    sum.x = p1.x+p2.x;
    sum.y = p1.y+p2.y;

    cout << "coordinate point p1+p2 "<<sum.x<<'.'<<sum.y<<endl;



    return 0;
}
