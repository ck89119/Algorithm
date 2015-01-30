/*
ID: ck891191
PROG: fence9
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
int n,m,p;

int input(){
    freopen("fence9.in","r",stdin);
    freopen("fence9.out","w",stdout);
    scanf("%d%d%d",&n,&m,&p);
    return 0;
}

int solve(){
    int i,j,b;
    b=p+1;
    if (n==0) b+=m+1;
    else
        for (i=0;i<=n;i++)
            if (m*i%n==0) b++;

    if (n==p) b+=m+1;
    else
        for (i=min(n,p);i<=max(n,p);i++)
            if (m*(i-p)%(n-p)==0) b++;
    b-=3;
    printf("%d\n",(m*p-b)/2+1);
    return 0;
}

int main(){
    input();
    solve();
    return 0;
}
