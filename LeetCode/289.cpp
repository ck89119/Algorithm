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
  int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
  int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
  
  int neighor_life(int x, int y, vector<vector<int>> &board) {
    int cnt = 0;
    for (int i = 0; i < 8; ++i) {
      int tx = x + dx[i];
      int ty = y + dy[i];
      if (tx >= 0 && tx < board.size() && ty >= 0 && ty < board[0].size()) {
        cnt += board[tx][ty];
      }
    }
    return cnt;
  } 

  void gameOfLife(vector<vector<int>>& board) {
    int n = board.size();
    if (n == 0) return ;
    int m = board[0].size();
    if (m == 0) return ;
    
    vector<vector<int>> tmp;
    for (int i = 0; i < n; ++i) {
      vector<int> t;
      for (int j = 0; j < m; ++j) {
        int x = neighor_life(i, j, board);
        if (board[i][j] == 1) {
          t.push_back(x >= 2 && x <= 3 ? 1 : 0);
        } else {
          t.push_back(x == 3 ? 1 : 0);
        }
      }
      tmp.push_back(t);
    }

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        board[i][j] = tmp[i][j];
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
