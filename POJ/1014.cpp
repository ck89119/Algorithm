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
#define two(X) (1<<(X))
#define towL(X) (((int64)(1))<<(x))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define FOR(i,n) FR(i,0,n)//[0,n)
#define RF(i,a,b) for(int i=(a)-1;i>=(b);--i)//(a,b]
#define ROF(i,n) RF(i,n,0)//[0,n)
#define CL(a,x) memset(a,x,sizeof(a))

const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

int n[10];
int v;
int f[60005];

int ZeroOnePack(int cost){
    int k;
    for (k=v/2;k>=cost;k--)
        if (!f[k]&&f[k-cost]) f[k]=1;
    return 0;
}

int CompletePack(int cost){
    int k;
    for (k=cost;k<=v/2;k++)
        if (!f[k]&&f[k-cost]) f[k]=1;
    return 0;
}

int MultiplePack(int cost, int amount){
    int k;
    if (cost*amount>=v/2) CompletePack(cost);
    else{
        k=1;
        while (k<amount){
            ZeroOnePack(k*cost);
            amount-=k;
            k*=2;
        }
        ZeroOnePack(amount*cost);
    }
    if (f[v/2]) return 1;
    else return 0;
}

int main(){
    int c;
    c=0;
    while (1){
        int i,j,k,t;
        int left;
        c++;v=0;
        for (i=1;i<=6;i++) {scanf("%d",&n[i]);v+=i*n[i];}
        if (v==0) break;
        if (v%2){
            printf("Collection #%d:\n",c);
            printf("Can't be divided.\n\n");
            continue;
        }
        memset(f,0,sizeof(f));
        f[0]=1;
        for (i=6;i>=1;i--)
            if (MultiplePack(i,n[i])) break;
        if (f[v/2]){
            printf("Collection #%d:\n",c);
            printf("Can be divided.\n\n");
        }
        else{
            printf("Collection #%d:\n",c);
            printf("Can't be divided.\n\n");
        }

//        left=v/2;
//        while (left>0){
//            int update=0;
//            for (i=6;i>0;i--)
//                while (n[i]&&left>=i){
//                    left-=i;
//                    n[i]--;
//                    update=1;
//                }
//            if (!update) break;
//        }
//        if (left==0){
//            printf("Collection #%d:\n",c);
//            printf("Can be divided.\n");
//        }
//        else{
//            printf("Collection #%d:\n",c);
//            printf("Can't be divided.\n");
//        }

    }
    return 0;
}
