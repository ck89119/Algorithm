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
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CL(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define two(X) (1<<(X))
#define towL(X) (((int64)(1))<<(x))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
//freopen("","r",stdin);
//freopen("","w",stdout);
const long long MAXN=(1LL<<62);
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;
const int maxn = 5000 + 5;
int n;
int x[maxn];
int sum[maxn<<2];

int PushUp(int rt) {
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    return 0;
}

int built(int l, int r, int rt) {
    sum[rt] = 0;
    if (l == r) return 0;
    int m = (l + r) >> 1;
    built(lson);
    built(rson);
    return 0;
}

int update(int p, int l, int r, int rt) {
    if (l == r) {
        sum[rt] ++;
        return 0;
    }
    int m = (l + r) >> 1;
    if (p <= m) update(p,lson);
    else update(p,rson);
    PushUp(rt);
    return 0;
}

int query(int L, int R, int l, int r, int rt) {
    if (L <= l && R >= r) return sum[rt];
    int ans = 0;
    int m = (l + r) >> 1;
    if (L <= m) ans += query(L, R, lson);
    if (R > m) ans += query(L, R, rson);
    return ans;
}

int main(){
    int i;
    while (scanf("%d", &n) != EOF) {
        int res, sum;
        built(1, n, 1);
        for (i = 1; i <= n; i ++) scanf("%d", &x[i]);
        sum = 0;
        for (i = 1; i <= n; i ++) {
            sum += query(x[i]+1, n, 1, n, 1);
            update(x[i]+1, 1, n, 1);
        }
        res =  sum;
        for (i = 1; i <= n; i ++) {
            sum += n - x[i] -1 - x[i];
            res = min(res,  sum);
        }
        printf("%d\n", res);
    }

    return 0;
}
