/*
ID: ck891191
PROG: rockers
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
//const int INF=99999999;
int N,T,M;
int len[25];
int l[25];
int res,sum;


int input(){
    int i;
    freopen("rockers.in","r",stdin);
    scanf("%d%d%d",&N,&T,&M);
    for (i=0;i<N;i++)
        scanf("%d",&len[i]);
    for (i=0;i<M;i++) l[i]=T;
    return 0;
}

int dfs(int n,int l[25],int m){
    //if (n==N) dump(sum);
    if (N-n+sum<=res) return 0;
    if (n==N) return 0;
    if (len[n]>T) {dfs(n+1,l,m);return 0;}
    if (l[m]>=len[n]){
        l[m]-=len[n];
        sum++;
        if (sum>res) res=sum;
        dfs(n+1,l,m);
        l[m]+=len[n];
        sum--;
    }
    else if (m<M-1){
        l[m+1]-=len[n];
        sum++;
        if (sum>res) res=sum;
        dfs(n+1,l,m+1);
        l[m+1]+=len[n];
        sum--;
    }
    dfs(n+1,l,m);
    return 0;
}

int solve(){
    res=0;
    sum=0;
    dfs(0,l,0);
    return 0;
}

int output(){
    freopen("rockers.out","w",stdout);
    printf("%d\n",res);
    return 0;
}

int main(){
    input();
    solve();
    output();
    return 0;
}
