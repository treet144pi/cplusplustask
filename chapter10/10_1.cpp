#include <iostream>
using namespace std;


class publication
{
    private:
        static const int MAX = 60;
        char name[MAX];
        float price;
    public:
        virtual void getdata() //стоит оставить функцию виртуальной для полеморфизма
        {                       //  так как иначе будте вызываться именно этот метод
            cout<<"name book: "; // без минут и номеров страниц
            cin.getline(name,MAX);
            cout<<"price this book: ";
            cin>>price;

        }
        virtual void putdata()  // оставляем виртуальным  так как есть
        {                       // осмысленная реализация по умолчнию
            cout<<"is the name of book "<<name // мы можем использовать этот метод в других классах производных как раньше
                <<"\nhis price is "<<price<<endl;
        }
        virtual void changer() =0; //делаем класс абстрактным у этого метода нету реализацией осмсленной по умолсчанию
};
class book: public publication
{
    private:
        int n_page;
    public:
        void getdata() override
        {
            publication::getdata();
            cout<<"enter number of page in this book: ";
            cin>>n_page;
            cin.ignore();
        }

        void putdata() override
        {
            publication::putdata();
            cout<<" number of page in this book = "<<n_page<<endl;

        }
        void changer()  override
        {
            cout<<"enter now number page in this book"<<endl;
            cin>>n_page;
        }

};
class type: public publication
{
    private:
        float minutes;
    public:
        void getdata() override
        {
            publication::getdata();
            cout<<"enter number of minutes in this book: ";
            cin>>minutes;
            cin.ignore();
        }

        void putdata() override
        {
            publication::putdata();
            cout<<" number of minutes in this book = "<<minutes<<endl;

        }
        void changer() override
        {
            cout<<"enter now number minute in this book"<<endl;
            cin>>minutes;
        }
};
int main()
{
    const int LEN = 2;
    publication * library[LEN];
    type c1; book c2;
    library[0]=&c1; library[1] = &c2;
    for (int i = 0;i<LEN;i++ )
        library[i]->getdata();
    library[0]->changer();
    for (int i = 0;i<LEN;i++ )
        library[i]->putdata();

}
