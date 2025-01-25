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
int n,na,nb;
int a[105],b[105];

int main(){
    int t;
    int i;
    scanf("%d",&t);
    while (t--){
        int res;
        scanf("%d%d%d",&n,&na,&nb);
        for (i=0;i<na;i++) scanf("%d",&a[i]);
        for (i=0;i<nb;i++) scanf("%d",&b[i]);
        res=0;
        for(i=0;i<n;i++){
            if (a[i%na]==0&&b[i%nb]==2) res++;
            if (a[i%na]==0&&b[i%nb]==5) res--;
            if (a[i%na]==2&&b[i%nb]==0) res--;
            if (a[i%na]==2&&b[i%nb]==5) res++;
            if (a[i%na]==5&&b[i%nb]==0) res++;
            if (a[i%na]==5&&b[i%nb]==2) res--;
        }
        if (res>0) printf("A\n");
        else if (res<0) printf("B\n");
        else printf("draw\n");
    }
    return 0;
}
