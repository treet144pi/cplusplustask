#include <iostream>
using namespace std;

class tollBooth
{
    unsigned int count;
    double summa_earn;
    public:
        tollBooth(): count(0), summa_earn(0)
        {       }
        void payingCar()
        {   count++;
            summa_earn+=0.50;
        }
        void nopayCar()
        {    count++;  }
        void display()
        {   cout<<summa_earn<<'/'<< count;}

};
int main()
{
    tollBooth car;
    char ch ;
    cout<<"enter operation or nopay or pay or q to quit or d to display"<<endl;
    while (ch= getchar())
    {
        switch (ch)
        {
            case 'p':
                car.payingCar();
                break;
            case 'n':
                car.nopayCar();
                break;
            case 'd':
                car.display();
                break;
            default:
                break;
        }
        if (ch == 'q')
        {
            break;
        }


    }


    return 0;
}
