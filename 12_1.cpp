#include <iostream>
using namespace std;
int main()
{
    float decpounds;
    int pounds;
    float decfrac;
    cin >> decpounds;
    pounds = static_cast<int>(decpounds) ;//отбрасывание от числа дробнай части приведение типов
    decfrac = decpounds - pounds;
    cout << decpounds << '=' << decfrac << '+'<< pounds<<endl;

    return 0;
}
