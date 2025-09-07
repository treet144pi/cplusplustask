#include <iostream>
using namespace std;


class angle
{
    private:
        int degree;
        float minute;
        char vector;
    public:
        void out()
        {   cout<<degree<<'\xF8'<<minute<<'`'<<' '<<vector<<endl;}
        void input()
        {
            cin>>degree>>minute>>vector;
        }
};

class ship
{
    angle coordinates;
    int num;
    public:
        void out()
        {
            coordinates.out();
            cout<<"ship number: "<<num<<endl;
        }
        void input()
        {
            coordinates.input();
            cin>>num;
        }



};
int main()
{
    ship ship1,ship2,ship3;
    ship1.input();
    // ship2.input();
    // ship3.input();

    ship1.out();
    // ship2.out();
    // ship3.out();

    return 0;
}
