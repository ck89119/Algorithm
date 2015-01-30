#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n,b[60];
    int i,sum,h,set=1;
    while (scanf("%d",&n),n)
    {
          sum=0;
          for (i=0;i<n;i++) 
          {
              scanf("%d",&b[i]);
              sum+=b[i];
          }
          h=sum/n;
          sum=0;
          for (i=0;i<n;i++)
              if (b[i]>h) sum+=(b[i]-h);
          printf("Set #%d\n",set++);
          printf("The minimum number of moves is %d.\n\n",sum);
          
    }
    return 0;
}
