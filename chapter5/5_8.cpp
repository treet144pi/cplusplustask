#include <iostream>
using namespace std;

class number_data
{
    private:
        static int count; // поле с таким словом становится общим для всех обьектов этого класса
        int number;
    public:
        number_data()
        {
            count++;
            number=count;
        }
        void output_input() const
        {   cout<<number<<endl;}
};

int number_data:: count=0;  // установили ее равной 0


int main()
{
    number_data n1,n2,n3,n4;

    n1.output_input();
    n2.output_input();
    n3.output_input();
    n4.output_input();

    return 0;
}
