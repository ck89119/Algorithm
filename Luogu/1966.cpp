#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e8 - 3;

int n, a[N], b[N];

int merge(int l, int r) {
  if (l >= r) return 0;

  int ans = 0;
  int m = (l + r) >> 1;
  ans = (ans + merge(l, m)) % MOD;
  ans = (ans + merge(m+1, r)) % MOD;
  for (int i = l, j = m+1; i <= m; ++i) {
    while (j <= r && b[j] < b[i]) ++j;
    ans = (ans + (j - m - 1)) % MOD;
  }

  int i = l, j = m+1;
  int idx = l;
  while (i <= m && j <= r) a[idx++] = b[i] < b[j] ? b[i++] : b[j++];
  while (i <= m) a[idx++] = b[i++];
  while (j <= r) a[idx++] = b[j++];
  for (int i = l; i <= r; ++i) b[i] = a[i];

  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  vector<pii> va, vb;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    va.emplace_back(x, i);
  }
  sort(va.begin(), va.end());
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    vb.emplace_back(x, i);
  }
  sort(vb.begin(), vb.end());
  for (int i = 0; i < n; ++i) b[va[i].second] = vb[i].second;
  printf("%d\n", merge(0, n-1));
  return 0;
}