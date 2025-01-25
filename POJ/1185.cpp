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

int dp[65][65][105];
int g[105];
int n, m;
int state[65], cnt[65], state_size;

int input() {
    int i, j;
    char ch;
    cin >> n >> m;
    CL(g, 0);
    for (i = 1; i <= n; i++) {
        getchar();
        for (j = 0; j < m; j++) {
            cin >> ch;
            if (ch == 'H') g[i] |= (1<<j);
        }
    }
}

int dfs(int cur, int tCnt, int tState) {
    int i;
    state[state_size] = tState;
    cnt[state_size] = tCnt;
    state_size++;

    if (cur >= m-3) return 0;

    for (i = cur+3; i < m; i++)
        dfs(i, tCnt+1, tState|(1<<i));
    return 0;
}

int solve() {
    int i, j, k, tn;
    int res;
    state_size = 0;
    dfs(-3, 0, 0);
//    dump(state_size)
//    for (i = 0; i < state_size; i++) cout<<state[i]<<' ';cout<<endl;
//    for (i = 0; i < state_size; i++) cout<<cnt[i]<<' ';cout<<endl;
    CL(dp, 0);
    for (tn = 1; tn <= n; tn++)
        for (i = 0; i < state_size; i++) {
            if (g[tn] & state[i]) continue;
            for (j = 0; j < state_size; j++){
                if (state[i] & state[j]) continue;
                for (k = 0; k < state_size; k++) {
                    if (state[k] & state[i] || state[k] & state[j]) continue;
                    dp[i][j][tn] = max(dp[i][j][tn], dp[j][k][tn-1]+cnt[i]);
                }
//                dump(tn)dump(i)dump(j)
//                dump(dp[i][j][tn])
            }
        }

    res = 0;
    for (i = 0; i < state_size; i++)
        for (j = 0; j < state_size; j++)
            res = max(res, dp[i][j][n]);
    cout<<res<<endl;
    return 0;
}

int main(){
    input();
    solve();
    return 0;
}
