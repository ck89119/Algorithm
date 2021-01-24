/*
ID: ck891191
PROG: inflate
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int m,n,value[10005],cost[10005],p[10005];

inline int mmax(int a,int b){
    if (a>b) return a;
    else return b;
}

int input(){
    int i;
    freopen("inflate.in","r",stdin);
    scanf("%d%d",&m,&n);
    for (i=0;i<n;i++) scanf("%d%d",&value[i],&cost[i]);
    return 0;
}

int complete_pack(){
    int i,j;
    memset(p,0,sizeof(p));
    for (i=0;i<=m;i++)
        for (j=0;j<n;j++)
            if (i-cost[j]>=0){
                p[i]=mmax(p[i],p[i-cost[j]]+value[j]);
            }
    return 0;
}

int output(){
    int i,ret;
    freopen("inflate.out","w",stdout);
    ret=0;
    for (i=0;i<=m;i++)
        if (p[i]>ret) ret=p[i];
    printf("%d\n",ret);
}

int main(){
    input();
    complete_pack();
    output();
    return 0;
}
