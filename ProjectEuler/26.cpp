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

int cyc_len(int n) {
  int pre[1000];
  clr(pre, -1);

  int r = 1;
  pre[r] = 0;
  for (int i = 1; ; ++i) {
    r *= 10;
    r %= n;
    // dump(r);
    if (r == 0) return 0;
    if (pre[r] != -1) return i - pre[r];
    pre[r] = i;
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  // cyc_len(983);
  int max_len, idx;
  max_len = -1;
  for (int i = 2; i < 1000; ++i)
    if (max_len < cyc_len(i)) {
      max_len = cyc_len(i);
      idx = i;
    }
  cout << idx << endl;
  return 0;
}
