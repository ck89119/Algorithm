/*
ID: ck891191
PROG: subset
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,sum;
long long dp[805];
int init(){
    freopen("subset.in","r",stdin);
    freopen("subset.out","w",stdout);
    scanf("%d",&n);
    sum=n*(n+1)/2;
    memset(dp,0,sizeof(dp));
    return 0;
}

int solve(){
    int i,j;
    if (sum%2==1) return 0;
    dp[0]=1;
    for (i=1;i<=n;i++){
        for (j=sum;j>=1;j--){
            if (j-i>=0){
                dp[j]+=dp[j-i];
            }
            //cout<<dp[j]<<' ';
        }
        //cout<<endl;
    }
    return 0;
}

int print(){
    printf("%d\n",dp[sum/2]/2);
    return 0;
}
int main(){
    init();
    solve();
    print();
    return 0;
}
