#include <iostream>
using namespace std;

int main()
{
    int a0[] = {1,2,3},a1[3],a2[]= {1,2,3};
    for (int i=0;i<3;i++)
        cin>>a1[i];
    int * ap[3]= {a0,a1,a2};
    cout<<ap[1][2];


    return 0;
}
