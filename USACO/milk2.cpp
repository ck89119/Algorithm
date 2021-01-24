/*
ID: ck891191
PROG: milk2
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t[1000005];

int main()
{
    int n;
    int i,j,b,e,max,min,la,lb,tmp;
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    scanf("%d",&n);
    memset(t,0,sizeof(t));
    max=0;min=1000005;
    for (i=0;i<n;i++)
    {
        scanf("%d%d",&b,&e);
        if (b<min) min=b;
        if (e>max) max=e;
        for (j=b;j<e;j++) t[j]=1;
    }
    la=0;lb=0;tmp=0;
    for (i=min;i<max;i++)
    {
        if (i==min||t[i]==t[i-1]) tmp++;
        else
        {
            if (t[i-1]&&tmp>la) la=tmp;
            if (!t[i-1]&&tmp>lb) lb=tmp;
            tmp=1;
        }
    }
    if (t[i-1]&&tmp>la) la=tmp;
    if (!t[i-1]&&tmp>lb) lb=tmp;
    printf("%d %d\n",la,lb);
    return 0;
}
