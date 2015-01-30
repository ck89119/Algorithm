#include <iostream>
using namespace std;
const int maxn=30005;
int rank[maxn],pnt[maxn]; 
int makeset(int x) 
{ 
    rank[pnt[x]=x]=0; 
    return 0;
} 

int find(int x) 
{ 
    int px=x,i; 
    while(px!=pnt[px]) px=pnt[px]; 
    while(x!=px){  
        i=pnt[x] ;  
        pnt[x]=px ;  
        x=i;	
    }
    return px;
} 

int merge(int x,int y)	// or  just  pnt[find(x)]= find(y)
{
    if (rank[x=find(x)]>rank[y=find(y)]) pnt[y]=x;
    else{ 
        pnt[x]=y;
        rank[y]+=(rank[x]==rank[y]);	
    }
    return 0;
}

int main()
{
    int m,n,root,ans;
    int i,k,j,t1,t2;
    while (scanf("%d%d",&n,&m),n||m)
    {
          for (i=0;i<n;i++) makeset(i);
          for (i=0;i<m;i++)
          {
              scanf("%d",&k);
              if (k>0) scanf("%d",&t1);
              for (j=1;j<k;j++)
              {
                  scanf("%d",&t2);
                  merge(t1,t2);
              }
          }
          root=find(0);ans=0;
          for (i=0;i<n;i++) 
              if (find(i)==root) ans++;
          printf("%d\n",ans);
    }
    return 0;
}
