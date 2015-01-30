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

int h, w;
int p;
long long dp[15][2100];
int res;

int check(int pre, int cur) {
    int i, f1, f2;
    for (i = 0; i < h; i++) {
        f1 = pre & (1<<i);
        f2 = cur & (1<<i);
        if (!f1 && !f2) return 0;
        if (f1 && f2) {
            i++;
            if (i >= h) return 0;
            if ((pre & (1<<i)) == 0) return 0;
            if ((cur & (1<<i)) == 0) return 0;
        }
    }
    return 1;
}

int solve() {
    int i, j, k;
    int biggest = (1<<h) - 1;
    if ((h*w) & 1) {
        cout << 0 << endl;
        return 0;
    }

    CL(dp, 0);
    dp[0][biggest] = 1;

    for (i = 0; i < w; i++)
        for (j = 0; j <= biggest; j++)
            if (dp[i][j]){
                for (k = 0; k <= biggest; k++)
                    if (check(j, k)) dp[i+1][k] += dp[i][j];
            }

    cout << dp[w][biggest] << endl;
    return 0;
}

int main() {
    while (cin >> h >> w, h+w) {
        solve();
    }
    return 0;
}
