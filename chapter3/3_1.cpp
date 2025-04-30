#include <iostream>
#include <iomanip>
using namespace std;

struct phone {
    int country;
    int station;
    int subsriber;
};

int main()
{
    phone sub1 = {212,767,8900};
    phone sub2;

    cout<<"enter number your country, station, subsribe: ";
    cin>>sub2.country>>sub2.station>>sub2.subsriber;

    cout<<"my number: ("<<sub1.country<<")  "<<sub1.station<<'-'<<sub1.subsriber<<endl;
    cout<<"your number: ("<<setw(3)<<setfill('0')<<sub2.country
        <<")  "<<setw(3)<<setfill('0')<<sub2.station<<
        '-'<<setw(4)<<setfill('0')<<sub2.subsriber<<endl;

    return 0;
}
