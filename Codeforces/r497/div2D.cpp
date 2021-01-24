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
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int t;
int a, b, c;

set<int> f(int n) {
  set<int> ans;
  int i;
  for (i = 1; i * i <= n; ++i) 
    if (n % i == 0) {
      ans.insert(i);
      ans.insert(n / i);
    }
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &a, &b, &c);
    set<int> sa = f(a);
    set<int> sb = f(b);
    set<int> sc = f(c);
    
    ll ans = 1LL * sa.size() * sb.size() * sc.size();
    int cnt = 0;
    for (auto x: sa) {
      if (sb.count(x)) ++cnt; 
    }
    ans -= sc.size() * cnt * (cnt - 1) / 2;
    dump(cnt);

    cnt = 0;
    for (auto x: sb) {
      if (sc.count(x)) ++cnt; 
    }
    ans -= sa.size() * cnt * (cnt - 1) / 2;

    cnt = 0;
    for (auto x: sa) {
      if (sc.count(x)) ++cnt; 
    }
    ans -= sb.size() * cnt * (cnt - 1) / 2;
    
    cnt = 0;
    for (auto x: sa) {
      if (sb.count(x) && sc.count(x)) ++cnt; 
    }
    ans += 2 * cnt * (cnt - 1) / 2;
    dump(cnt);

    // printf("%I64d\n", ans);
    printf("%lld\n", ans);
  }
  return 0;
}
