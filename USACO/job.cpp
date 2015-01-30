/*
ID: ck891191
PROG: job
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
const int MAXN = 1000;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

int cost[2][MAXN+5];
int t[2][30+5];
int delay[30+5];
int n, m1, m2;
int resa, resb;

int input() {
    scanf("%d%d%d", &n, &m1, &m2);
    FR(i, 0, m1) scanf("%d", &t[0][i]);
    FR(i, 0, m2) scanf("%d", &t[1][i]);
    return 0;
}

int cmp(const int &a, const int &b) {
    return a>b;
}

int solve() {
    int mint, k;
    CL(delay, 0);
    FR(i, 0, n) {
        mint = INF; k = -1;
        FR(j, 0, m1)
            if (mint > delay[j] + t[0][j]) {
                k = j;
                mint = delay[j] + t[0][j];
            }
        delay[k] += t[0][k];
        cost[0][i] = delay[k];
        //dump(k)dump(delay[k])
    }
    CL(delay, 0);
    FR(i, 0, n) {
        mint = INF; k = -1;
        FR(j, 0, m2)
            if (mint > delay[j] + t[1][j]) {
                k = j;
                mint = delay[j] + t[1][j];
            }
        delay[k] += t[1][k];
        cost[1][i] = delay[k];
    }
    sort(cost[0], cost[0]+n);
    resa = cost[0][n-1];
    sort(cost[1], cost[1]+n, cmp);
    resb = 0;
    FR(i, 0, n) resb = max(resb, cost[0][i]+cost[1][i]);
    printf("%d %d\n", resa, resb);
    return 0;
}

int main() {
    freopen("job.in","r",stdin);
    freopen("job.out","w",stdout);
    input();
    solve();
    return 0;
}
