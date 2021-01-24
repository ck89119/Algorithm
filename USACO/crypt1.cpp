/*
ID: ck891191
PROG: crypt1
LANG: C++
*/

#include <iostream>
#include <cstdio>
using namespace std;
#define dump(x)  cerr<< __LINE__ << " : " << #x << " = " << (x) <<endl;
int n,digit[15];

int isIn(int a)
{
    int i,flag=1;
    while (a!=0)
    {
        int tmp=a%10,f=1;
        for (i=0;i<n;i++)
            if (tmp==digit[i]) {f=0;break;}
        if (f) {flag=0;break;}
        a/=10;
    }
    return flag;
}

int solve()
{
    int i,j,k,l,m;
    int ret=0;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            for (k=0;k<n;k++)
                for (l=0;l<n;l++)
                    for (m=0;m<n;m++)
                    {
                        int tmp=100*digit[i]+10*digit[j]+digit[k];
                        //dump(tmp);dump(digit[l]);dump(digit[m]);
                        if (tmp*digit[l]>=100&&tmp*digit[l]<=999&&isIn(tmp*digit[l])
                          &&tmp*digit[m]>=100&&tmp*digit[m]<=999&&isIn(tmp*digit[m])
                          &&tmp*(digit[l]*10+digit[m])>=1000
                          &&tmp*(digit[l]*10+digit[m])<=9999
                          &&isIn(tmp*(digit[l]*10+digit[m]))) ret++;
                    }
    printf("%d\n",ret);
    return 0;
}

int main()
{

    int i;
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);
    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%d",&digit[i]);
    solve();
    return 0;
}
