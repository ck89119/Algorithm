/*
ID: ck891191
PROG: numtri
LANG: C++
*/

#include <iostream>
#include <cstdio>
using namespace std;
#define Max2(a,b) (a)>(b)?(a):(b)
int r,mat[1005][1005];
int init()
{
    int i,j;
    freopen("numtri.in","r",stdin);
    freopen("numtri.out","w",stdout);
    scanf("%d",&r);
    for (i=0;i<r;i++)
        for (j=0;j<=i;j++)
            scanf("%d",&mat[i][j]);
    return 0;
}

int solve()
{
    int i,j;
    for (i=r-2;i>=0;i--)
        for (j=0;j<=i;j++)
            mat[i][j]+=Max2(mat[i+1][j],mat[i+1][j+1]);
    printf("%d\n",mat[0][0]);
}

int main()
{
    init();
    solve();
    return 0;
}
