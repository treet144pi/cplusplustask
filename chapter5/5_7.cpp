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
int main()
{
    angle a;
    a.input();
    a.out();
    return 0;
}
