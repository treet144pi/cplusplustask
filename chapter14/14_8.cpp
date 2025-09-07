#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    int arr[12] = {0,1,2,3,4,5,6,7,8,9,10,11};

    int first1,last1,first2;
    cin>>first1>>last1>>first2;

    if (first1>= first2)
        copy(arr+first1,arr+last1,arr+first2);
//Так делается потому, что copy() начинает работу с самого
// крайнего элемента слева.
/*Проблема обычного std::copy при перекрытии
Если целевая позиция (first2) находится правее исходного диапазона ([first1, last1)), но при этом диапазоны перекрываются, то std::copy будет портить данные.

Пример (как НЕ надо делать):
cpp
std::vector<int> data = {1, 2, 3, 4, 5};

// Пытаемся скопировать [2,3,4] (индексы 1-3) в позицию 2 (индексы 2-4)
std::copy(data.begin() + 1, data.begin() + 4, data.begin() + 2);

// Ожидаемый результат: [1, 2, 2, 3, 4]
// Реальный результат: [1, 2, 2, 2, 2]  😱 Данные испорчены!
Почему?
std::copy копирует поэлементно слева направо:

Сначала копирует data[1] (значение 2) в data[2] → [1, 2, 2, 4, 5].

Потом data[2] (уже 2) в data[3] → [1, 2, 2, 2, 5].

Затем data[3] (теперь 2) в data[4] → [1, 2, 2, 2, 2]*/
    else
        {
            int* buffer = new int [last1-first1];
            copy(arr+first1,arr+last1,buffer);
            copy(buffer,buffer+last1-first1,arr+first2);
            delete [] buffer ;
        }
    for (int i=0;i<12;i++)
        cout<<arr[i]<<endl;


    return 0;
}
