/*
ID: ck89119
PROG: bigbrn
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
#define fin freopen("bigbrn.in","r",stdin);
#define fout freopen("bigbrn.out","w",stdout);
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

int n;
int grid[1005][1005];
int sum[1005][1005];

int input() {
    int i, t;
    cin >> n >> t;
    for (i = 0; i < t; ++i) {
        int x, y;
        cin >> x >> y;
        grid[x][y] = 1;
    }
    return 0;
}

int solve() {
    int i, j;
    int ans = 0;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            if (!grid[i][j]) {
                sum[i][j] = min(sum[i-1][j-1] ,min(sum[i][j-1], sum[i-1][j])) + 1;
                ans = max(ans, sum[i][j]);
            }
    cout << ans << endl;
    return 0;
}

int main() {
    fin fout
    input();
    solve();
    return 0;
}
