/*
ID: ck891191
PROG: stamps
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int k,n,value[55],l[2000005];
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
int input(){
    int i;
    freopen("stamps.in","r",stdin);
    scanf("%d%d",&k,&n);
    for (i=0;i<n;i++)
        scanf("%d",&value[i]);
    return 0;
}

int solve(){
    int i,j;
    memset(l,-1,sizeof(l));
    l[0]=k;
    for (i=0;;i++){
        for (j=0;j<n;j++)
                if (i-value[j]>=0&&l[i-value[j]]>0){
                    l[i]=Max(l[i],l[i-value[j]]-1);
                }
        if (l[i]==-1) break;
    }
    return i-1;
}

int output(){
    freopen("stamps.out","w",stdout);
    printf("%d\n",solve());
}
int main(){
    input();
    output();
    return 0;
}
