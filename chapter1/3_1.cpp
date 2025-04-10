#include <iostream>
using namespace std;
int main()
{
    const int number_10 = 10;
    cout << number_10 << endl;
    int number_20 = 10*2-10*2+10+10;
    cout << number_20-- << endl;
    // префиксный декремент после вывода уменьшит на 1 если вкратце
    cout << number_20 <<endl;
    return 0;


}
