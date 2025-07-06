#include <iostream>
using namespace std;

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
class book: private publication
{
    private:
        int n_page;
    public:
        void getdata()
        {
            publication::getdata();
            cout<<"enter number of page in this book: ";
            cin>>n_page;
            cin.ignore();
        }

        void putdata()
        {
            publication::putdata();
            cout<<" number of page in this book = "<<n_page<<endl;

        }
};
class type: private publication
{
    private:
        float minutes;
    public:
        void getdata()
        {
            publication::getdata();
            cout<<"enter number of minutes in this book: ";
            cin>>minutes;
            cin.ignore();
        }

        void putdata()
        {
            publication::putdata();
            cout<<" number of minutes in this book = "<<minutes<<endl;

        }
};
int main()
{
    book b1,b2;
    type b3;
    b1.getdata();


    b1.putdata();
    b2.getdata();
    b2.putdata();




    return 0;
}
