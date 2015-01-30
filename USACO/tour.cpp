/*
ID: ck89119
PROG: tour
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
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen("tour.in","r",stdin);
#define fout freopen("tour.out","w",stdout);
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

int n, m;
string city[105];
int adj[105][105];
int f[105][105];

int find(string &s) {
    int i;
    for (i = 1; i <= n; ++i)
        if (s == city[i]) break;
    return i;
}

int input() {
    int i;
    string a, b;
    int u, v;
    cin >> n >> m;
    for (i = 1; i <= n; ++i)
        cin >> city[i];
    CLR(adj, 0);
    for (i = 0; i < m; ++i) {
        cin >> a >> b;
        u = find(a);
        v = find(b);
        adj[u][v] = adj[v][u] = 1;
    }
    return 0;
}

int solve() {
    int i, j, k;
    CLR(f, 0x80); f[1][1] = 1;
    for (i = 1; i <= n; ++i)
        for (j = i+1; j <= n; ++j) {
            //f[i][j] = -INF;
            for (k = 1; k < j; ++k)
                if (adj[k][j] && f[i][k] > 0)
                    f[i][j] = max(f[i][j], f[i][k]);
            f[i][j]++;
            f[j][i] = f[i][j];
        }

    int ans = 1;
    for (i = 1; i < n; ++i)
        if (adj[i][n]) ans = max(ans, f[i][n]);
    cout << ans << endl;
    return 0;
}

int main() {
    fin fout
    input();
    solve();
    return 0;
}
