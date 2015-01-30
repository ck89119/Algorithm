#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int gcd(int a,int b)
{
    if (a%b==0) return b;
    else return gcd(b,a%b);
}

int main()
{
    int n,arr[60];
    int sum,s;
    double ans;
    int i,j;
    while (scanf("%d",&n),n)
    {
          sum=0;s=n*(n-1)/2;
          for (i=0;i<n;i++) scanf("%d",&arr[i]);
          for (i=0;i<n-1;i++)
             for (j=i+1;j<n;j++) 
                if (gcd(arr[i],arr[j])==1) sum++;
          if (sum)
          {
               ans=sqrt((double)s*6/sum);
               printf("%.6lf\n",ans);
          }
          else 
          {
               printf("No estimate for this data set.\n");
          }
    }
    return 0;
}
