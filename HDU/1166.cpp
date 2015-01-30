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
#define rson m+1, r, rt << 1 | 1
//freopen("","r",stdin);
//freopen("","w",stdout);
const long long MAXN=(1LL<<62);
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;
const int maxn=50000+5;
int sum[maxn<<2];
int t;
int PushUp(int rt) {
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    return 0;
}

int PushDown(int rt) {
    return 0;
}

int built(int l,int r,int rt) {
    if (l == r) {
        scanf("%d", &sum[rt]);
        return 0;
    }
    int m = (l + r) >> 1;
    built(lson);
    built(rson);
    PushUp(rt);
    return 0;
}

int update(int p,int add,int l,int r,int rt) {
    if (l == r) {
        sum[rt] += add;
        return 0;
    }
    int m = (l + r) >> 1;
    if (p <= m) update(p, add, lson);
    else update(p, add, rson);
    PushUp(rt);
    return 0;
}

int query(int L, int R, int l, int r, int rt) {
    if (L <= l && R >= r) return sum[rt];
    int m = (l + r) >> 1;
    int ans = 0;
    if (L <= m) ans += query(L, R, lson);
    if (R > m) ans += query(L, R, rson);
    return ans;
}

int main(){
    int k,n,i;
    scanf("%d",&t);
    for (k = 1; k <= t; k ++) {
        printf("Case %d:\n",k);
        scanf("%d", &n);
        built(1, n, 1);
       // for (i=1;i<=2*n;i++) printf("%d ",sum[i]);cout<<endl;
        char str[10];
        scanf("%s", str);
        while (str[0] != 'E') {
            int a, b;
            scanf("%d%d",&a, &b);
            if (str[0] == 'Q') printf("%d\n",query(a, b, 1, n, 1));
            if (str[0] == 'A') update(a, b, 1, n, 1);
            if (str[0] == 'S') update(a, -b, 1, n, 1);
            scanf("%s", str);
        }
    }
    return 0;
}
