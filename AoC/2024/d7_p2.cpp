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

bool check(const vector<int> &b, int idx, ll ret, ll exp) {
  if (idx == b.size()) return ret == exp;
  if (check(b, idx + 1, ret + b[idx], exp)) return true;
  if (check(b, idx + 1, ret * b[idx], exp)) return true;
  
  ll base = 10;
  while (base <= b[idx]) base *= 10;
  if (check(b, idx + 1, ret * base + b[idx], exp)) return true;

  return false;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  ll ans = 0;
  string line;
  while (getline(cin, line)) {
    istringstream is(line);
    ll a, b;
    char ch;
    vector<int> v;
    is >> a >> ch;
    while (is >> b) {
      // cout << b << endl;
      v.push_back(b);
    }

    // dump(a); out(v);
    if (check(v, 1, v[0], a)) ans += a;
  }
  cout << ans << endl;
  return 0;
}
