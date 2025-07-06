#include <iostream>
using namespace std;

class date
{
    int month;
    int day;
    int year;
    public:
    void get_date()
    {
        char ch;
        cout<< "enter your date in format mm/dd/yy:"<<endl;
        cin>> month>>ch>>day>>ch>>year;
    }
    void show_date() const
    {   cout<<month<<'/'<<day<<'/'<<year<<endl; }
};
int main()
{
    date yesterday;
    yesterday.get_date();
    yesterday.show_date();
    return 0;
}
