#include <iostream>
#include <fstream>
using namespace std;

int main(int argc,char * argv[])
{
    if (argc != 2)
    {
        cerr<<"ERROR not arguments"<<endl;
        exit(-1);
    }

    fstream s;
    s.open(argv[1],ios::in);


    if (!s)
    {
        cerr<<"ERROR OPEN FILE"<<endl;
        exit(-1);
    }
    s.seekg(0,ios::end);
    // char ch; s.get(ch);
    int size_s = s.tellg();
    cout<<size_s<<endl;
    return 0;
}
