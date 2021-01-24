#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
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
const int N = 1000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

typedef pair<pii, pii> post;
int w, h, n;
post p[N];

struct UnionFindSet {
  int f[N];
  int init() {
    for (int i = 0; i < N; ++i) f[i] = i;
    return 0;
  }
  
  int find(int x) {
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
  }

  int union(int )

}



bool inside(pii point, post pp) {
  
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  scanf("%d %d %d", &w, &h, &n);
  for (int i = 0; i < n; ++i) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    post[i] = mp(mp(a, b), mp(c, d));
  }

  

  return 0;
}
