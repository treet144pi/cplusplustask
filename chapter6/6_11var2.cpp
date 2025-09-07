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
        string ldtoms( long double n)
        {
            ostringstream n_str; // поток вывода в строку
            n_str << n; // запись в поток

            string bufstring = n_str.str(); // получение строки
            size_t point_ind = bufstring.find('.');

            string frac_part = "";
            if (point_ind != string::npos)
            {
                frac_part = bufstring.substr(point_ind);
            }
            else
                point_ind = bufstring.size();
// C++ можно присвоить часть одной строки другой, используя метод substr класса std::string.
//Параметры substr:
//Первый аргумент — позиция (pos), с которой начинается подстрока (индексация с 0).
//Второй аргумент — длина (count) подстроки. Если не указан, берётся всё от pos до конца строки.

            int indent_number = point_ind%3;
            string whole_part = bufstring.substr(0, indent_number);
            if (indent_number != 0 )
                whole_part += ' ';

            for (int i= indent_number; i<point_ind;i+= 3)
                whole_part+= bufstring.substr(i,3)+" ";
            whole_part.pop_back();

            return "$"+whole_part+frac_part;
        }
};
int main()
{
    money f;
    long double n = 3233322221.2222l;

// Устанавливаем максимальную точность (до 18-19 знаков для long double)
    cout<<setiosflags(ios::fixed) //нормальный неэкспонициальный вид
        <<setiosflags(ios::showpoint) // всегда показывать десятичную точку
        <<setprecision(18)
        <<f.ldtoms(n)<<endl;
    return 0;
}
