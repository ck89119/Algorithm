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
const long long MOD=1000000007;

int n,k;
long long  power(int x, int a){
    long long tmp;
    if (a==0) return 1;
    if (a==1) return x;
    tmp=power(x,a/2);
    if (a%2) return (tmp*tmp)%MOD*x%MOD;
    else return (tmp*tmp)%MOD;
}

int main(){
    long long res;
    int t;
    scanf("%d%d",&n,&k);
    res=power(k,k-1);
    //dump(res)
    //t=power(n-k,n-k);dump(t)
    res=res%MOD*power(n-k,n-k)%MOD;
    printf("%I64d\n",res);
    return 0;
}
