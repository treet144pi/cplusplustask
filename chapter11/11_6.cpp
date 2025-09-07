#include <iostream>
#include <fstream>
using namespace std;

class name
{
    private:
        char name_name[100];
        char surname[100];
        char family_name[100];
        int number;
    public:
        void read_name( int ) ; // по умолчанию читаем первую строку
        void write_name();
        void display();
};
void name::display()
{
    cout<<name_name<<' '<<surname<<' '<<family_name<<' '<<number<<endl;
}
void name::write_name()
{
    ofstream file;
    file.open("test6.txt",ios::app);

    file<<name_name<<' '<<surname<<' '<<family_name<<' '<<number<<endl;
    file.close();
}
void name::read_name(int number_line = 1)
{
    ifstream file;
    file.open("test6.txt");
    if (number_line <=0)
    {
        cout<<"ERROR your enter number line <0(your get the first line)"<<endl;
        number_line = 1;
    }
    for (int i=0; i<number_line;i++)
    {
        file>>name_name>>surname>>family_name>>number;
    }
    file.close();

}
int main()
{
    name first;
    first.read_name();
    first.write_name();
    first.read_name(3);

    first.display();
/*cin.get() - читает один символ

cin.get(char& ch) - сохраняет символ в переменную

cin.get(char* str, streamsize n, char delim) - читает строку до разделител
*/
    return 0;
}
