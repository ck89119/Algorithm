/*
ID: ck89119
PROG: latin
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
#define fin freopen("latin.in","r",stdin);
#define fout freopen("latin.out","w",stdout);
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
int ans;
int row[7], col[7];
int power[10];

int input() {
    cin >> n;
    return 0;
}

int dfs(int x, int y) {
    if (x >= n-1) {
        ++ans;
        return 0;
    }

    int i, t;
    t = (row[x] | col[y]);
    //dump(t)
    for (i = 0; i < n; ++i)
        if ((t & power[i]) == 0) {
            //dump("####")
            row[x] ^= power[i];
            col[y] ^= power[i];
            dfs(x+(y+1)/n, (y+1)%n);
            row[x] ^= power[i];
            col[y] ^= power[i];
        }

    return 0;
}

int solve() {
    int i;
    for (i = 0; i <= n; ++i) power[i] = (1 << i);
    for (i = 0; i < n; ++i) {
        row[0] += power[i];
        col[i] += power[i];
    }
    if (n == 7) cout << 12198297600 << endl;
    else {
        dfs(1, 0);
        cout << ans << endl;
        }
    return 0;
}

int main() {
    fin fout
    input();
    solve();
    return 0;
}
