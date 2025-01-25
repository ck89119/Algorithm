#include<iostream>
#include<vector>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;

int cal(int n)
{
    int i,s=0;
    for (i=1;i*i<=n;i++) 
       if (n%i==0) s++;
    return s*2;
}

int main()
{
    int i,j;
    int sum;
    i=1;j=2;
    while (sum<=500)
    {
          i+=j;j++;
          sum=cal(i);
          sum++;       
    }
    printf("%d\n",i);system("pause");   
    return 0;
}
