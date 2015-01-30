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
#define PB(A) push_back(A)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
//ifstream fin("");
//ofstream fout("");
#define LL long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const LL MOD = 1000000007;

LL D[2005];
LL n, p[2005];
int a[2005], b[2005], fix;

int init() {
    int i;
    D[1] = 0; D[2] = 1;
    for (i = 3; i <= 2000; i++) {
        D[i] = (i-1) * (D[i-1] + D[i-2]);
        D[i] %= MOD;
    }
    return 0;
}

int input() {
    int i;
    CLR(a, 0); CLR(b, 0); fix = 0;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i] != -1) {
            a[i] = 1;
            b[p[i]] = 1;
            fix++;
        }
    }
    return 0;
}

int solve() {
    int n1, unFix;
    int i;
    LL ans;
    n1 = 0;
    for (i = 1; i <= n; i++)
        if (a[i] && b[i]) n1++;
    unFix = n - fix;
    ans = D[unFix];
    ans = (ans + (fix - n1)*D[unFix-1]) % MOD;
    cout << ans << endl;
    return 0;
}


int main() {
    init();
    input();
    solve();
    //out(D, 2000);
    return 0;
}
