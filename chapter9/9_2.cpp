#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class String
{
    private:
        char* str; // указатель на строку
    public:
        String(const char* s) // конструктор с одним параметром
        {
            int length = strlen(s); // вычисляем длину строки
            str = new char[length + 1]; // выделяем необходимую память
            strcpy(str, s); // копируем строку
        }
        ~String() // деструктор
        {
            cout << "Удаляем строку\n";
            delete[] str; // освобождаем память
        }
        void display() // покажем строку на экране
        {
            cout << str << endl;
        }
        void upit()
        {
            int len = strlen(str);
            for (int i=0;i<len;i++)
                str[i] = toupper(str[i]);
        }
};

int main()
{
    String str = "enter you gg wp";
    str.display();
    str.upit();
    str.display();

    return 0;
}
