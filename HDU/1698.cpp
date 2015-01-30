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
const long long MAXN=(1LL<<62);
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;
const int maxn = 100000 + 5;
int sum[maxn<<2];
int mark[maxn<<2];
int n,q;

int PushUp(int rt) {
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    return 0;
}

int PushDown(int rt, int len) {
    if (mark[rt]) {
        mark[rt<<1] = mark[rt];
        mark[rt<<1|1] = mark[rt];
        sum[rt<<1] = mark[rt] * (len - (len>>1));
        sum[rt<<1|1] = mark[rt] * (len>>1);
        mark[rt] = 0;
    }
    return 0;
}

int build(int l, int r, int rt) {
    sum[rt] = 1;
    mark[rt] = 0;
    if (l == r) return 0;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);
    return 0;
}

int update(int L, int R, int c, int l, int r, int rt) {
    if (L <= l && R >= r) {
        mark[rt] = c;
        sum[rt] = c * (r - l + 1);
        return 0;
    }
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, c, lson);
    if (R > m) update(L, R, c, rson);
    PushUp(rt);
    return 0;
}

int query(int L, int R, int l, int r, int rt) {
    if (L <= l && R >= r) return sum[rt];
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    int res = 0;
    if (L <= m) res += query(L, R, lson);
    if (R > m) res += query(L, R, rson);
    return res;
}

int main() {
    int k,i;
    int t;
    scanf("%d", &t);
    for (k = 0; k < t; k ++) {
        int x, y, z;
        scanf("%d%d", &n, &q);
        build(1, n, 1);
        for (i = 0; i < q; i ++) {
            scanf("%d%d%d", &x, &y, &z);
            update(x, y, z, 1, n, 1);
            //dump("%%%%%%%%%")
        }
        printf("Case %d: The total value of the hook is %d.\n", k + 1, query(1, n, 1, n, 1));
    }
    return 0;
}
