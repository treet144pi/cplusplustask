#include <iostream>
using namespace std;


class safearay
{
    static const int LIMIT = 10;
    int array[LIMIT];
    public:
        void putel(int index,int data)
        {
            if (index<0 || index>= LIMIT)
                cout<<"ERROR out of range";
            else
                array[index]= data;
        }
        int getel(int index)
        {
            if (index<0 || index>= LIMIT)
            {
                cout<<"ERROR out of range";
                return -9999;
            }
            else
                return array[index];
        }
};
int main()
{
    safearay sa;
    int temp = 12345;
    sa.putel(4,temp);
    sa.putel(0,43);
    temp = sa.getel(10);
    cout<<temp<<endl;


    return 0;
}

