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
const int N = 340000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

// int count_one(ll n) {
//   int cnt = 0;
//   while (n) {
//     n = lowbit(n);
//     ++cnt;
//   }
//   return cnt;
// }

// map<int, set<int>> get(int l, int n) {
//   map<int, set<int>> ans;
//   for (ll status = 0; status < (1LL << n); ++status) {
//     int sum = 0;
//     for (int k = 0; k < n; ++k)
//       if ((status >> k) & 1) sum += (l + k) * (l + k);
//     ans[count_one(status)].insert(sum);
//   }
//   return ans;
// }

// map<int, set<int>> merge(map<int, set<int>> &m1, map<int, set<int>> &m2) {
//   map<int, set<int>> ans;
//   for (auto p1: m1)
//     for (auto p2: m2) {
//       int s = p1.first + p2.first;
//       for (auto x: p1.second)
//         for (auto y: p2.second)
//           ans[s].insert(x+y);
//     }
//   return ans;
// } 

// map<int, set<int>> solve2(int l, int r) {
//   dump(l), dump(r);
//   int m = (l + r) >> 1;
//   int n1 = m - l;
//   int n2 = r - m + 1;
//   auto s1 = get(l, n1);
//   dump("s1 complete");
//   auto s2 = get(m, n2);
//   dump("s2 complete");

//   return merge(s1, s2);
// }

// map<int, set<int>> solve(int l, int r) {
//   int m = (l + r) >> 1;
//   auto s1 = solve2(l, m);
//   auto s2 = solve2(m+1, r);
//   return merge(s1, s2);
// }

int f[N][51];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  clr(f, 0);
  f[0][0] = 1;
  for (int i = 1; i <= 100; ++i)
    for (int j = N-1; j >= i*i; --j)
      for (int k = 0; k < 50; ++k)
        f[j][k+1] += f[j-i*i][k];
  ll sum = 0;
  for (int i = 0; i < N; ++i)
    if (f[i][50] == 1) sum += i;
  printf("%lld\n", sum);
  return 0;
}
