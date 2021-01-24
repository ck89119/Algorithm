/*
ID: ck891191
PROG: nuggets
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
int num[100000];
int n;
int v[15],min_v;
int res;

int input(){
    int i;
    freopen("nuggets.in","r",stdin);
    freopen("nuggets.out","w",stdout);
    min_v=300;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&v[i]);
        min_v=min(min_v,v[i]);
    }
    return 0;
}

int gcd(int a,int b){
    if (b==0) return a;
    else return gcd(b,a%b);
}

int solve(){
    int i,j,g;
    if (min_v==1){
        res=0;
        return 0;
    }

    g=v[0];
    for (i=1;i<n;i++)
        g=gcd(g,v[i]);
    if (g!=1){
        res=0;
        return 0;
    }

    memset(num,0,sizeof(num));
    num[0]=1;
    for (i=0;i<n;i++)
        for (j=0;j<100000;j++)
            if (j>=v[i]&&num[j-v[i]])
                num[j]=1;
    for (i=1;i<100000;i++)
        if (!num[i]){
            j=i+1;
            while (num[j]&&j-i<=min_v) j++;
            if (j-i>min_v){
                res=i;
                return 0;
            }
        }
    return 0;
}

int output(){
    printf("%d\n",res);
    return 0;
}

int main(){
    input();
    solve();
    output();
    return 0;
}
