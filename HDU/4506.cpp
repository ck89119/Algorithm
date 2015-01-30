/*
ID: ck891191
PROG:
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define dump(x) cerr<<__LINE__<<"  "<<#x<<"  :  "<<(x)<<endl;
const int MOD=1000000007;
int T,n,t,k;
int a[10005];

long long power(int x,int y){
    long long t;
    if (y==0) return 1;
    if (y==1) return x%MOD;
    t=power(x,y/2);
    if (y%2) return t*t%MOD*x%MOD;
    else return t*t%MOD;
}

int input(){
    int i;
    scanf("%d%d%d",&n,&t,&k);
    for (i=1;i<=n;i++)
        scanf("%d",&a[i]);
    return 0;
}

int solve(){
    long long kt=power(k,t);
    int i;
    t=t%n;
    if (t!=0){
        for (i=n-t+1;i<=n;i++)
            printf("%d ",kt*a[i]%MOD);
        for (i=1;i<n-t;i++)
            printf("%d ",kt*a[i]%MOD);
        printf("%d\n",kt*a[n-t]%MOD);
    }
    else {
        for (i=1;i<n;i++)
            printf("%d ",kt*a[i]%MOD);
        printf("%d\n",kt*a[n]%MOD);
    }
    return 0;
}

int main(){
    scanf("%d",&T);
    //dump(T);
    while (T--){
        //dump(T);
        input();
        solve();
        //dump(T);
    }
    return 0;
}
