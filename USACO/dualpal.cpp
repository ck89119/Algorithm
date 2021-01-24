/*
ID: ck891191
PROG: dualpal
LANG: C++
*/

#include <iostream>
#include <cstdio>
using namespace std;

string toN(int num,int n)
{
    const int mapping[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
    int i;
    string ret;
    while (num!=0)
    {
        ret.push_back(mapping[num%n]);
        num/=n;
    }
    return ret;
}

int pal(string s)
{
    int i,flag=1;
    for (i=0;i<s.size()/2;i++)
        if (s[i]!=s[s.size()-1-i]) {flag=0;break;}
    return flag;
}

int main()
{
    int n,s;
    int sum=0,i,j;
    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);
    scanf("%d%d",&n,&s);
    for (i=s+1;sum<n;i++)
    {
        int tmp=0;
        for (j=2;j<=10;j++)
        {
            if (pal(toN(i,j))) tmp++;
            if (tmp>=2) break;
        }
        if (tmp>=2)
        {
            printf("%d\n",i);
            sum++;
        }
    }
    return 0;
}
