#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
typedef long long ll;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100 + 5;
const int M = 20000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int s, n, m;
int a[N][N];
int f[M];
vector<vector<int>> value, cost;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d%d", &s, &n, &m);
  for (int i = 0; i < s; ++i)
    for (int j = 0; j < n; ++j)
      scanf("%d", &a[j][i]);
  for (int i = 0; i < n; ++i) {
    sort(a[i], a[i]+s);
    vector<int> v, c;
    for (int j = 0; j < s && a[i][j] * 2 < m; ++j) {
      v.push_back((i + 1) * (j + 1));
      c.push_back(a[i][j] * 2 + 1);
    }
    value.push_back(v);
    cost.push_back(c);
  }

  memset(f, 0, sizeof(f));
  for (int i = 0; i < n; ++i)
    for (int j = m; j >= 0; --j)
      for (int k = 0; k < value[i].size(); ++k) {
        if (j >= cost[i][k]) f[j] = max(f[j], f[j-cost[i][k]] + value[i][k]);
      }
  printf("%d\n", f[m]);
  return 0;
}