#include <iostream>
#include <cstring>
using namespace std;

void bsort(const char** ptr, int n)
{
    void order(const char**, const char**); // прототип функции
    int j, k; // индексы в нашем массиве
    for(j = 0; j < n - 1; j++) // внешний цикл
        for(k = j + 1; k < n; k++) // внутренний цикл
            order(ptr+j, ptr+k); // сортируем элементы
}
void order(const char** s1,const char** s2)
{
    if (strcmp(*s1,*s2)>0)
    {
        const char *temp =*s1;
        *s1 =*s2;
        *s2 = temp;
    }
}

int main()
{
    const char * str_day[] = {"ansday","tuesda","cas","ter","fd","ss","lsssss"};
    bsort(str_day,7);
    for (int i=0;i<7;i++)
        cout<<str_day[i]<<endl;


}
