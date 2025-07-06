#include <iostream>
using namespace std;

class employee
{
    private:
        string name;
        long number;
    public:
        void getdata()
        {
            cout<<"enter name and number:"<<endl;
            cin>>name>>number;
        }
        void putdata() const
        {
            cout<<name<<endl;
            cout<<number<<endl;
        }
};
const int   SIZE = 5;
int main()
{
    employee arr_emp[SIZE];
    for (int i =0; i<SIZE;i++)
        arr_emp[i].getdata();


    for (int i =0; i<SIZE;i++)
        arr_emp[i].putdata();


    return 0;
}
