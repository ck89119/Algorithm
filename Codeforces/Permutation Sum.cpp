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

const int MAXN=20;
int n;
int res;

int isPermutation(int a[MAXN]){
    int visited[20];
    int i;
    memset(visited,0,sizeof(visited));
    for (i=0;i<n;i++)
        visited[a[i]]=1;
    for (i=1;i<=n;i++)
        visited[0]+=visited[i];
    if (visited[0]==n) return 1;
    else return 0;
}

inline int swap(int &x,int &y){int t=x;x=y;y=t;return 0;}

int nextPermutation(int a[MAXN]){
    int i;
    for (i=n-1;i>0;i--){
        if (a[i-1]<a[i]){
            int j=n-1;
            while (a[i-1]>=a[j]) j--;
            swap(a[i-1],a[j]);
            sort(a+i,a+n);
            return 1;
        }
    }
    return 0;
}

int solve(){
    int a[20],b[20],c[20];
    int i;
    for (i=0;i<n;i++) a[i]=i+1;
    res=0;
    do{
        for (i=0;i<n;i++) b[i]=i+1;
        do{
            for (i=0;i<n;i++) c[i]=(a[i]-1+b[i]-1)%n+1;
            if (isPermutation(c)) res=(res+1)%1000000007;
        }while(nextPermutation(b));
    }while(nextPermutation(a));
    return 0;
}

int output(){
    cout<<res<<endl;
    return 0;
}

int main(){
    //scanf("%d",&n);
    for (int i=1;i<=16;i++){
    n=i;
    solve();
    output();
    }
    return 0;
}
