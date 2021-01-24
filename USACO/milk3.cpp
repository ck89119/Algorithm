/*
ID: ck891191
PROG: milk3
LANG: C++
*/


#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a,b,c,statue[21][21][21];

int init()
{
    freopen("milk3.in","r",stdin);
    freopen("milk3.out","w",stdout);
    scanf("%d%d%d",&a,&b,&c);
    memset(statue,0,sizeof(statue));
    return 0;
}

int dfs(int va,int vb,int vc)
{
    statue[va][vb][vc]=1;
    if (va!=0)
    {
        if (va+vb>b&&!statue[va+vb-b][b][vc])
        {
            dfs(va+vb-b,b,vc);
            //statue[va+vb-b][b][vc]=0;
        }
        if (va+vb<=b&&!statue[0][va+vb][vc])
        {
            dfs(0,va+vb,vc);
            //statue[0][va+vb][vc]=0;
        }
        if (va+vc>c&&!statue[va+vc-c][vb][c])
        {
            dfs(va+vc-c,vb,c);
            //statue[va+vc-c][vb][c]=0;
        }
        if (va+vc<=c&&!statue[0][vb][va+vc])
        {
            dfs(0,vb,va+vc);
            //statue[0][vb][va+vc]=0;
        }
    }

    if (vb!=0)
    {
        if (vb+va>a&&!statue[a][vb+va-a][vc])
        {
            dfs(a,va+vb-a,vc);
            //statue[a][va+vb-a][vc]=0;
        }
        if (va+vb<=a&&!statue[vb+va][0][vc])
        {
            dfs(va+vb,0,vc);
            //statue[va+vb][0][vc]=0;
        }
        if (vb+vc>c&&!statue[va][vb+vc-c][c])
        {
            dfs(va,vb+vc-c,c);
            //statue[va][vb+vc-c][c]=0;
        }
        if (vb+vc<=c&&!statue[va][0][vb+vc])
        {
            dfs(va,0,vb+vc);
            //statue[va][0][vb+vc]=0;
        }
    }

    if (vc!=0)
    {
        if (va+vc>a&&!statue[a][vb][vc+va-a])
        {
            dfs(a,vb,vc+va-a);
            //statue[a][vb][vc+va-a]=0;
        }
        if (va+vc<=a&&!statue[va+vc][vb][0])
        {
            dfs(va+vc,vb,0);
            //statue[va+vc][vb][0]=0;
        }
        if (vb+vc>b&&!statue[va][b][vb+vc-b])
        {
            dfs(va,b,vb+vc-b);
            //statue[va][b][vb+vc-b]=0;
        }
        if (vb+vc<=b&&!statue[va][vb+vc][0])
        {
            dfs(va,vb+vc,0);
            //statue[va][vb+vc][0]=0;
        }
    }
    return 0;
}

int solve()
{
    dfs(0,0,c);
    return 0;
}

int print()
{
    int i,j,ret[21],total,t;
    memset(ret,0,sizeof(ret));
    for (i=0;i<=20;i++)
        for (j=0;j<=20;j++)
            if (statue[0][i][j]) ret[j]=1;
    total=0;
    for (i=0;i<=20;i++)
        if (ret[i]&&!total) {printf("%d",i);total++;}
        else if (ret[i]&&total) {printf(" %d",i);total++;}
    printf("\n");
}

int main()
{
    init();
    solve();
    print();
    return 0;
}
