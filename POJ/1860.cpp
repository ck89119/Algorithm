#include <iostream>
#include <cstdio>
using namespace std;
const int maxv=1000;
const int maxe=10000;
struct EDGE{
    int u,v;
    double r,c;
};
int noden,edgen,s;
double money;
double dis[maxv];
EDGE edge[maxe];

int init(){
    int i,u,v;
    double r1,r2,c1,c2;
    cin>>noden>>edgen>>s>>money;
    edgen*=2;
    for (i=1;i<=noden;i++) dis[i]=0;
    dis[s]=money;
    for (i=1;i<=edgen/2;i++){
        cin>>u>>v>>r1>>c1>>r2>>c2;
        edge[i].u=u;
        edge[i].v=v;
        edge[i].r=r1;
        edge[i].c=c1;
        edge[i+edgen/2].u=v;
        edge[i+edgen/2].v=u;
        edge[i+edgen/2].r=r2;
        edge[i+edgen/2].c=c2;
    }
    return 0;
}

int relax(int j){
    if (dis[edge[j].v]<(dis[edge[j].u]-edge[j].c)*edge[j].r){
        dis[edge[j].v]=(dis[edge[j].u]-edge[j].c)*edge[j].r;
        return 1;
    }
    else return 0;
}

int Bellman_Ford(){
    int i,j,flag;
    for (i=1;i<=noden-1;i++)
        for (j=1;j<=edgen;j++){
            relax(j);
            if (dis[s]>money) return 1;
        }
    flag=0;
    for (i=1;i<=edgen;i++)
        if (relax(i)){
            flag=1;break;
        }
    return flag;
}

int main(){
    init();
    if (Bellman_Ford()) printf("YES\n");
    else printf("NO\n");
    return 0;
}
