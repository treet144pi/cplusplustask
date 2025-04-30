#include <iostream>
using namespace std;

int main()
{
    int a,b,c,d;
    char symbol='0',sign;
    while ((symbol)!= 'q')
    {
        cin >>a>>symbol>>b>>sign>>c>>symbol>>d;
        switch (sign)
        {
            case '+':
                cout<<"summa: "<<(float) (a*d+b*c)/(b*d)<<endl;
                break;
            case '-':
                cout<<"sub: "<<(float) (a*d-b*c)/(b*d)<<endl;
                break;
            case '*':
                cout<<"mult: "<<(float) (a*c)/(b*d)<<endl;
                break;
            case '/':
                cout<<"div: "<<(float) (a*d)/(b*c)<<endl;
                break;
            default:
                cout<<"ERROR unknow sign"<<endl;
                break;
        }

        cout<<"enter q to quit or any symbol to continue: \n";
        while ((symbol =getchar())!= '\n')
            ;
        symbol=getchar();

    }


    return 0;
}
