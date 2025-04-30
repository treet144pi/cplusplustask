#include <iostream>
using namespace std;

int main()
{
    int chair=0,
        guests= 0;
    long combinations=1;

    cout<<"enter guests and chairs: ";
    cin>>guests>>chair;

    if (!chair || chair > guests)
    {
        cout <<"ERROR not chairs"<<endl;
        return 1;
    }
    for (int i = guests;i>(guests-chair);i--)
        combinations *= i;

    cout<<"number combinations: "<<combinations<<endl;

    return 0;
}
