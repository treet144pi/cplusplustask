#include <iostream>
using namespace std;

int main()
{
    short signal ;
    cout << "enter 1 to translation Celsius to Fahrenheit"<<endl<<"enter 2 to translation Fahrenheit to Celsius:";
    cin >> signal;
    if (signal == 1 )
    {
        cout <<"enter Celsius"<<endl;
        float degrees_Celsius;
        cin >> degrees_Celsius;
        cout << "your degrees in Fahrenheit: "<< degrees_Celsius*9/5+32<<endl;

    }
    else if (signal == 2)
    {

        cout <<"enter Fahrenheit"<<endl;
        float degrees_Fahrenheit;
        cin >> degrees_Fahrenheit;
        cout << "your degrees in Celsius: "<< (float) 5/9*(degrees_Fahrenheit-32)<<endl;

    }
    else
    {
        cout <<"your wrong,the programm finished"<<endl;
    }



    return 0;
}
