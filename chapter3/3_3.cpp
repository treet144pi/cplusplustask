#include <iostream>
using namespace std;
struct volume{
    float height;
    float withd;
    float log;
};
int main()
{
    volume home = {10.12,10.12,10};
    cout<<"your chora  "<< home.height*home.withd*home.log<<endl;
    return 0;
}
