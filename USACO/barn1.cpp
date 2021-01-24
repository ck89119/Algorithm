/*
ID: ck891191
PROG: barn1
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
int gap_size;
struct GAP
{
    int begin,end;
};

int cmp(const GAP &a,const GAP &b)
{
    return ((a.end-a.begin)<(b.end-b.begin));
}

int main()
{
    int m,s,c,stall[205];
    int i,ret;
    GAP gap[500];
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    scanf("%d%d%d",&m,&s,&c);
    for (i=0;i<c;i++) scanf("%d",&stall[i]);
    sort(stall,stall+c);
    gap_size=0;
    for (i=0;i<c-1;i++)
    {
        if (stall[i]+1==stall[i+1]) continue;
        gap[gap_size].begin=stall[i];
        gap[gap_size].end=stall[i+1];
        gap_size++;
    }
    sort(gap,gap+gap_size,cmp);
    ret=stall[c-1]-stall[0]+1;//dump(ret);
    for (i=gap_size-1;i>=gap_size-m+1&&i>=0;i--){
        ret-=(gap[i].end-gap[i].begin-1);
        //dump(i);dump(ret);
        }


    printf("%d\n",ret);
    return 0;
}
