/*
ID: ck891191
PROG: friday
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int isLeap(int n)
{
    if (n%4==0)
    {
        if (n%100==0&&n%400!=0) return 0;
        else return 1;
    }
    else return 0;
}

int main()
{
    int n,i,j,total[7],d,last;
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
    scanf("%d",&n);
    memset(total,0,sizeof(total));
    total[6]++;last=6;
    for (i=0;i<n;i++){
        for (j=0;j<12;j++){
            d=days[j];
            if (j==1) d+=isLeap(1900+i);
            total[(last+d)%7]++;
            last=(last+d)%7;
        }
    }
    total[last]--;
    printf("%d",total[6]);
    for (i=0;i<6;i++) printf(" %d",total[i]);
    printf("\n");
    return 0;
}
