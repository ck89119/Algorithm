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

class Solution {
 public:
  int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
  int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

  int inborad(int r, int c, int N) {
    return r >= 0 && r < N && c >= 0 && c < N; 
  }  

  double knightProbability(int N, int K, int r, int c) {
    double p[2][N][N];
    int cur = 0, nxt;
    clr(p[cur], 0);
    p[cur][r][c] = 1.0;
    while (K--) { 
      nxt = cur ^ 1;
      clr(p[nxt], 0);
      for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
          if (p[cur][i][j] > 1e-11) {
            for (int k = 0; k < 8; ++k) {
              int nx = i + dx[k];
              int ny = j + dy[k];
              if (inborad(nx, ny, N))
                p[nxt][nx][ny] += p[cur][i][j] / 8;
            }
          }
      cur = nxt;
    }

    double ans = 0.0;
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j) ans += p[cur][i][j];
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.knightProbability(3, 2, 0, 0);
  return 0;
}
