/*
ID: ck891191
PROG: agrinet
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,dis[105],weight[105][105],visited[105],cost;
int input(){
    int i,j;
    freopen("agrinet.in","r",stdin);
    scanf("%d",&n);
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            scanf("%d",&weight[i][j]);
    return 0;
}

int prim(){
    int i,tree_size,min_cost,k;
    cost=0;
    for (i=0;i<n;i++) dis[i]=weight[0][i];
    memset(visited,0,sizeof(visited));
    visited[0]=1;tree_size=1;

    while (tree_size<n){
        min_cost=99999999;k=-1;
        for (i=0;i<n;i++)
            if (!visited[i]&&dis[i]<min_cost){
                min_cost=dis[i];
                k=i;
            }
        cost+=min_cost;
        visited[k]=1;tree_size++;
        for (i=0;i<n;i++)
            if (!visited[i]&&dis[i]>weight[k][i])
                dis[i]=weight[k][i];
    }
    return 0;
}

int output(){
    freopen("agrinet.out","w",stdout);
    printf("%d\n",cost);
    return 0;
}

int main(){
    input();
    prim();
    output();
    return 0;
}
