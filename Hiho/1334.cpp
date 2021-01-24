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

int n;
int ans;

int dfs(int dep, const vector<int> &masks, int cnt, int mask) {
  if (dep >= n) {
    ans = max(ans, cnt);
    return 0;
  }
  if (cnt + masks.size() - dep <= ans) return 0;

  dfs(dep+1, masks, cnt, mask);
  for (int i = dep; i < masks.size(); ++i)
    if ((masks[i] & mask) == 0) {
      dfs(i+1, masks, cnt+1, mask | masks[i]);
    }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n;
  vector<int> masks(n, 0);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (auto ch: s)
      masks[i] |= (1 << (ch-'a'));
  }

  ans = 0;
  dfs(0, masks, 0, 0);
  cout << ans << endl;
  return 0;
}
