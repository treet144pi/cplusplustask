#include <iostream>
using namespace std;

const int len =100;

float fmemory[len];
int pmemory[len];
int fmemtop=0;
int pmemtop=0;

class Float
{
    int addr;
    public:
    Float(float n)
    {
        addr = fmemtop;
        fmemory[fmemtop++]=n;
    }
    int operator& () // перегрузка операции взятие адреса
    {
        return addr;
    }



};
class ptrFloat
{
    int addr;
    public:
    ptrFloat(int ptr)
    {
        addr = pmemtop;
        pmemory[pmemtop++] = ptr;
    }
    float& operator* () // перегрузка операции разыменования
    {
        return fmemory[pmemory[addr]];

    }
};
int main()
{
    Float var1 = 1.234; // определяем и инициализируем
    Float var2 = 5.678; // две вещественные переменные
    ptrFloat ptr1 = &var1; // определяем и инициализируем
    ptrFloat ptr2 = &var2; // два указателя
    cout << " *ptr1 = " << *ptr1; // получаем значения переменных
    cout << " *ptr2 = " << *ptr2; // и выводим на экран
    *ptr1 = 7.123; // присваиваем новые значения
    *ptr2 = 8.456; // переменным, адресованным через указатели
    cout << " *ptr1 = " << *ptr1; // снова получаем значения
    cout << " *ptr2 = " << *ptr2; // и выводим на экран




    return 0;
}



