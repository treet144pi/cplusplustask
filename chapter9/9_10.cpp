#include <iostream>
using namespace std;

int main()
{
    int * ap[3];
    for (int i=0;i<3;i++)
    {
        ap[i] = new int [3];
        for (int j=0;j<3;j++)
            cin>>ap[i][j];
    }
    cout<<endl;
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
            cout<<ap[i][j];
        cout<<endl;
        delete [] ap[i];


    }

    return 0;
}
