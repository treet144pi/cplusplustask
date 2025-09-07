#include <iostream>
#include <fstream>
using namespace std;

struct link // один элемент списка
{
    int data; // некоторые данные
    link* next; // указатель на следующую структуру
};

class linklist // список
{
    private:
        link* first;
    public:
        linklist() // конструктор без параметров
            {  first = NULL; } // первого элемента пока нет
        ~linklist()
        {
            while (first)
            {
                link* temp = first->next;
                cout<<"delete element:" <<first->data<<endl;
                delete first;
                first = temp;
            }

        }
        void additem(int d); // добавление элемента
        void display(); // показ данных
        friend istream& operator>> (istream&,linklist&);
        friend ostream& operator<< (ostream&,linklist&);
};
/////////////////////////////////////////////////////////// в условии можно ставить поток если с ним все хорошо то будет истина иначе ложь
istream& operator >> (istream& s,linklist& our_likst)
{
    int data;
    while ( s>>data) // good() не очень хорошая идея она показывает хорошее ли сейчас чтение не предсказывает будущее чтение
        our_likst.additem(data); // число выводилосб два раза так как после чтения последнего числа поток хороший и цикл снова запускается
// и s>>data пытается снова прочесть  число но его нет поэтому data не изменяется и утсанавливается ошибка флага и после этого лишь конец цикла
// s>>data возвращает сам поток s который можно проверить в условии если чтение успешно то цикл выполняется
// если достигнут конец файла ил произошла ошибка то поток приводится к false

    return s;
}
ostream& operator << (ostream& s,linklist& our_likst)
{
    link* current = our_likst.first; // начинаем с первого элемента
    while(current) // пока есть данные
    {
        s << current->data << endl; // печатаем данные
        current = current->next; // двигаемся к следующему элементу
    }
    return s;
}

void linklist::additem(int d) // добавление элемента
{
    link* newlink = new link; // выделяем память
    if (first)
    {
        link *temp = first;
        while (temp->next)
            temp= temp->next;
        temp->next = newlink;
        newlink->data =d;
        newlink->next = NULL;

    }
    else
    {
        first = newlink;
        first->data = d;
    }
}
///////////////////////////////////////////////////////////
void linklist::display()
{
    link* current = first; // начинаем с первого элемента
    while(current) // пока есть данные
    {
        cout << current->data << endl; // печатаем данные
        current = current->next; // двигаемся к следующему элементу
    }
}

int main()
{
    fstream s;
    linklist * list_user = new linklist;


    int ch=0;
    while(ch != 5)
    {
        cout<<"enter your operation"<<endl
            <<"1-add element "<<"2-showdata "<<endl
            <<"3-input data in file "<<"4-save data use file"<<endl
            <<"5 to quit"<<endl;
        cin>>ch;


        switch (ch)
        {
            case 1:
            {
                int data_user;
                cin>>data_user;
                list_user->additem(data_user);
                break;
            }
            case 2:
            {
                list_user->display();
                break;
            }
            case 3:
            {
                s.open("11_8eee.txt",ios::out);
                s<<*list_user;
                s.close();
                break;
            }
            case 4:
            {
                delete list_user;
                list_user = new linklist;
                s.open("11_8eee.txt",ios::in);
                s>>*list_user;
                s.close();
                break;
            }

        }

    }
    delete list_user;
    return 0;
}
