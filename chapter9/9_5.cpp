#include <iostream>
using namespace std;
void addarrays(float*,float*,float*,int);
int main()
{
    float ar1[3]={1,2,3};
    float ar2[3]={-3,-2,-1};
    float ar[3];
    addarrays(ar1,ar2,ar,3);
    for (int i=0;i<3;i++)
        cout<<ar[i];
    return 0;
}
void addarrays(float *s1,float *s2,float *s3,int n)
{
    for (int i=0;i<n;i++)
        s3[i]= s1[i]+s2[i];
}
