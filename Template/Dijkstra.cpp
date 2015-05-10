#include <iostream>
#include <cstdio>
using namespace std;

const int inf=1000000000;
const int maxn=1000005;
const int maxm=1000005;
int n,m,num,len,next[maxm],ev[maxm],ew[maxm]; 
int value[maxn],mk[maxn],nbs[maxn],ps[maxn],heap[maxn]; 

int update (int r) 
{
    int q=ps[r],p=q>>1; 
    while(p && value[heap[p]]>value[r]){ 
        ps[heap[p]]=q; 
        heap[q]=heap[p]; 
        q=p;  p=q>>1;
    } 
    heap[q]=r; ps[r]=q;
    return 0;
}

int getmin() 
{ 
    int  ret=heap[1],p=1,q=2,r=heap[len--]; 
    while(q<=len){ 
       if (q<len && value[heap[q+1]]<value[heap[q]]) q++; 
       if (value[heap[q]]<value[r]) { 
           ps[heap[q]]=p; 
           heap[p]=heap[q]; 
           p=q;  q=p<<1; 
       } 
       else break;
    }
    heap[p]=r; ps[r]=p; 
    return  ret ; 
} 

int dijkstra(int src,int dst) 
{ 
    int i,j,u,v; 
    for(i=1;i<=n;i++) {value[i]=inf;mk[i]=ps[i]=0;} 
    value[src]=0; heap[len=1]=src; ps[src]=1; 
    while (!mk[dst]){
        if(len==0) return 0;
        u=getmin();  mk[u]=1;
        for(j=nbs[u];j;j=next[j]){
               v=ev[j]; 
               if(!mk[v]&&value[u]+ew[j]<value[v]){
                   if(ps[v]==0){heap[++len]=v;ps[v]=len;}
                   value[v]=value[u]+ew[j];   
                   update(v);
               }
        }
    }
}

int readdata() 
{
     int i,u,v,w; 
     cin>>n>>m; num=0; 
     for(i=1;i<=n;i++) nbs[i]=0; 
     while(m--){ 
         cin>>u>>v>>w; 
         next[++num]=nbs[u];  nbs[u]=num; 
         ev[num]=v;  ew[num]=w; 
     } 
     dijkstra(1,n);	//  Minimum  Distance  saved  at  value [ 1 . . n]
     return 0;
}

int main()
{
    
    return 0;
}
