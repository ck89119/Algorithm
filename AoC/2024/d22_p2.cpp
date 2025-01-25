#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lowbit(x) x & (-x)
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 2100;
const int M = 130321;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

ll f1(ll x) {
  return ((x << 6) ^ x) & ((1 << 24) - 1);
}

ll f2(ll x) {
  return ((x >> 5) ^ x) & ((1 << 24) - 1);
}

ll f3(ll x) {
  return ((x << 11) ^ x) & ((1 << 24) - 1);
}

ll f(ll x) {
  return f3(f2(f1(x)));
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int sum[M];
  memset(sum, 0, sizeof(sum));

  int p0, p1, p2, p3;
  auto encode = [&]() -> int {
    return (p0 + 9) + (p1 + 9) * 19 + (p2 + 9) * 19 * 19 + (p3 + 9) * 19 * 19 * 19;   
  };

  ll x; 
  while (scanf("%lld", &x) != EOF) {
    int d = x % 10;
    bool vis[M] = {false};

    for (int i = 1; i <= 2000; ++i) {
      x = f(x);
      p3 = p2, p2 = p1, p1 = p0, p0 = x % 10 - d;      
      // dump(p0), dump(p1), dump(p2), dump(p3);
      d = x % 10;
      
      int k = encode();
      if (i >= 4 && !vis[k]) {
        vis[k] = true;
        sum[k] += d;
      }

      // if (i == 4) break;
    }
  }

  int ans = 0;
  for (int i = 0; i < M; ++i) 
    ans = max(ans, sum[i]);

  dump(ans);
  return 0;
}
