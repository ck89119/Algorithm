/*
ID: ck891191
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <string>
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

int ccout(string a)
{
    int i;
    for (i=a.size()-1;i>=0;i--) cout<<a[i];
}

int main()
{
    int n;
    int i;
    string tmp1,tmp2;
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=300;i++)
    {
        tmp2=toN(i*i,n);
        if (pal(tmp2))
        {
            tmp1=toN(i,n);
            //cout<<tmp1<<' '<<tmp2<<endl;
            ccout(tmp1);
            ccout(" ");
            ccout(tmp2);cout<<endl;
        }
    }

    return 0;
}
