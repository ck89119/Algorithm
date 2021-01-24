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
const int N = 55 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

bool check(vector<int> x[N], int n) {
  bool f = true;
  for (int i = 0; i < n; ++i) {
    if (x[i].size() <= 0 || x[i].size() > 2) return false;
    if (x[i].size() == 1) {
      if (f) f = false;
      else return false;
    }
  }
  return !f;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("B-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    int n;
    char maze[N][N];
    scanf("%d", &n); getchar();
    for (int i = 0; i < n; ++i) scanf("%s", maze[i]);
    vector<int> r[N], c[N];
    clr(c, 0); clr(r, 0);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (maze[i][j] == 'X') r[i].push_back(j), c[j].push_back(i);
    for (int i = 0; i < n; ++i) {
      sort(r[i].begin(), r[i].end()); 
      sort(c[i].begin(), c[i].end()); 
    }
    
    if (!check(r, n) || !check(c, n)) {
      printf("Case #%d: IMPOSSIBLE\n", ncase); 
      continue;
    }

    bool visited[N];
    clr(visited, false);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (visited[i]) continue;
      if (c[i].size() == 1) continue;
      int x0 = c[i][0];
      int x1 = c[i][1];
      int y0 = r[x0][0] + r[x0][1] - i;
      int y1 = r[x1][0] + r[x1][1] - i;
      if (y0 != y1) break;
      ++cnt;
      visited[i] = visited[y0] = true;
    } 
    printf("Case #%d: %s\n", ncase, cnt == n / 2 ? "POSSIBLE" : "IMPOSSIBLE"); 
  }
  return 0;
}
