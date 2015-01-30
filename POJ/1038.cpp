/*
//ID: ck891191
//PROG:
//LANG: C++
//*/
//#include <vector>
//#include <list>
//#include <map>
//#include <set>
//#include <deque>
//#include <queue>
//#include <stack>
//#include <string>
//#include <bitset>
//#include <algorithm>
//#include <functional>
//#include <numeric>
//#include <utility>
//#include <sstream>
//#include <fstream>
//#include <iostream>
//#include <iomanip>
//#include <cstdio>
//#include <cmath>
//#include <cstring>
//#include <cstdlib>
//using namespace std;
//#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
//#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
//#define CL(a,x) memset(a,x,sizeof(a))
//#define MP(A,B) make_pair(A,B)
//#define lson l, m, rt << 1
//#define rson m + 1, r, rt << 1 | 1
////freopen("","r",stdin);
////freopen("","w",stdout);
////ifstream fin("");
////ofstream fout("");
//const int MAXN = 9999;
//const int INF=(1<<30);
//const double PI=acos(-1.0);
//const double EPS=1e-11;
//
//int D, N, M, K;
//int g[155][15];
//int f[2][60000];
//int stateA[15], stateB[15];
//int pow3[11] = {1,3,9,27,81,243,729,2187,6561,19683,59049};
//
//int input() {
//    int i;
//    CL(g, 0);
//    cin >> N >> M >> K;
//    for (i = 0; i < K; i++) {
//        int x, y;
//        cin >> x >> y;
//        g[x][y] = 1;
//    }
//    return 0;
//}
//
//int getState(int state[]) {
//    int i, res;
//    res = 0;
//    for (i = 1; i <= M; i++)
//        res = res + state[i] * pow3[i-1];
//    return res;
//}
//
//int setState(int state[], int s) {
//    int i;
//    for (i = 1; i <= M; i++){
//        state[i] = s % 3;
//        s /= 3;
//    }
//    return 0;
//}
//
//int dfs(int m, int n, int cnt) {
//    int i, tb, ta;
//    if (m >= M) return 0;
//
//    if (m <= M-2 && !stateB[m] && !stateB[m+1] && !stateB[m+2]) {
//        stateB[m] = stateB[m+1] = stateB[m+2] = 2;
//        tb = getState(stateB);
//        ta = getState(stateA);
//        f[n&1][tb] = max(f[n&1][tb], f[(n+1)&1][ta]+cnt+1);
//        dfs(m+3, n, cnt+1);
//        stateB[m] = stateB[m+1] = stateB[m+2] = 0;
//    }
//
//    if (m <= M-1 && !stateA[m] && !stateA[m+1] && !stateB[m] && !stateB[m+1]) {
//        stateB[m] = stateB[m+1] = 2;
//        tb = getState(stateB);
//        ta = getState(stateA);
//        f[n&1][tb] = max(f[n&1][tb], f[(n+1)&1][ta]+cnt+1);
//        dfs(m+2, n, cnt+1);
//        stateB[m] = stateB[m+1] = 0;
//    }
//
//    tb = getState(stateB);
//    ta = getState(stateA);
//    f[n&1][tb] = max(f[n&1][tb], f[(n+1)&1][ta]+cnt);
//    dfs(m+1, n, cnt);
//    return 0;
//}
//
//int solve() {
//    int i, j, k;
//    int res;
//    CL(f, -1);
//    CL(stateA, 0);
//    for (i = 1; i <= M; i++)
//        stateA[i] = g[1][i] + 1;
//    f[1][getState(stateA)] = 0;
//
////    dump(getState((stateA)))
////    for (i = 0 ; i <= pow3[M]-1; i++) cout<<f[1][i]<<' ';cout<<endl;
//
//    for (i = 2; i <= N; i++) {
//        CL(f[i&1], -1);
//        for (j = 0; j <= pow3[M]-1; j++)
//            if (f[(i+1)&1][j] != -1) {
//                //dump(i)dump(j)
//                CL(stateB, 0);
//                setState(stateA, j);
//                //for (k = 1; k <= M; k++) cout<<stateA[k]<<' ';cout<<endl;
//                for (k = 1; k <= M; k++)
//                    if (g[i][k]) stateB[k] = 2;
//                    else if (stateA[k] == 2) stateB[k] = 1;
//                //for (k = 1; k <= M; k++) cout<<stateB[k]<<' ';cout<<endl;
//                dfs(1, i, 0);
//            }
//        //for (j = 0; j <= pow3[M]-1; j++) cout<<f[i&1][j]<<' ';cout<<endl;
//    }
//
//    res = 0;
//    for (i = 0; i <= pow3[M]-1; i++)
//        res = max(res, f[N&1][i]);
//    cout << res << endl;
//    return 0;
//}
//
//int main() {
////    freopen("in.txt","r",stdin);
////    freopen("out.txt","w",stdout);
//    cin >> D;
//    while (D--) {
//        input();
//        solve();
//    }
//    return 0;
//}


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
#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
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

int D, N, M, K;
int dp[2][60000];
int pow3[11] = {1,3,9,27,81,243,729,2187,6561,19683,59049};
int grid[155][15];
int p[15], q[15];

int input() {
    int i;
    cin >> N >> M >> K;
    CL(grid, 0);
    for (i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        grid[x][y] = 1;
    }
    return 0;
}

int dfs(int x, int y, int s, int cnt) {
    int i, j;
    if (y >= M) return 0;
    if (y <= M-2 && q[y] == 0 && q[y+1] == 0 && p[y] == 0 && p[y+1] == 0) {
        int t = s + 2 * pow3[y] + 2 * pow3[y+1];
        dp[x&1][t] = max(dp[x&1][t], cnt+1);
        dfs(x, y+2, t, cnt+1);
    }
    if (y <= M-3 && q[y] == 0 && q[y+1] == 0 && q[y+2] == 0) {
        int t = s + 2 * pow3[y] + 2 * pow3[y+1] + 2 * pow3[y+2];
        dp[x&1][t] = max(dp[x&1][t], cnt+1);
        dfs(x, y+3, t, cnt+1);
    }
    dp[x&1][s] = max(dp[x&1][s], cnt);
    dfs(x, y+1, s, cnt);
    return 0;
}

int solve() {
    int i, j, s;
    int res;
    CL(dp, -1);
    for (i = 0, s = 0; i < M; i++)
        if (grid[1][i+1]) s += 2 * pow3[i];
        else s += pow3[i];
    dp[1&1][s] = 0;

    for (i = 2; i <= N; i++){
        CL(dp[i&1], -1);

        for (j = 0; j <= pow3[M]-1; j++)
            if (dp[(i-1)&1][j] != -1){

                int cnt = dp[(i-1)&1][j];
                int tmp, k;

                tmp = j;
                for (k = 0; k <= M-1; k++) {
                    p[k] = tmp % 3;
                    tmp /= 3;
                }

                s = 0;
                for (k = 0; k < M; k++)
                    if (grid[i][k+1]) {q[k] = 2; s += 2 * pow3[k];}
                    else if (p[k] == 2) {q[k] = 1; s += pow3[k];}
                    else q[k] = 0;
                //dp[i&1][s] = cnt;

                dfs(i, 0, s, cnt);
            }
    }
    res = 0;
    for (i = 0; i <= pow3[M]-1; i++)
        res = max(res, dp[N&1][i]);
    cout << res << endl;
    return 0;
}


int main() {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin >> D;
    while (D--) {
        input();
        solve();
    }
    return 0;
}
