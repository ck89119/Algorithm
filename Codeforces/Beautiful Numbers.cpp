/*
ID: ck891191
PROG:
LANG: C++
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CL(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
//freopen("","r",stdin);
//freopen("","w",stdout);
//ifstream fin("");
//ofstream fout("");
const int MAXN = 9999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;
const int MOD = 1000000007;

int a,b,n;
long long nCr[1000005];
long long ans;


//int ext_gcd(int a, int b, int &d, int &x, int &y) {
//    if (!b) {d=a;x=1;y=0;}
//    else {
//       ext_gcd(b,a%b,d,y,x);
//        y-=x*(a/b);
//    }
//    return 0;
//}

int ext_gcd(int a, int b, int &d, int &x, int &y) {
    if (b==0) {
        d=a;
        x=1;y=0;
    }
    else {
        ext_gcd(b,a%b,d,x,y);
        int tmp;
        tmp=x;
        x=y;
        y=tmp-(a/b)*y;
    }
    return 0;
}

int inv(int m) {
    int d,x,y;
    ext_gcd(m,MOD,d,x,y);
    if (x<0) x+=MOD;
    return x;
}

int init() {
    int i;
    nCr[0]=1;
    for (i=1;i<=n;i++) {
        nCr[i]=nCr[i-1]*(n-i+1)%MOD;
        nCr[i]=nCr[i]*inv(i)%MOD;
    }
    //for (i=0;i<=n;i++) cout<<nCr[i]<<' ';cout<<endl;
    return 0;
}

int check(int m) {
    while (m) {
        if (m%10!=a&&m%10!=b) return 0;
        m/=10;
    }
    return 1;
}

int main() {
    int i;
    scanf("%d%d%d", &a,&b,&n);
    init();//dump("###")
    ans=0;
    for (i=0;i<=n;i++) {
        int m=a*(n-i)+b*i;
        if (check(m)) ans=(ans+nCr[i])%MOD;
    }
    printf("%I64d\n",ans);
    return 0;
}
