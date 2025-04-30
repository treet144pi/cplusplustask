#include <iostream>
using namespace std;

int main()
{
    float contribution = 0;
    int years = 0;
    float percent=0;
    cout <<"enter contribution: ";
    cin >> contribution;
    cout <<"enter years: ";
    cin >> years;
    cout <<"enter percent: ";
    cin >> percent;
    for (int i =0;i<years;i++)
    {
        contribution += (contribution* percent / 100);
    }
    cout << "your contribution over "<<years<<" years: "<< contribution<<endl;




    return 0;
}
