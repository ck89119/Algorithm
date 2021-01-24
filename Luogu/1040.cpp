#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
typedef long long ll;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 30 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, a[N];
pair<long long, vector<int>> f[N][N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  // memset(f, 0, sizeof(f));
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j)
      f[i][j] = make_pair(1, vector<int>());
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    f[i][i] = make_pair(a[i], vector<int>(1, i));
  }

  for (int l = 2; l <= n; ++l)
    for (int i = 1; i + l - 1 <= n; ++i) {
      int j = i + l - 1;
      for (int k = i; k <= j; ++k) {
        auto [l_val, l_tra] = f[i][k-1];
        auto [r_val, r_tra] = f[k+1][j];
        // dump(k); dump(f[i][j].first); dump(l_val * r_val + a[k]);
        if (f[i][j].first < l_val * r_val + a[k]) {
          vector<int> v(1, k);
          v.insert(v.end(), l_tra.begin(), l_tra.end());
          v.insert(v.end(), r_tra.begin(), r_tra.end());
          f[i][j] = make_pair(l_val * r_val + a[k], v);
        }
      }
      // cout << i << " " << j << endl;
      // out(f[i][j].second);
      // cout << "\n"; 
    }
  printf("%lld\n", f[1][n].first);
  for (auto x: f[1][n].second)
    printf("%d ", x);
  printf("\n");
  return 0;
}