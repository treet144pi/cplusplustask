#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
using namespace std;
/*Вместо устаревших классов из <strstream> (таких как ostrstream, istrstream и strstream), в современном C++ (начиная с C++98) рекомендуется использовать <sstream>.

Эти классы безопаснее, удобнее и поддерживают автоматическое управление памятью через std::string.
std::ostringstream – поток вывода в строку <<
std::istringstream – поток ввода из строки >>
std::stringstream – поток ввода-вывода
*/
class money
{
    public:
        long double mstold(char const str[])
        {
            char s[20];
            int n = strlen(str);
            int k = 0;
            for (int i =0;i<n;i++)
            {
                if (str[i] == '.')
                    s[k++]= '.';
                else if (str[i] == '\0' )
                    break;
                else if (str[i]-'0'>=10 || str[i]-'0'<0)
                    continue;
                else
                    s[k++] = str[i];
            }
            s[k] = '\0';
            return stold(s);
        }
        /*Нужно ли добавлять нулевой символ (\0) при работе с <sstream>?
Короткий ответ: Нет, не нужно! std::string и классы из <sstream> автоматически добавляют нулевой символ при формировании строки.*/
        string ldtoms( double n)
        {
            ostringstream n_str; // поток вывода в строку
            n_str << n; // запись в поток
            string bufstring = n_str.str(); // получение строки
/*В C++ у класса std::string (и других контейнеров, например, std::vector) есть два способа доступа к элементам по индексу:
Оператор [] (квадратные скобки) — быстрый, но без проверки границ.
Метод .at() — медленнее, но с проверкой выхода за границы.
*/

            string result_str;
            // Для std::string никогда не добавляйте \0 вручную.
            int len = bufstring.size();
            reverse(bufstring.begin(),bufstring.end());

            size_t point = bufstring.find('.');
            if (point != string::npos) // Возвращает позицию символа или std::string::npos, если символ не найден
            {
                point++;
                len -= point;
                string copied(bufstring.begin(),bufstring.begin()+point);
                result_str +=copied;
            }
            else
                point = 0;
            for (int i =0;i<len;i++)
            {
                if (i%3 ==0 && i!=0 )
                    result_str +=' ';
                result_str += bufstring[point+i];

            }
            result_str += '$';
            reverse(result_str.begin(),result_str.end());
            return result_str;

        }
};
int main()
{
    money f;
    long double n = 4221.22;
    cout<< f.ldtoms(n);


    return 0;
}
