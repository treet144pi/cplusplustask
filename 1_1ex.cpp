#include <iostream>
using namespace std;
int main()
{
    const float gallon_cub = 7.481F;
    float cub_fut = 0, gallon;
    cout << "Enter number gallons: ";
    cin >> gallon;
    cub_fut = gallon / gallon_cub;
    cout <<"Your gallons in cub fut: "<< cub_fut <<endl;
    return 0;
}
