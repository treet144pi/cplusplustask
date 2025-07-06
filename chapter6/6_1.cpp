#include <iostream>
#include <cstring>
using namespace std;

void reversit(char [],int);

int main()
{
    char str[] = "hello my freind nigger";
    int n = strlen(str);
    cout<<str<<endl;
    reversit(str,n);
    cout<<str<<endl;

    return 0;
}
void reversit(char s[],int n)
{
    char temp;
    for (int i =0;i< n /2;i++)
    {
        temp = s[i];
        s[i]= s[n-1-i];
        s[n-1-i]= temp;
    }

}
