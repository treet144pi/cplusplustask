
#include <iostream>
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
        /*
        Нам нужно либо запретить копирования в private
        linklist& operator =(linklist&); оператор присваивания
        linklist(linklist&); коструктор копирования
        проблема заключается в том что коипруется указатели что нам не нужно так как при удалении одного
        обьекта память очищается и скопированный обьект имеет указатель на бессмысленные ячейки возникает ошибка
        поэтому нам нужно полное копирование с выделением памяти чтобы такого не было
        */



        linklist(linklist& list) // конструктор копирования
        {
            first = new link;
            link* memory_first = first;
            first->data = list.first->data;
            first->next = NULL;

            link* temp_list = list.first->next;
            while (temp_list )
            {
                link *temp_main = new link;
                temp_main->data = temp_list->data;
                temp_main->next = NULL;
                first = first->next = temp_main;


                temp_list = temp_list->next;
            }
            first = memory_first;

        }
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
        linklist& operator = (linklist&);
        void additem(int d); // добавление элемента
        void display(); // показ данных

};
///////////////////////////////////////////////////////////
linklist& linklist:: operator= (linklist& list)
{
            first = new link;
            link* memory_first = first;
            first->data = list.first->data;
            first->next = NULL;

            link* temp_list = list.first->next;
            while (temp_list )
            {
                link *temp_main = new link;
                temp_main->data = temp_list->data;
                temp_main->next = NULL;
                first = first->next = temp_main;


                temp_list = temp_list->next;
            }
            first = memory_first;
            return *this;
}
void linklist::additem(int d) // добавление элемента
{
    link* newlink = new link; // выделяем память
    newlink->data = d; // запоминаем данные
    newlink->next = first; // запоминаем значение first
    first = newlink; // first теперь указывает на новый элемент
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
    linklist* s1 = new linklist;
    linklist s3;
    s1->additem(3);
    s1->additem(2);
    s1->additem(452);
    s1->additem(52);
    s1->display();
    linklist s2(*s1);
    s3 = s2;
    s2.display();
    delete s1;

    return 0;
}
