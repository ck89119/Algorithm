#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int r,m,y;
    int i;
    double ans,rr;
    scanf("%d%d%d",&r,&m,&y);
    ans=m;rr=1+r/100.0;
    for (i=0;i<y;i++)
        ans*=rr;
    i=(int)ans;
    printf("%d\n",i);system("pause");
    return 0;
}
