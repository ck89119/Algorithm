/*
ID: ck89119
PROG: milk4
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
#define fin freopen("milk4.in","r",stdin);
#define fout freopen("milk4.out","w",stdout);
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

int q, p;
int vol[105], use[105];
int ans;
int get_ans;


int input() {
    int i;
    fin fout
    cin >> q >> p;
    for (i = 0; i < p; ++i)
        cin >> vol[i];
    sort(vol, vol+p);
    return 0;
}

int output() {
    int i;
    get_ans = 1;
    cout << ans;
    for (i = 1; i < ans; ++i)
        cout << ' ' << vol[use[i]];
    cout << ' ' << vol[use[ans]] << endl;
    return 0;
}

int check() {
    int f[q+5];
    int i, j;
    CLR(f, 0);
    f[0] = 1;
    for (i = 1; i <= ans; ++i)
        for (j = vol[use[i]]; j <= q; ++j)
            f[j] |= f[j-vol[use[i]]];
    return f[q];
}

int dfs_id(int k, int dep_max) {
    if (k > dep_max) {
        if (check()) output();
        return 0;
    }

    int i;
    for (i = use[k-1]+1; i < p; ++i) {
        use[k] = i;
        dfs_id(k+1, dep_max);
        if (get_ans) break;
    }
    return 0;
}

int solve() {
    get_ans = 0;
    use[0] = -1;
    for (ans = 1; ans <= p; ++ans) {
        dfs_id(1, ans);
        if (get_ans) break;
    }
    return 0;
}

int main() {
    input();
    solve();
    return 0;
}
