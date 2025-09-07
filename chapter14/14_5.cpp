#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main()
{
    vector<int> vector_number(10); // конструктор с таким аргументом создает 10 мест
    int arr_even[5] = {2,4,6,8,10};
    int arr_odd[5] = {1,3,5,7,9};
    set<int, less<int> > set_odd(arr_odd,arr_odd+5);
    //множество интов компаратор передается как второй шаблонный аргумент

    merge(arr_even,arr_even+5, set_odd.begin(),set_odd.end(), vector_number.begin());

    for (int i=0;i< vector_number.size();i++)
        cout<<vector_number[i]<<' ';
    cout<<endl;

    return 0;
}
