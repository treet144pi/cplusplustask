#include <iostream>
using namespace std;
struct fraction {
    int chis;
    int znam;
};
int main()
{
    fraction a,b,sum;
    char slash;
    cout<< "enter your number a b"<<endl;
    cin>>a.chis>>slash>>a.znam
       >>b.chis>>slash>>b.znam;
    sum.chis = a.chis*b.znam+b.chis*a.znam;
    sum.znam = a.znam*b.znam;
    cout<<"your sum: "<<sum.chis<<slash<<sum.znam<<'='<<(float) sum.chis/sum.znam<<endl;



    return 0;
}
