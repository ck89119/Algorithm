/*
ID: ck891191
PROG:
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <map>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;

const int MAXN=200000;
long long mem[MAXN+1][2];
int visited[MAXN+1][2];
int b[MAXN+1][2];
int a[MAXN+1];
int n;

int input(){
    int i;
    scanf("%d",&n);
    for (i=2;i<=n;i++)
        scanf("%d",&a[i]);
    return 0;
}

int search(int x,int k){
    int i,tx;
   // dump(x);
   // dump(k);
    if (visited[x][k]==1){
        mem[x][k]=-1;
        return 0;
    }

//    if (mem[x][k]!=0){
//        return 0;
//    }
    if (visited[x][k]==2){
        return 0;
    }

    if (x==1&&k==1){
        b[x][k]=1;
        mem[x][k]=0;
        return 0;
    }
    mem[x][k]+=a[x];
    visited[x][k]=1;
    tx=x;
    if (k) tx-=a[x];else tx+=a[x];
    if (tx>=1&&tx<=n){
        search(tx,k^1);
        if (mem[tx][k^1]!=-1){
            mem[x][k]+=mem[tx][k^1];
            b[x][k]=b[tx][k^1];
        }
        else mem[x][k]=-1;
    }
    visited[x][k]=2;
    return 0;
}

int solve(){
    int i;
    memset(mem,0,sizeof(mem));
    memset(b,0,sizeof(b));
    memset(visited,0,sizeof(visited));
    visited[1][0]=1;
    for (i=2;i<=n;i++){
        if (!visited[i][1]) search(i,1);
    }


    for (i=1;i<n;i++){
        a[1]=i;a[0]=0;
        if (mem[i+1][1]==-1) printf("-1\n");
        else printf("%I64d\n",mem[i+1][1]+i+a[b[i+1][1]]);
    }
    return 0;
}


//long long dfs(int x,int state){
//    int tx;
//    long long ty;
//    if (state==0) tx=x+a[x];
//    else tx=x-a[x];
//    ty=mem[x][state]+a[x];
//
//    if (tx>n||tx<=0) return ty;
//    if (mem[tx][1-state]!=-1) return -1;
//
//    mem[tx][1-state]=ty;
//    return dfs(tx,1-state);
//}
//
//int solve(){
//    int i;
//
//    for (i=1;i<n;i++){
//        a[1]=i;
//        memset(mem,-1,sizeof(mem));
//        mem[1][0]=0;
//        printf("%I64d\n",dfs(1,0));
//    }
//
//    return 0;
//}

int main(){
    input();
    solve();
    return 0;
}
