#include <iostream>
using namespace std;
const int LEN = 5;
int main()
{
    int maxint(int[],int);
    int ar[LEN];
    for (int i=0;i<LEN;i++)
        cin>>ar[i];

    cout<<ar[maxint(ar,LEN)]<<endl;
    return 0;
}
int maxint(int ar[],int size)
{
    int maximum = 0;
    for (int i=0;i<LEN;i++)
        maximum = (ar[maximum]>ar[i])? maximum: i;
    return maximum;
}
