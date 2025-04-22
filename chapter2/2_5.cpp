#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    for (int i = 20;i >0;i--)
    {
        cout << setw(i*2)<<'X';
        for (int j = 20 - i;j >0;j--)
            cout <<"XX";
        cout<<endl;
    }


    return 0;
}
