#include <iostream>
using namespace std;
#include <string>
const int LEN = 3;

class person // некоторый человек
{
    protected:
        string name; // имя
        float salary;
    public:
        void setData() // установка имени
            {
                cout << "Введите имя: "; cin >> name;
                cout << "Введите его зарплату: "; cin>> salary;
            }
        void printData() // показ имени
            {
                cout << endl << name
                     << endl << salary;
            }
        string getName() // получение имени
            { return name; }
        float getSalary()
            { return salary;}
};

void bsort(person** pp, int n)
{
     void order(person**, person**); // прототип функции
     int j, k; // переменные для циклов
     for(j = 0; j < n - 1; j++) // внешний цикл
        for(k = j + 1; k < n; k++) // внутренний цикл
            order(pp + j, pp + k); // сортируем два элемента
}
///////////////////////////////////////////////////////////
void order(person** pp1, person** pp2)
{
     if((*pp1)->getName() > (*pp2)->getName()) // если первая строка больше второй,
     {
        person* tempptr = *pp1; // меняем их местами
        *pp1 = *pp2;
        *pp2 = tempptr;
     }
}
void salsort (person **pp,int n)
{
    for (int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if ((*(pp+j-1))->getSalary() > (*(pp+j))->getSalary())
            {
                person* temp = *(pp+j);
                *(pp+j) = *(pp+j-1);
                *(pp+j-1) = temp;
            }

        }


    }




}

int main()
{
    person * persPtr[LEN];
    for (int i=0; i<LEN;i++)
    {
        persPtr[i] = new person; // надо присвоить значение указателю
        persPtr[i]->setData();// так как иначе он указывает на неизвестный участок памяти
    }
    salsort(persPtr,LEN);
    for (int i=0;i<LEN;i++)
    {
        persPtr[i]->printData();
        delete persPtr[i];
    }



}
