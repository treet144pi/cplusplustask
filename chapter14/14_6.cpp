#include <iostream>
#include <algorithm>
#include <vector>
/*Разница между прямыми и обратными итераторами:
Обычные (прямые) итераторы:

begin() указывает на первый элемент

end() указывает на позицию после последнего элемента (не на сам элемент!)

Перед использованием end() нужно уменьшать: --end()

Обратные итераторы (rbegin/rend):

rbegin() указывает на последний элемент

rend() указывает на позицию перед первым элементом

Уменьшать rbegin() не нужно - он уже указывает на действительный элемент*/
using namespace std;
int main()
{
    int arr[5] = {1,2,3,4,5};
    vector<int> vector_arr(arr,arr+5);
    vector<int>::iterator iter1;
    vector<int>::reverse_iterator iter2; // используем обратный итератор


    iter1 = vector_arr.begin();
    iter2 = vector_arr.rbegin();// как бы указывает на адрес следующий после последнего



    int len_iterat = vector_arr.size()/2;
    while (len_iterat-- >0)
        swap(*iter1++,*iter2++);
    // larr.reverse(); переворачивает список
    for (int i=0;i<5;i++)
        cout<<vector_arr[i]<<endl;


    return 0;
}
