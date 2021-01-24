#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
typedef long long ll;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 1000 + 5;
const int M = 600 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

vector<pair<int, int>> g[N];
int node = 0, s;
int pic[N];
int f[N][M];

int input(int u) {
  int v = ++node;
  int w, pic_cnt;
  scanf("%d%d", &w, &pic_cnt);
  g[u].emplace_back(v, w);
  if (pic_cnt == 0) {
    input(v);
    input(v);
  } else {
    pic[v] = pic_cnt;
  }
  return 0;
}

int dfs(int u) {
  if (pic[u]) {
    for (int i = 1; i <= pic[u]; ++i)
      f[u][5*i] = i;
    return 0;
  }

  for (auto [v, w]: g[u]) {
    dfs(v);
    for (int i = s; i >= 0; --i)
      for (int k = 0; k + 2 * w <= i; ++k)
        f[u][i] = max(f[u][i], f[u][i-k-2*w] + f[v][k]);
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &s);
  memset(pic, 0, sizeof(pic));
  input(0);
  // for (int u = 0; u <= node; ++u)
  //   for (auto [v, w]: g[u]) {
  //     cout << u << " " << v << " " << w << endl;
  //   }
  // for (int i = 0; i <= node; ++i) cout << pic[i] << ' '; cout << endl;

  memset(f, 0, sizeof(f));
  dfs(0);
  // for (int j = 0; j <= node; ++j) {
  //   for (int i = 0; i <= s; ++i) cout << f[j][i] << " "; cout << endl;
  // }
  // printf("%d\n", *max_element(f[0], f[0]+s));
  printf("%d\n", f[0][s-1]);
  return 0;
}