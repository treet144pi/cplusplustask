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

class publication
{
    private:
        static const int MAX = 60;
        char name[MAX];
        float price;
    public:
        void getdata()
        {
            cout<<"name book: ";
            cin.getline(name,MAX);
            cout<<"price this book: ";
            cin>>price;

        }
        void putdata()
        {
            cout<<"is the name of book "<<name
                <<"\nhis price is "<<price<<endl;
        }
};
class publication2: private publication
{
    date d;
    public:
        void getdata()
        {
            publication::getdata();
            d.get_date();
            cin.ignore();

        }
        void putdata()
        {
            publication::putdata();
            cout<<"your date book: ";
            d.show_date();
        }
};
class book: private publication2
{
    private:
        int n_page;
    public:
        void getdata()
        {
            publication2::getdata();
            cout<<"enter number of page in this book: ";
            cin>>n_page;
            cin.ignore();
        }

        void putdata()
        {
            publication2::putdata();
            cout<<" number of page in this book = "<<n_page<<endl;

        }
};
class type: private publication2
{
    private:
        float minutes;
    public:
        void getdata()
        {
            publication2::getdata();
            cout<<"enter number of minutes in this book: ";
            cin>>minutes;
            cin.ignore();
        }

        void putdata()
        {
            publication2::putdata();
            cout<<" number of minutes in this book = "<<minutes<<endl;

        }
};
int main()
{
    type d1;
    book d2;
    d1.getdata();
    d2.getdata();

    d1.putdata();
    d2.putdata();



    return 0;
}
