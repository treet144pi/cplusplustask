#include <iostream>
#include "classpack.h"
using namespace std;

int main()
{
    Complex a(5,4),b(3,4),c;
    c =a+b;
    c.display();
    int res = tick(5,4,3);
    cout<<res;
    return 0;
}
