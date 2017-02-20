// [>
// ID: ck891191
// PROG:
// LANG: C++
// */
// #include <vector>
// #include <list>
// #include <map>
// #include <set>
// #include <deque>
// #include <queue>
// #include <stack>
// #include <string>
// #include <bitset>
// #include <algorithm>
// #include <functional>
// #include <numeric>
// #include <utility>
// #include <sstream>
// #include <fstream>
// #include <iostream>
// #include <iomanip>
// #include <cstdio>
// #include <cstring>
// #include <cmath>
// #include <cstdlib>
// using namespace std;
// #define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
// #define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
// #define CL(a,x) memset(a,x,sizeof(a))
// #define MP(A,B) make_pair(A,B)
// #define two(X) (1<<(X))
// #define towL(X) (((int64)(1))<<(x))
// #define contain(S,X) ((S&two(X))>0)
// #define containL(S,X) ((S&twoL(X))>0)
// #define lson l, m, rt << 1
// #define rson m+1, r, rt << 1 | 1
// //freopen("","r",stdin);
// //freopen("","w",stdout);
// const long long MAXN=(1LL<<62);
// const int INF=(1<<30);
// const double PI=acos(-1.0);
// const double EPS=1e-11;
// const int maxn=50000+5;
// int sum[maxn<<2];
// int t;
// int PushUp(int rt) {
//     sum[rt] = sum[rt<<1] + sum[rt<<1|1];
//     return 0;
// }
// 
// int PushDown(int rt) {
//     return 0;
// }
// 
// int built(int l,int r,int rt) {
//     if (l == r) {
//         scanf("%d", &sum[rt]);
//         return 0;
//     }
//     int m = (l + r) >> 1;
//     built(lson);
//     built(rson);
//     PushUp(rt);
//     return 0;
// }
// 
// int update(int p,int add,int l,int r,int rt) {
//     if (l == r) {
//         sum[rt] += add;
//         return 0;
//     }
//     int m = (l + r) >> 1;
//     if (p <= m) update(p, add, lson);
//     else update(p, add, rson);
//     PushUp(rt);
//     return 0;
// }
// 
// int query(int L, int R, int l, int r, int rt) {
//     if (L <= l && R >= r) return sum[rt];
//     int m = (l + r) >> 1;
//     int ans = 0;
//     if (L <= m) ans += query(L, R, lson);
//     if (R > m) ans += query(L, R, rson);
//     return ans;
// }

// int main(){
//     int k,n,i;
//     scanf("%d",&t);
//     for (k = 1; k <= t; k ++) {
//         printf("Case %d:\n",k);
//         scanf("%d", &n);
//         built(1, n, 1);
//        // for (i=1;i<=2*n;i++) printf("%d ",sum[i]);cout<<endl;
//         char str[10];
//         scanf("%s", str);
//         while (str[0] != 'E') {
//             int a, b;
//             scanf("%d%d",&a, &b);
//             if (str[0] == 'Q') printf("%d\n",query(a, b, 1, n, 1));
//             if (str[0] == 'A') update(a, b, 1, n, 1);
//             if (str[0] == 'S') update(a, -b, 1, n, 1);
//             scanf("%s", str);
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 50000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
int t[2*N];

int build(int p) {
  for (p >>= 1; p > 0; p >>= 1) t[p] = t[p<<1] + t[p<<1|1];
  return 0;
}

int modify(int i, int delta) {
  t[i += n] += delta;
  build(i);
  return 0;
}

int query(int l, int r) {
  int ans = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ans += t[l++];
    if (r & 1) ans += t[--r];
  }
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    printf("Case %d:\n", ncase);
    clr(t, 0);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      int tmp;
      scanf("%d", &tmp);
      modify(i, tmp);
    }
    
    char op[10];
    while (scanf("%s", op), strcmp(op, "End")) {
      if (strcmp(op, "Query") == 0) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", query(l-1, r));
      } else if (strcmp(op, "Add") == 0) {
        int i, v;
        scanf("%d%d", &i, &v);
        modify(i-1, v);
      } else if (strcmp(op, "Sub") == 0) {
        int i, v;
        scanf("%d%d", &i, &v);
        modify(i-1, -v);
      }
    }
  }
  return 0;
}
