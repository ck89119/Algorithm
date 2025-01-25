#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int m,n,t;
    int i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d%d",&m,&n);
        float ans=m*n;
        if (m*n%2)
        {
             ans=ans-1+sqrt(2.0);
        }
        printf("Scenario #%d:\n",i+1);
        printf("%.2f\n\n",ans);             
    }
    return 0;
}
