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
const int N = 500 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

const char face[6][7] = {"front", "back", "left", "right", "top", "bottom"};
int cubes[N][6], n;

int lis() {
  int f[N][6];  
  pii pre[N][6];
  pii max_idx = make_pair(-1, -1);
  int max_length = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 6; ++j) {
      f[i][j] = 1;
      pre[i][j] = make_pair(-1, -1);
      for (int x = 0; x < i; ++x)
        for (int y = 0; y < 6; ++y) {
          int h = f[x][y];
          if (cubes[i][j] == cubes[x][y^1] && f[i][j] < h + 1) {
            f[i][j] = h + 1;
            pre[i][j] = make_pair(x, y);
          }
        }
      if (f[i][j] > max_length) {
        max_length = f[i][j];
        max_idx = make_pair(i, j);
      }
    }
  
  vector<pii> ans;
  while (max_idx != make_pair(-1, -1)) {
    ans.push_back(max_idx);
    int i = max_idx.first;
    int j = max_idx.second;
    max_idx = pre[i][j];
  }
  printf("%d\n", ans.size());
  for (int i = ans.size() - 1; i >= 0; --i)
    printf("%d %s\n", ans[i].first + 1, face[ans[i].second]);
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t = 1;
  while (scanf("%d", &n), n) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < 6; ++j)
        scanf("%d", &cubes[i][j]);
    if (t != 1) printf("\n");
    printf("Case #%d\n", t++);
    lis();
  }
  return 0;
}
