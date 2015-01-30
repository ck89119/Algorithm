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

int p[2*1000005];
int n;

int input(){
    int i;
    scanf("%d",&n);
    for (i=1;i<=n;i++) p[i]=i;
    return 0;
}

int solve(){
    int i,j,ii;
    int t1,t2;
    for (i=2;i<=n;i++){
        t1=p[i-1];
        for (j=i+i-1;j<n+i-1;j+=i){
            t2=p[j];
            p[j]=t1;
            t1=t2;
        }
        p[n+i-1]=t1;
//        for (ii=i;ii<n+i;ii++)
//            printf("%d ",p[ii]);
//        printf("\n");
    }
    return 0;
}

int output(){
    int i;
    for (i=n;i<n+n;i++)
        printf("%d ",p[i]);
    printf("\n");
    return 0;
}

int main(){
    input();
    solve();
    output();
    return 0;
}
