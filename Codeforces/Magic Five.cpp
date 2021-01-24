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
const int MAXN=99999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;
const long long MOD = 1000000007;

long long two[100005];
string a;
long long k,n;
long long inv,sum;

long long gcd(long long a,long long b,long long &d,long long &x,long long &y)
{
    if (b==0){ d=a; x=1; y=0; return 0;}
    gcd(b,a%b,d,y,x);
    y-= x*(a/b);
    return 0;
}

long long pow(long long a,long long n){
    long long b;
    if (n==1) return a%MOD;
    else{
        b=pow(a,n/2);
        if (n%2) return (b*b)%MOD*a%MOD;
        else return (b*b)%MOD;
    }
}

int init() {
    long long i;
    long long tmp,d,y;
    cin>>a>>k;
    n=a.size();
    two[0]=1;
    for (i=1;i<=100001;i++)
        two[i]=(two[i-1]<<1)%MOD;
    tmp=(two[n]-1)%MOD;
    //dump(two[10000]);
    gcd(tmp,MOD,d,inv,y);
    inv = (inv+MOD)%MOD;
    return 0;
}

int solve() {
    long long i;
    sum=0;
    for (i=0;i<n;i++)
        if (a[i]=='0'||a[i]=='5') {
            sum = (sum+two[i])%MOD;
        }
    long long tmp;
    tmp=inv;
    tmp=tmp*((pow(two[n],k)-1)%MOD)%MOD;
    sum = (sum * tmp) % MOD;
    printf("%I64d\n",sum%MOD);
    return 0;
}


int main(){
    init();
    solve();
    return 0;
}
