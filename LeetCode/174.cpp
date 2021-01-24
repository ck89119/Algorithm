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

class Solution {
 public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int n = dungeon.size();
    if (n == 0) return 0;
    int m = dungeon[0].size();
    if (m == 0) return 0;
    
    int f[n][m];
    f[n-1][m-1] = max(1, 1 - dungeon[n-1][m-1]);
    for (int i = n-2; i >= 0; --i) {
      f[i][m-1] = f[i+1][m-1] - dungeon[i][m-1];
      f[i][m-1] = max(f[i][m-1], 1); 
    }
    for (int j = m-2; j >= 0; --j) {
      f[n-1][j] = f[n-1][j+1] - dungeon[n-1][j];
      f[n-1][j] = max(f[n-1][j], 1);
    }
    for (int i = n-2; i >= 0; --i)
      for (int j = m-2; j >= 0; --j) {
        f[i][j] = min(f[i+1][j], f[i][j+1]) - dungeon[i][j];
        f[i][j] = max(f[i][j], 1);
      }
    return f[0][0];
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
