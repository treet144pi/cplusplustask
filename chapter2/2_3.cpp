#include <iostream>
using namespace std;

int main()
{
    char ch;
    long number=0;
    for (int i=0;i<6;i++)
    {
        ch = getchar();
        ch -=48;
        // ch - "0" (0 = 48)
        number += static_cast<int> (ch);
        number *=10;
    }
    number /= 10;
    cout<<number<<endl;
    return 0;
}
