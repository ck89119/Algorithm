/*
ID: ck89119
PROG:
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=50005;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

typedef pair<LL, LL> PLL;
LL p, b, n;
LL x;
//unordered_map<LL, LL> table;
PLL table[MAXN];

LL pow(LL x, LL y, LL mod) {
  if (y == 0) return 1;
  LL t = pow(x, y / 2, mod);
  if (y & 1) return t * t % mod * x % mod;
  else return t * t % mod;
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  #endif
  while (scanf("%lld%lld%lld", &p, &b, &n) != EOF) {
    //table.clear();
    x = (LL)sqrt(p-1) + 1;
    
    LL t = 1;
    table[0] = make_pair(1, 0);
    for (int i = 1; i < x; ++i) {
      t = t * b % p;
      table[i] = make_pair(t, i);
      //if (table.count(t) == 0) table[t] = i;
    }
    sort(table, table + x);   

    LL inv_b = pow(b, p-2, p);
    t = pow(inv_b, x, p);
    
    int flag = 0;
    for (int i = 0; i < x; ++i) {
      PLL *lb = lower_bound(table, table + x, make_pair(n, (LL)-1));
      if (lb->first == n) {
        printf("%lld\n", i * x + lb->second);
        flag = 1; break;
      }
      n = n * t % p;
    }
    if (!flag) printf("no solution\n");
  
  }
  return 0;
}
