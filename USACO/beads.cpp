/*
ID: ck891191
PROG: beads
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
int main()
{
    char str[705],ch;
    int r[705],l[705],len;
    int i,j,max;
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    scanf("%d",&len);getchar();
    scanf("%s",str);
    for (i=0;i<len;i++) str[len+i]=str[i];
    str[2*len]='\0';
    //dump(str);
    for (i=0;i<2*len;i++)
    {
        ch=str[i];
        l[i]=0;
        j=i;
        while (j<2*len&&j<len+i&&(str[j]==ch||str[j]=='w'||ch=='w'))
        {
            l[i]++;
            j++;
            if (ch=='w') ch=str[j];
        }
        //dump(l[i]);
    }
    for (i=2*len-1;i>=0;i--)
    {
        ch=str[i];
        r[i]=0;
        j=i;
        while (j>=0&&j>i-len&&(str[j]==ch||str[j]=='w'||ch=='w'))
        {
            r[i]++;
            j--;
            if (ch=='w') ch=str[j];
        }
        //dump(r[i]);
    }
    max=l[0]+r[2*len-1];
    for (i=1;i<2*len;i++)
        if (r[i-1]+l[i]>max) max=r[i-1]+l[i];
    if (max>len) max=len;
    printf("%d\n",max);
    return 0;
}
