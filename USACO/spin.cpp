/*
	ID: ck891191
	PROG: spin
	LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct WHEEL{
    int v;
    int cur,wedge[360];
};
WHEEL wheel[5];

int input(){
    int i,j,k,n,b,e;
    freopen("spin.in","r",stdin);
    freopen("spin.out","w",stdout);
    for (i=0;i<5;i++){
        wheel[i].cur=0;
        scanf("%d",&wheel[i].v);
        scanf("%d",&n);
        memset(wheel[i].wedge,0,sizeof(wheel[i].wedge));
        for (j=0;j<n;j++){
            scanf("%d%d",&b,&e);
            for (k=b;k<=b+e;k++) wheel[i].wedge[k%360]=1;
        }
    }
    return 0;
}

int check(int n){
    int i,j,w[360];
    memset(w,0,sizeof(w));
    for (i=0;i<360;i++)
        for (j=0;j<5;j++)
            if (wheel[j].wedge[i]){
                w[(i+wheel[j].v*n)%360]+=wheel[j].wedge[i];
            }
    for (i=0;i<360;i++)
        if (w[i]==5) return 1;
    return 0;
}

int solve(){
    int l,i,j;
    for (i=0;i<360;i++){
        if (check(i)) break;
    }
    if (i<360) printf("%d\n",i);
    else printf("none\n");
    return 0;
}

int main(){
    input();
    solve();
    return 0;
}
