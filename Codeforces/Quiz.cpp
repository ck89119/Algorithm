/*
ID: ck89119
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
#define CLR(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
//ifstream fin("");
//ofstream fout("");

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;
const int MOD=1e9+9;

int n, m, k;
long long res;

long long twoPow(int i) {
    long long t;
    if (i == 0) return 1;
    if (i == 1) return 2;
    t = twoPow(i/2);
    if (i%2) return t*t%MOD*2%MOD;
    else return t*t%MOD;
}

int cal(int p) {
    int i;
    res = (twoPow(p+1) + MOD - 2) % MOD;
    res = (res * k) % MOD;
    res += (m-p*k);
    res %= MOD;
    return 0;
}

int solve() {
    int p, q;
    if (n - n/k >= m) res = m;
    else {
        q = n - m;
        p = n/k - q;// dump(p)dump(q)
        cal(p);
    }
    printf("%I64d", res);
    return 0;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    solve();
    return 0;
}
