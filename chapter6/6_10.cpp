#include <iostream>
#include <stdlib.h>
using namespace std;

class matrix
{
    private:
        int *arr;
        int rows;
        int columns;
    public:
        matrix(int r = 10,int c = 10)
        {
            if (r> 10 || c>10 || r<0 || c<0)
                exit(-1);
            rows = r; columns = c;
            arr =  new int [r*c];
        }
        ~matrix()
        {  delete[] arr; }

        void putel(int r,int c,int d)
        {
            if (r>= rows || c>=columns || r<0 || c<0)
                exit(-1);
            arr[r*columns+c] =d; }
        int getel(int r,int c) const
        {

            if (r>= rows || c>=columns || r<0 || c<0)
                exit(-1);
            return arr[r*columns+c];
        }
};
int main()
{
    matrix ml(3, 4); // описываем матрицу
    int temp = 12345; // описываем целое
    ml.putel(1, 3, temp); // помещаем значение temp в матрицу
    temp = ml.getel(1, 3); //
    cout<<ml.getel(1, 3);


    return 0;
}
