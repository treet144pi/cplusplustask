#include <iostream>
using namespace std;
const int str =20;
const int col = 10;
int main()
{
    int number;
    cout<<"enter your number"<<endl;
    cin>>number;

    for (int i=0;i<str;i++)
    {
        for (int j=1;j<=col;j++)
        {
            int multiplier = j+i*10;
            cout << number*multiplier;
        }

        cout<<endl;

    }


    return 0;
}
