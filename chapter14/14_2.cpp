#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<string> ar;
    string input;
    for (int i=0;i<4;i++)
    {
        cin>>input;
        ar.push_back(input);
    }
    sort(ar.begin(),ar.end());
    for (int i=0;i<ar.size();i++)
        cout<<ar[i]<<' '<<ar[i].size()<<endl;




    return 0;
}
