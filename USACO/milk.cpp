/*
ID: ck891191
PROG: milk
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct MILK
{
    int p,a;
};

int cmp(const MILK &a,const MILK &b)
{
    return (a.p<b.p);
}

int main()
{
    MILK farm[5005];
    int n,m;
    int i,sum;
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (i=0;i<m;i++)
        scanf("%d%d",&farm[i].p,&farm[i].a);
    sort(farm,farm+m,cmp);
    sum=0;
    for (i=0;i<m&&n>0;i++)
    {
        if (n>=farm[i].a)
        {
            n-=farm[i].a;
            sum+=farm[i].a*farm[i].p;
        }
        else
        {
            sum+=farm[i].p*n;
            n=0;
        }
    }
    printf("%d\n",sum);
    return 0;
}
