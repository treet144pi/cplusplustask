#include <iostream>
using namespace std;

int main()
{
    char arithmetic_sign;
    int op1,op2,result;
    char next = 'y';
    while (next != 'n')
    {
    cout << "enter operand 1 arithemetic sign operand 2: ";
    cin>>op1>>arithmetic_sign>>op2;
    switch (arithmetic_sign)
    {
        case '+':
            cout <<"your result: "<< op1+op2<<endl;
            break;
        case '-':
            cout <<"your result: "<< op1-op2<<endl;
            break;
        case '*':
            cout <<"your result: "<< op1*op2<<endl;
            break;
        case '/':
            cout <<"your result: "<< op1/op2<<endl;
            break;
        default:
            cout << "ERROR not result"<<endl;
            break;
    }
        cout << "continue (y/n): ";
        while ((next = getchar()) != '\n')
            continue;
        next = getchar();
    }
    return 0;
}
