#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

// int n;
// int a[N];
// int f[N], pre[N];

// int output(int idx) {
//   if (idx == -1) return 0;
//   output(pre[idx]);
//   printf("%d\n", a[idx]);
//   return 0;
// }

// int dp() {
//   int idx = 0;
//   clr(pre, -1);
//   for (int i = 0; i < n; ++i) {
//     f[i] = 1;
//     for (int j = 0; j < i; ++j)
//       if (a[i] > a[j] && f[i] <= f[j] + 1) {
//         f[i] = f[j] + 1;
//         pre[i] = j;
//       }
//     if (f[i] >= f[idx]) idx = i;
//   }
//   printf("%d\n-\n", f[idx]); 
//   output(idx); 
//   return 0;
// }

vector<int> a;

int dp() {
  vector<pii> b;
  vector<int> pre;
  for (int i = 0; i < a.size(); ++i) {
    auto x = make_pair(a[i], -i);
    auto it = lower_bound(b.begin(), b.end(), x);
    if (it == b.begin()) pre.push_back(-1);
    else pre.push_back(-(*(it-1)).second);
    if (it == b.end()) b.push_back(x);
    else *it = x;
  }
  
  int idx = -b[b.size()-1].second;
  vector<int> ans; 
  while (idx != -1) {
    ans.push_back(a[idx]);
    idx = pre[idx];
  }
  printf("%d\n-\n", b.size());
  for (int i = ans.size() - 1; i >= 0; --i)
    printf("%d\n", ans[i]);
  return 0;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int tmp;
  for (int n = 0; scanf("%d", &tmp) != EOF; ++n) {
    a.push_back(tmp);
  }
  dp();
  return 0;
}
