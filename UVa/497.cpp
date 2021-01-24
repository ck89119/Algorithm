#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
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
const int N = 1000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

vector<int> a;
int f[N], pre[N];

// vector<int> lis(vector<int> &a) {
//   vector<int> b;
//   for (auto c: a) {
//     auto it = lower_bound(b.begin(), b.end(), c);
//     if (it == b.end()) b.push_back(c);
//     else *it = c; 
//   }
//   return b;
// }

vector<int> lis(vector<int> &a) {
  int max_len = 0, max_idx = -1;
  for (int i = 0; i < a.size(); ++i) {
    f[i] = 1; pre[i] = -1;
    for (int j = 0; j < i; ++j)
      if (a[i] > a[j] && f[i] < f[j] + 1) {
        f[i] = f[j] + 1;
        pre[i] = j;
      }
    if (f[i] > max_len) {
      max_len = f[i];
      max_idx = i;
    }
  }

  vector<int> b;
  while (max_idx != -1) {
    b.push_back(a[max_idx]);
    max_idx = pre[max_idx];
  }
  return b; 
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  char str[20];
  scanf("%d", &t); getchar(); getchar();
  while (t--) {
    while (gets(str) != NULL && strcmp(str, "\0") != 0) {
      int tmp;
      sscanf(str, "%d", &tmp);
      a.push_back(tmp);
    }
    vector<int> b = lis(a);
    printf("Max hits: %d\n", b.size());
    for (int i = b.size() - 1; i >= 0; --i)
      printf("%d\n", b[i]);
    if (t) printf("\n");
    a.clear();
  }
  return 0;
}
