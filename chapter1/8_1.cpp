#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    cout<<setw(9)<<"MOSCOW"<<setw(4)<<setfill('.')<<"1"<<endl;
    //setfill принимиает символ который заполняет вместо пробела в setw()
    return 0;
}
