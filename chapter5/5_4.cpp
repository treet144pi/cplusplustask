#include <iostream>
using namespace std;
class employee
{
    private:
        int number;
        float earn;
    public:
        void input_data()
        {
            cout<< "input number and earn"<<endl;
            cin>>number>>earn;
        }
        void show_data() const
        {
            cout<<"your nubmber employee: "<<number<<endl;
            cout<<"your earning employee: "<<earn<<endl;

        }
};
int main()
{
    employee d1,d2,d3;
    d1.input_data();
    d2.input_data();
    d3.input_data();

    d1.show_data();
    d2.show_data();
    d3.show_data();

    return 0;
}
