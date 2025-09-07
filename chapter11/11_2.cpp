#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int main(int argv, char * argc[])
{
    if (argv !=3)
    {
        cerr<<"ERROR not argments"<<endl;
        exit(-1);
    }
    ifstream file_inp; // создать входной поток
    ofstream file_out; //создать выходной поток
    file_inp.open(argc[1]);
    if (!file_inp)
    {
        cerr<<"UNREAL OPEN file:"<<argc[1]<<endl;
        exit(-1);
    }
    file_out.open(argc[2]);
    if (!file_inp)
    {
        cerr<<"UNREAL OPEN file:"<<argc[2]<<endl;
        exit(-1);
    }
    char ch;
    while (!file_inp.eof())
    {
        file_inp.get(ch);
        file_out.put(ch);
    }




    return 0;
}
