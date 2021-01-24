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
const int N = 1000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

class Solution {
 public:
  int add(int a, int b) {
    return (a + b) % MOD;
  }

  int kInversePairs(int n, int k) {
    int f[2][500000];
    clr(f[1], 0); f[1][0] = 1;
    for (int i = 1; i < n; ++i) {
      int cur = i & 1;
      int nxt = cur ^ 1;
      int end = min(k, i*(i-1)/2);
      clr(f[nxt], 0);
      for (int j = 0; j <= end; ++j) {
        f[nxt][j] = add(f[nxt][j], f[cur][j]);
        f[nxt][i+j+1] = add(f[nxt][i+j+1], MOD-f[cur][j]);
      }
      for (int j = 1; j <= end + i + 1; ++j)
        f[nxt][j] = add(f[nxt][j], f[nxt][j-1]);
    }
    return f[n&1][k];
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  // cout << s.kInversePairs(2, 1) << endl;
  for (int i = 1; i < 10; ++i) {
    for (int j = 0; j <= i*(i-1)/2; ++j)
        cout << s.kInversePairs(i, j) << ' ';
    cout << endl;
  }
  cout << s.kInversePairs(1000, 1000) << endl;
  return 0;
}
