#include <iostream>
using namespace std;
const int SIZE = 10;


template <class T> // шаблон класса
class queue
{
    private:
    int head;
    int tail;
    int count_data; // счетчик числа элементов
    T arr[SIZE];
    public:
        class Full
        {}; // класс исключений
        class Empty
        {}; // класс исключений
        queue (): head(0), tail(0),count_data(0)
        {   }
        void push(T);
        T pop();
};

template <class T> // шаблон метода класса вне определении класса
void queue<T>::push(T data)
{
    if (count_data == SIZE)
        throw Full(); // генерирyем исклюяение
    arr[++tail] = data;
    count_data++;
    if (tail ==SIZE)
        tail = -1;
}

template <class T>
T queue<T>::pop()// шаблон метода класса вне определении класса
{
    if (count_data == 0)
        throw Empty();// генерирyем исклюяение
    count_data--;
    if (head == SIZE)
        head = -1;
    return arr[++head];
}

int main()
{
    queue<int> q_int; // шаблон класса очереди типа int
    int quit=0;
    while (quit != 5)
    {
        cin>>quit;
        // cin.ignore();s
        switch (quit)
        {
            case 1:
            {
                int data;
                cin>>data;
                try {
                q_int.push(data);
                }
                catch (queue<int>::Full) // обработчик исключений
                {
                    cout<<"queue if FULL"<<endl;
                }
                break;
            }
            case 2:
            {
                try{
                cout<<q_int.pop();
                }
                catch(queue<int>::Empty) // обработчик исключений
                {
                    cout<<"queue is empty"<<endl;
                }
                break;
            }
            default:
                break;
        }
    }


    return 0;
}
