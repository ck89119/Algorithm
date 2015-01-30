//const int maxn=maxm=1000005;
//const int inf=1000000000;
//int nbs[maxn],next[maxm],value[maxn],open[maxn],open1[maxn];
//int ev[maxm],ew[maxm],mk[maxn],n,m,num,cur,tail ;
//
//int BellmanFord (int src)
//{
//    int i,j,k,l,t,u,v,p=0;
//    for(i=1;i<=n;i++) {value[i]=inf;mk[i]=0;}
//    value[src]=tail=0;  open[0]=src;
//    while(++p,tail>=0){
//        for(i=0;i<=tail;i++) open1[i]=open[i];
//        for(cur=0,t=tail,tail=-1;cur<=t;cur++)
//           for(u=open1[cur],i=nbs[u];i;i=next[i]){
//               v=ev[i];
//               if (value[u]+ew[i]<value[v]){
//	               value[v]=value[u]+ew[i];
//                   if(mk[v]!=p){open[++tail]=v;mk[v]=p;}
//               }
//           }
//    }
//}

#include <iostream>
using namespace std;
const int inf=10000000;
const int maxv=100000;
const int maxe=1000000;
struct EDGE{
  int u, v;
  int w;
};
int noden, edgen, s;
int dis[maxv];
EDGE edge[maxe];

int init() {
    int i, u, v, w;
    cin >> noden >> edgen >> s;
    for (i = 1; i <= nodes; i++)
	  dis[i] = inf;
    dis[s] = 0;
    for (i = 1; i <= edgen; i++) {
      cin >> u >> v >> w;
      edge[i].u = u;
      edge[i].v = v;
      edge[i].w = w;
    }
    return 0;
}

int relax(int u, int v, int w) {
    if (dis[v] > dis[u] + w)
	  dis[v] = dis[u] + w;
    return 0;
}

int Bellman_Ford() {
    int i, j, flag;
    for (i = 1; i <= n-1; i++)
      for (j = 1; j <= edgen; j++) {
          relax(edge[j].u, edge[j].v, edge[j].w);
      }
    flag = 1;
    for (i = 1; i <= edgen; i++)
      if (dis[edge[i].v] > dis[edge[i].u] + edge[i].w) {
        flag = 0; 
		break;
      }
    return flag;
}

int main() {
    init();
    if (Bellman_Ford()) {
	  ...
	}
    return 0;
}
