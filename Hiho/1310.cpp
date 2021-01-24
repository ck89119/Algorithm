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
const int N = 50 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct Island {
  int min_x, min_y, max_x, max_y;
  int area;
  Island(int min_x, int min_y, int max_x, int max_y, int area): 
      min_x(min_x), min_y(min_y), max_x(max_x), max_y(max_y), area(area) {}
};

int n, m;
char pic[N][N];
bool vis[N][N];
vector<Island> islands;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int min_x, min_y, max_x, max_y;

bool in_borad(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

int dfs(int x, int y) {
  int area = 1;
  vis[x][y] = true;
  min_x = min(min_x, x);
  min_y = min(min_y, y);
  max_x = max(max_x, x);
  max_y = max(max_y, y);
  for (int i = 0; i < 4; ++i) {
    int tx = x + dx[i];
    int ty = y + dy[i];
    if (in_borad(tx, ty) && !vis[tx][ty] && pic[tx][ty] == '#') 
      area += dfs(tx, ty);
  }
  return area;
}

bool check(const Island &a, const Island &b) {
  if (a.area != b.area) return false;
  int l1 = a.max_x - a.min_x;
  int l2 = a.max_y - a.min_y;
  if (l1 != b.max_x - b.min_x) return false;
  if (l2 != b.max_y - b.min_y) return false;
  for (int i = 0; i <= l1; ++i)
    for (int j = 0; j <= l2; ++j)
      if (pic[a.min_x+i][a.min_y+j] != pic[b.min_x+i][b.min_y+j]) return false;
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%s", pic[i]);
  clr(vis, false);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (!vis[i][j] && pic[i][j] == '#') {
        min_x = min_y = INF;
        max_x = max_y = -INF;
        int area = dfs(i, j);
        islands.emplace_back(min_x, min_y, max_x, max_y, area);
      }
  printf("%d ", islands.size());
  
  set<int> areas;
  for (auto &i: islands) areas.insert(i.area);
  printf("%d ", areas.size());
  
  int shape = 0;
  vector<bool> vis_island(islands.size(), false);
  for (int i = 0; i < islands.size(); ++i)
    if (!vis_island[i]) {
      ++shape;
      for (int j = i + 1; j < islands.size(); ++j)
        if (check(islands[i], islands[j])) vis_island[j] = true;
    }
  printf("%d\n", shape);

  return 0;
}
