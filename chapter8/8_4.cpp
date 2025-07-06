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
class sales
{
    private:
        float sale_3[3];
    public:
        void getdata()
        {
            cout<<"enter sale this book the last 3 month: "<<endl;
            cin>>sale_3[0]>>sale_3[1]>>sale_3[2];
            char ch;
            while (cin.get(ch) && ch != '\n')
                ;
        }
        void putdata()
        {
            cout<<"sale this book the last 3 month: \n"
                <<sale_3[0]<<"- 1\n"<<sale_3[1]<<"- 2\n"
                <<sale_3[2]<<"- 3"<<endl;

        }



};
class book: private publication, private sales
{
    private:
        int n_page;
    public:
        void getdata()
        {
            publication::getdata();
            cout<<"enter number of page in this book: ";
            cin>>n_page;
            sales::getdata();

        }

        void putdata()
        {
            publication::putdata();
            cout<<" number of page in this book = "<<n_page<<endl;
            sales::putdata();
        }
};
class type: private publication, private sales
{
    private:
        float minutes;
    public:
        void getdata()
        {
            publication::getdata();
            cout<<"enter number of minutes in this book: ";
            cin>>minutes;
            sales::getdata();
        }

        void putdata()
        {
            publication::putdata();
            cout<<" number of minutes in this book = "<<minutes<<endl;
            sales::putdata();
        }
};
class disk: private publication, private sales
{
    private:
        enum type_disk {dvd,cd};
        type_disk td;
    public:
        void getdata()
        {
            publication::getdata();
            cout<<"enter type of disk(DVD or CD) enter d or c: ";
            char ch;
            cin>>ch;
            if (ch == 'd') td = dvd;
            else  if (ch== 'c') td = cd;
            sales::getdata();
        }

        void putdata()
        {
            publication::putdata();
            cout<<"type disk: ";
            if (td == dvd) cout<<"DVD"<<endl;
            else cout<<"CD"<<endl;
            sales::putdata();
        }



};
int main()
{
    disk d1,d2;
    d1.getdata();
    d1.putdata();

    d2.getdata();
    d2.putdata();

    return 0;
}
