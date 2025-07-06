#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class Counter
{
    protected: // заметьте, что тут не следует использовать private
        unsigned int count; // счетчик
    public:
     Counter() : count() // конструктор без параметров
        { }
     Counter(int c) : count(c) // конструктор с одним параметром
        { }
     unsigned int get_count() const // получение значения
        { return count; }
     Counter operator++() // оператор увеличения
        { return Counter(++count); }
};
///////////////////////////////////////////////////////////
class CountDn : public Counter
{
    public:
        CountDn() : Counter() // конструктор без параметров
            { }
        CountDn(int c) : Counter(c) // конструктор с одним параметром
            { }
        CountDn operator--() // оператор уменьшения
            { return CountDn(--count); }
};
/////
class Counten: public CountDn
{
    public:
        Counten(): CountDn()
            {   }
        Counten(int c): CountDn(c)
            {   }
        using CountDn::operator--;
        using Counter::operator++;
        Counten operator++ (int)
            { return Counten (count++); }
        Counten operator-- (int)
            { return Counten (count--); }

};

int main()
{
    Counten t = 29;
    t++;
    cout<< t.get_count();


    return 0;
}
