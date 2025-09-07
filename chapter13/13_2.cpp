#include <iostream>
using namespace std;
/*Выражение template<class Type> должно предварять не только определение
класса, но и каждый определенный вне класса метод. Вот как выглядит функция push();
Template<class Type>
void Stack<Type>::push(Type var)
 {
 st[++top] = var;
 }
Имя Stack<Type> используется для того, чтобы идентифицировать класс, чьим
методом является push().
Шаблоны (templates) в программировании помогают избежать дублирования кода, делая его более гибким и удобным для поддержки.*/
/*Итак, имя шаблонного класса выглядит по-разному в зависимости от контекста. Внутри спецификации класса это просто само имя: Stack. Для методов, определенных вне классов, это имя класса и имя шаблонного аргумента: Stack<Type>.
Когда вы определяете реальные объекты для хранения конкретного типа данных,
именем шаблонного класса будет являться имя класса и имя типа: Stack<float>.
Например:
class Stack // Описатель класса Stack
 { };
void Stack<Type>:: push(Type var) // определение push()
 { }
Stack<float> s1; // Объект типа Stack<float*/
const int SIZE = 10;


template <class T> // шаблон класса
class queue
{
    private:
    int head;
    int tail;
    T arr[SIZE];
    public:
        queue (): head(0), tail(0)
        {   }
        void push(T);
        T pop();
};

template <class T> // шаблон метода класса вне определении класса
void queue<T>::push(T data)
{
    arr[++tail] = data;
    if (tail ==SIZE)
        tail = -1;
}

template <class T>
T queue<T>::pop()// шаблон метода класса вне определении класса
{
    if (head == SIZE)
        head = -1;
    return arr[++head];
}

int main()
{
    queue<int> q_int; // шаблон класса очереди типа int
    queue<char> q_char;// шаблон класса очереди типа char
    queue<double> q_double;// шаблон класса очереди типа double
    q_int.push(12); q_int.push(2); q_int.push(3);
    q_char.push('a'); q_char.push('b');q_char.push('g');
    q_double.push(34.22);q_double.push(32122.22);q_double.push(20.2002);
    cout<<q_int.pop()<<' '<<q_int.pop()<<' '<<q_int.pop()<<endl;
    cout<<q_char.pop()<<' '<<q_char.pop()<<' '<<q_char.pop()<<endl;
    cout<<q_double.pop()<<' '<<q_double.pop()<<' '<<q_double.pop()<<endl;


    return 0;
}
