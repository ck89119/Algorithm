/*
ID: ck891191
PROG: money
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,v,value[30];
long long dp[10005];
int init(){
    int i;
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    scanf("%d%d",&v,&n);
    for (i=1;i<=v;i++) scanf("%d",&value[i]);
    memset(dp,0,sizeof(dp));
    return 0;
}

int solve(){
    int i,j;
    dp[0]=1;
    for (i=1;i<=v;i++)
        for (j=0;j<=n;j++)
            if (j-value[i]>=0){
                dp[j]=dp[j]+dp[j-value[i]];
            }
    return 0;
}

int print(){
    printf("%lld\n",dp[n]);
    return 0;
}
int main(){
    init();
    solve();
    print();
    return 0;
}
