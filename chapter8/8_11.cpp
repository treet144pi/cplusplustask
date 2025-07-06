#include <iostream>
using namespace std;
#include <stdlib.h>


struct pair_
{
    int x;
    int y;
};
class Stack
{
     protected: // Замечание: использовать private нельзя
        static const int MAX = 6; // размер стека
        int st[MAX]; // данные, хранящиеся в стеке
        int top; // индекс последнего элемента в стеке
     public:
        Stack() // конструктор
            { top = -1; }
        void push(int var) // помещение числа в стек
             { st[++top] = var; }
        int pop() // извлечение числа из стека
            { return st[top--]; }
};
///////////////////////////////////////////////////////////
class Stack2 : public Stack
{
     public:
         void push(int var) // помещение числа в стек
        {
            if(top >= MAX - 1) // если стек полон, то ошибка
                 { cout << "\nОшибка: стек полон"; exit(1); }
            Stack::push(var); // вызов функции push класса Stack
         }
        int pop() // извлечение числа из стека
        {
            if(top < 0) // если стек пуст, то ошибка
                { cout << "\nОшибка: стек пуст\n"; exit(1); }
            return Stack::pop(); // вызов функции pop класса Stack(можно без return)
     }
};
/////


class pairStack: public Stack2
{
    public:
        void push(pair_ p)
        {
            Stack2::push(p.x);
            Stack2::push(p.y);
        }
        pair_ pop()
        {
            pair_ p;
            p.y = Stack2::pop();
            p.x = Stack2::pop();
            return p;
        }
};


int main()
{
    pair_ x = {4,5};
    pair_ z = {6,7};
    pairStack stak;
    stak.push(x);
    stak.push(z);
    pair_ y = stak.pop();
    cout<<y.x<<y.y;


    return 0;
}
