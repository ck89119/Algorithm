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

bool v[10];
int get_v(int n) {
  for (int i = 0; i < 10; ++i) {
    if (v[i] == false) continue;
    if (n == 0) return i;
    --n;
  }
  return 0;
}

int fac(int n) {
  int ans = 1;
  for (int i = 1; i <= n; ++i)
    ans *= i;
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int left;
  int ans[10];
  
  while (cin >> left) {
    for (int i = 0; i < 10; ++i) v[i] = true;
    for (int i = 9; i >= 0; --i) {
      dump(i);
      int base = fac(i);
      int idx = left / base;
      ans[i] = get_v(idx);
      v[ans[i]] = false;
      dump(base), dump(idx), dump(ans[i]);
      left %= base;
    }
    cout << left << endl;
    for (int i = 9; i >= 0; --i) cout << ans[i];
    cout << endl;
  }

  return 0;
}
