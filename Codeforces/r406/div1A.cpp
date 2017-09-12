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
const int N = 7000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
int k1, k2;
int f[2][N], s[2][N];
bool visited[2][N];

int search(int x, int y) {
  if (f[x][y] != -1) return f[x][y];
 
  int all_win = -1;
  int l = (x == 0 ? k1 : k2);
  for (int i = 0; i < l; ++i) {
    int idx = (y + s[x][i]) % n;
    if (!visited[1-x][idx]) {
      visited[1-x][idx] = true;
      int t = search(1-x, idx);
      visited[1-x][idx] = false;

      if (t == 0) return f[x][y] = 2;
      if (t == 2 && all_win == -1) all_win = 1; 
      if (t == 1) all_win = 0;
    }
  }
  return f[x][y] = all_win == 1 ? 0 : 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  scanf("%d", &k1);
  for (int i = 0; i < k1; ++i)
    scanf("%d", &s[0][i]);
  scanf("%d", &k2);
  for (int i = 0; i < k2; ++i)
    scanf("%d", &s[1][i]);

  clr(f, -1); f[0][0] = f[1][0] = 0;
  for (int i = 1; i < n; ++i) {
    clr(visited, false);
    visited[0][i] = true;
    search(0, i);
  }
  for (int i = 1; i < n; ++i) {
    clr(visited, false);
    visited[1][i] = true;
    search(1, i);
  }

  for (int x = 0; x < 2; ++x) {
    for (int i = 1; i < n; ++i)
      if (f[x][i] == 0) printf("Lose ");
      else if (f[x][i] == 2) printf("Win ");
      else printf("Loop ");
    printf("\n");
  }
  return 0;
}
