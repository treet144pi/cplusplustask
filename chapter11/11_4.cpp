#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream out_data;
    out_data.open("11_4show.txt");
    while (true)
    {
        char name_full[100];
        unsigned long number;
        cout<<"ENTER your full name: "<<endl;
        cin.getline(name_full,100);
        cout<<"ENTER your number:";
        cin>>number;
        out_data<<name_full<<' '<<number<<endl;
        char quit;
        cout<<"ENTER q to quit: ";
        cin>>quit;
        cin.ignore();
        if (quit == 'q')
            break;
    }
    out_data.close();
    ifstream show;
    show.open("11_4show.txt");
    show.seekg(0);
    char out_line[130];
    while (show.getline(out_line,130)) // если чтение успешно(без ошибок) то все нормально инае 0
    {
        // show.getline(out_line,130); // читается до перевода строки и не сохраняет и удаляет из потока
        cout<<out_line<<endl;
    }



    return 0;
}
