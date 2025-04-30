#include <iostream>
using namespace std;

int main()
{
    long number_factorial = 1;
    short number_user;

    cout<<"enter your number(enter 0 to quit): ";
    cin >> number_user;

    while (number_user)
    {

        for (int i =2;i<=number_user;i++)
        {
            number_factorial *= i;
        }

        cout<<"your factorial number: "<<number_user<<"! ="<<number_factorial<<endl;
        number_factorial = 1;

        cout<<"enter your number(enter 0 to quit): ";
        cin >> number_user;

    }



    return 0;
}
