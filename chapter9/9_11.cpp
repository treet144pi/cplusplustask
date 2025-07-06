#include <iostream>
using namespace std;

const int LEN = 3;
class myarray
{
    private:
        int * ap[LEN];
    public:
        void input_arr()
        {
            for (int i=0;i<3;i++)
        {
            ap[i] = new int [3];
            for (int j=0;j<3;j++)
                cin>>ap[i][j];
        }
        }
        void output_arr()
        {
        for (int i=0;i<3;i++)
        {
            for (int j=0;j<3;j++)
                cout<<ap[i][j];
            cout<<endl;
            delete [] ap[i];


        }

        }
        int & operator[] (int n)
        {
            int i = n/LEN;
            int j = n%LEN;
            return ap[i][j];
        }
};
int main()
{
    myarray ar;

    ar.input_arr();
    for (int i=0;i<LEN*LEN;i++)
        cout<<ar[i];



}
