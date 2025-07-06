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

};
///////////////////////////////////////////////////////////
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
    linklist s1;
    s1.additem(3);
    s1.additem(2);
    s1.additem(452);
    s1.additem(52);
    s1.display();
    return 0;
}
