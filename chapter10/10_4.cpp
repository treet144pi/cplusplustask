#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////

class Array // моделирует обычный массив C++
{
    private:
    int* ptr; // указатель на содержимое Array
    int size; // размер Array
    public:
        Array(int s) // конструктор с одним аргументом
        {
            size = s; // аргумент - размер Array
            ptr = new int[s]; // выделить память под Array
        }
        Array(Array& ar ) //конструктор копирования
        {           //по умолчанию он просто копирует одни обьекты в другой
            size = ar.size;
            ptr = new int [size];
            for (int i=0;i<size;i++)
                ptr[i] = ar.ptr[i];

        }
        ~Array() // деструктор
            { delete[] ptr; }
        int& operator[](int j) // перегружаемая операция
        // списка индексов
            { return *(ptr + j); }
      Array& operator= (Array& ar) //перегружаемая операция присваивания
        { //по умолчанию он просто копирует одни обьекты в другой
            if (size>ar.size)
            {
                cout<<"this copy is not can be complete"<<endl;
                return *this;
            }
            for (int i=0;i<size;i++ )
                ptr[i] = ar.ptr[i];
            return *this; //указатель на наш обьект то есть адрес нашего обьекта (разыменнованный)
        }
        int* addres()
        {
            return ptr;
        }
 };
int main()
{
    Array a1(5);
    for (int i=0;i<5;i++)
        a1[i] = i*i;

    Array a2(a1); //используем конструктор копирования
    Array a3(5);
     for (int i=0;i<5;i++)
        a2[i] = a1[i]*i;
    a3 = a2; // присваивание
    //по умолчанию у нас все копируется если присваивание или конструктор копирование
// то есть даже ptr указатель у нас будте одинаковым но нам это не нужно
//+еще одна причина это деструктор так как он вначле удаляет первый элемент указатель очищает потом этот эе указатель еще раз очищает и возникает ошибка
    for (int i=0;i<5;i++)
        cout<<a3[i]<<' ';
    cout<<endl;



    return 0;
}
