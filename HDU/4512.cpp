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

int n;
int h[100005],hrev[100005];
int f[100005];

int LCIS(){
    int i,j,k;
    int m;
    int res;
    memset(f,0,sizeof(f));
    for (i=0;i<n;i++){
        m=0;
        for (j=0;j<n;j++){
            if (h[i]>hrev[j]) m=max(m,f[j]);
            if (h[i]==hrev[j]) f[j]=max(m+1,f[j]);
        }
    }
    //for (i=0;i<n/2;i++) cout<<f[i]<<' ';cout<<endl;
    m=0;k=-1;
    for (i=0;i<n/2;i++)
        if (f[i]>m) {m=f[i];k=i;}
    res=m+m;

    for (i=0;i<n/2;i++)
        if (h[i]==hrev[k]) break;
    if (k+1<=n-1-i) res++;
//    for (j=k+1;j<n-1-i;j++)
//        if (hrev[j]>hrev[k]) {res++;break;}
    return res;
}

int main(){
    int i,t;
    scanf("%d",&t);
    while (t--){
        scanf("%d",&n);
        for (i=0;i<n;i++){
            scanf("%d",&h[i]);
            hrev[n-1-i]=h[i];
        }
        printf("%d\n",LCIS());
    }
    return 0;
}
