#include <iostream>
using namespace std;
enum etype { laborer, secretary, manager, accountant, executive, researcher };
int main()
{
    etype user_type;
    char ch;
    cout<<"Введите первую букву должности (laborer, secretary, manager, accountant,executive, researcher): ";
    switch (ch = getchar())
    {
        case 'l':
            user_type =laborer;
            break;
        case 's':
            user_type = secretary;
            break;
        case 'm':
            user_type =manager;
            break;
        case 'a':
            user_type = accountant;
            break;
        case 'e':
            user_type =executive;
            break;
        case 'r':
            user_type = researcher;
        default:
            break;
    }
    cout<<"полное название должности: ";
    switch (user_type)
    {
        case 0:
            cout<<"laborer"<<endl;;
            break;
        case 1:
            cout<<"secretary"<<endl;
            break;
        case 2:
            cout<<"manager"<<endl;
            break;
        case 3:
            cout<<" accountant"<<endl;
            break;
        case 4:
            cout<<"executive"<<endl;
            break;
        case 5:
            cout<< "researcher"<<endl;
        default:
            break;
    }




    return 0;
}
