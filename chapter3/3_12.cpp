#include <iostream>
using namespace std;
struct fraction{
    int nominator;
    int denominator;
};
int main()
{
    char op;
    fraction a,b;
    char slash_trash;
    cout<< "enterf your first fraction(use /)"<<endl;
    cin>>a.nominator>>slash_trash>>a.denominator;
    cout<< "enterf your second fraction(use /)"<<endl;
    cin>>b.nominator>>slash_trash>>b.denominator;
    cout<< "enter operation that you use"<<endl;
    cin>> op;
    switch (op)
{
    case '+':
        cout<<"your sum: "
            <<a.nominator*b.denominator+ a.denominator*b.nominator
            <<'/'<< a.denominator*b.denominator<<endl;
        break;
     case '-':
        cout<<"your diff: "
            <<a.nominator*b.denominator- a.denominator*b.nominator
            <<'/'<< a.denominator*b.denominator<<endl;
        break;
    case '*':
        cout<<"your mull: "
            <<a.nominator*b.nominator
            <<'/'<< a.denominator*b.denominator<<endl;
        break;
    case '/':
        cout<<"your div: "
            <<a.nominator*b.denominator
            <<'/'<< a.denominator*b.nominator<<endl;
        break;
    default:
        cout<<"your operation is not found ERROR ";
        break;
}




    return 0;
}
