#include <iostream>
using namespace std;

class Int {
    private:
        int data;
    public:
    Int(): data(0)
    {   }
    Int(int n): data(n)
    {   }
    void showdata() const
    {   cout<<"your data "<<data<<endl;  }
    void summa(const Int&, const Int&);
};
void Int::summa(const Int& d1,const Int& d2)
{
    data = d1.data+d2.data;
};

int main()
{
    Int data1;
    data1.showdata();
    Int data2(30),data3(120);
    data1.summa(data2,data3);
    data1.showdata();

    return 0;
}
