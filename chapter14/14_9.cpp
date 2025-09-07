#include <iostream>
#include <algorithm>
#include <vector>
#include <functional> // для наших функциональных обьектов
/*find if Алгоритм последовательно применяет предикат pred к каждому элементу в диапазоне [first, last) до тех пор, пока:

не найдет элемент, для которого pred возвращает true

или не достигнет конца диапазона

Пример использования:
cpp
#include <iostream>
#include <vector>
#include <algorithm>

bool isEven(int n) {
    return n % 2 == 0;
}

int main() {
    std::vector<int> numbers = {1, 3, 5, 8, 9, 10};

    // Ищем первое четное число
    auto it = std::find_if(numbers.begin(), numbers.end(), isEven);

    if (it != numbers.end()) {
        std::cout << "First even number: " << *it
                  << " at position: " << std::distance(numbers.begin(), it)
                  << std::endl;
    } else {
        std::cout << "No even numbers found" << std::endl;
    }

    return 0;
}
Вывод:

text
First even number: 8 at position: 3*/

using namespace std;

int main()
{
    vector<string> arr_name  = {"ALICE","EVA","ANDREW","ANTONIE","CHELSIE","MARLIN"};
    string search_name = "ANDREW";

    vector<string>::iterator it = find_if(arr_name.begin(),arr_name.end(),bind2nd(equal_to<string>(),search_name));
    if (it != arr_name.end())
        cout<<"find "<<*it<<" "<<it-arr_name.begin();
/*операция вычитания итераторов (it1 - it2) действительно работает только для итераторов с произвольным доступом (random access iterators). Давайте разберём этот вопрос подробно.

Какие итераторы поддерживают разность?
Итераторы с произвольным доступом (random access):

Поддерживают: it1 - it2

Примеры: итераторы vector, deque, array, обычные указатели*/


    return 0;
}
/*bind2nd - это адаптер функции, который привязывает второй аргумент бинарной функции к определенному значению, превращая ее в унарную функцию.

В вашем примере:

cpp
ptr = find_if(names.begin(), names.end(), bind2nd(equal_to<string>(), SearchName));
Что происходит:

equal_to<string>() - это функциональный объект, который сравнивает два строковых аргумента на равенство

bind2nd привязывает второй аргумент этого сравнения к значению SearchName

В результате получается унарная функция, которая принимает один аргумент (элемент контейнера) и сравнивает его с SearchName

find_if проходит по контейнеру и находит первый элемент, для которого эта функция возвращает true*/
