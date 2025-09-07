#include <iostream>
#include <algorithm>
#include <list>

using namespace std;
int main()
{
    int arr[6] = {1,2,3,4,5,6};
    list<int> larr(arr,arr+6);
    list<int>::iterator iter1,iter2;
    iter1 = larr.begin();
    iter2 = larr.end();// как бы указывает на адрес следующий после последнего
    iter2--; // поэтому уменьшаем
    int len_iterat = larr.size()/2;
    while (len_iterat-- >0)
        swap(*iter1++,*iter2--);
    // larr.reverse(); переворачивает список
    iter1 = larr.begin();
    for (int i=0;i<6;i++)
        cout<<*iter1++<<endl;



    return 0;
}
