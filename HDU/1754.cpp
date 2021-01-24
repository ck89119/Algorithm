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
const int maxn = 200000+5;
int maxS[maxn<<2];
int N, M;

int PushUp(int rt) {
    maxS[rt] = max(maxS[rt<<1], maxS[rt<<1|1]);
    return 0;
}

int built(int l, int r, int rt) {
    if (l == r) {
        scanf("%d", &maxS[rt]);
        return 0;
    }
    int m = (l + r) >> 1;
    built(lson);
    built(rson);
    PushUp(rt);
    return 0;
}

int update(int a, int b, int l, int r, int rt) {
    if (l == r) {
        maxS[rt] = b;
        return 0;
    }
    int m =  (l + r) >> 1;
    if (a <= m) update(a, b, lson);
    if (a > m) update(a, b, rson);
    PushUp(rt);
    return 0;
}

int query(int L, int R, int l, int r, int rt) {
    //dump(L)dump(R)dump(l)dump(r)
    if (L <= l && R >= r) {
        return maxS[rt];
    }
    int ans1, ans2;
    int m = (l + r) >> 1;
    ans1 =  ans2 = 0;
    if (L <= m) ans1 = query(L, R, lson);
    if (R > m) ans2 = query(L, R, rson);
    return max(ans1, ans2);
}

int main(){
    int i;
    while (scanf("%d%d", &N, &M) != EOF) {
        built(1, N, 1);
        char op[5];
        int a, b;
        for (i = 0; i <  M; i ++) {
            scanf("%s%d%d", op, &a, &b);
            //dump(op)dump(a)dump(b)
            if (op[0] == 'Q') printf("%d\n", query(a, b, 1, N, 1));
            if (op[0] == 'U') update(a, b, 1, N, 1);
        }
    }
    return 0;
}
