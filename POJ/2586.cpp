#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int d,s,ans;
    double t1,t2,t3,t4;
    while (scanf("%d%d",&s,&d)!=EOF)
    {
          t1=4.0*s;t2=3.0*s/2;t3=2.0*s/3;t4=1.0*s/4;
          ans=-1;
          if (d>t1) ans=10*s-2*d;
          else if (d>t2) ans=8*s-4*d;
          else if (d>t3) ans=6*s-6*d;
          else if (d>t4) ans=3*s-9*d;
          if (ans>=0) printf("%d\n",ans);
          else printf("Deficit");
    }
    
    return 0;
}
