#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=50005;
int rank[maxn],pnt[maxn];
int ans;
int MakeSet(int x)
{
    rank[pnt[x]=x]=0;
    return 0;
}

int Find(int x)
{
    int px=x,i;
    while(px!=pnt[px]) px=pnt[px];
    while(x!=px)
    {
        i=pnt[x];
        pnt[x]=px;
        x=i;      
    }
    return px;
}

int Union(int x,int y)
{
    ans--;
    x=Find(x);y=Find(y);
    if (x==y) ans++;
    if (rank[x]>rank[y]) pnt[y]=x;
    else 
    {
         pnt[x]=y;
         rank[y]+=(rank[x]==rank[y]);
    }
    return 0;
}

int main()
{
    int m,n;
    int i,t1,t2,cases=0;
    while (scanf("%d%d",&n,&m),n||m)
    {
          for (i=1;i<=n;i++) MakeSet(i);
          ans=n;
          for (i=0;i<m;i++)
          {
              scanf("%d%d",&t1,&t2);
              Union(t1,t2);
          }
          printf("Case %d: %d\n",++cases,ans);
    }
    return 0;
}
