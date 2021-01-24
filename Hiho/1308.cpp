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
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {2, 1, -1, -2, 2, 1, -1, -2};
 
int inboard(int x, int y) {
  return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int bfs(int x, int y, int visit[64][64]) {
  visit[x][y] = 0;
  queue<pair<int, int>> q;
  q.push(make_pair(x, y));
  while (!q.empty()) {
    auto p = q.front(); q.pop();
    int x = p.first;
    int y = p.second;
    
    for (int i = 0; i < 8; ++i) {
      int tx = x + dx[i];
      int ty = y + dy[i];
      if (inboard(tx, ty) && visit[tx][ty] == -1) {
        visit[tx][ty] = visit[x][y] + 1;
        q.push(make_pair(tx, ty));
      }
    }
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    char s[3][3];
    scanf("%s%s%s", s[0], s[1], s[2]);
    int visit[3][64][64];
    clr(visit, -1);
    for (int i = 0; i < 3; ++i) {
      int x = s[i][0] - 'A';
      int y = s[i][1] - '1';
      bfs(x, y, visit[i]);
    }
    
    int ans = INF;
    for (int i = 0; i < 64; ++i)
      for (int j = 0; j < 64; ++j) {
        int sum = 0;
        for (int k = 0; k < 3; ++k) {
          if (visit[k][i][j] == -1) {
            sum = INF;
            break;
          }
          sum += visit[k][i][j];
        }
        ans = min(ans, sum);
      }
    printf("%d\n", ans);
  }
  return 0;
}
