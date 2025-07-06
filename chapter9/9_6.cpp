#include <iostream>
#include <cstring>
using namespace std;

int compstr(const char* s1,const char* s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int min_len = len1>len2 ? len2: len1;
    for (int i=0; i<min_len;i++)
    {
        if (s1[i]==s2[i])
            continue;
        if (s1[i] > s2[i])
            return 1;
        return -1;
    }
    if (len1 == len2)
        return 0;
    if (len1 >len2)
        return 1;
    return -1;

}

int main()
{
    const char* s1 ="";
    const char* s2 = "";
    cout<<compstr(s1,s2);


    return 0;
}
