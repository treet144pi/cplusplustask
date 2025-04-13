#include <iostream>
using namespace std;
int main()
{
    int f,sh,pen;
    cin>>f>>sh>>pen;
    pen += sh*12;
    f += pen /240;
    pen %= 240;
    unsigned char  word_j = 74;
    cout << word_j << f<<'.'<<pen<<endl;





}
