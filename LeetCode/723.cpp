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
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++){cout.width(4);cout<<A[i]<<" ";}cout<<endl;}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

class Solution {
 public:
  int n, m;

  int update(vector<vector<int>> &board) {
    for (int j = 0; j < m; ++j) {
      int cnt = board[n-1][j] == 0; 
      for (int i = n - 2; i >= 0; --i) {
        board[i+cnt][j] = board[i][j];
        cnt += board[i][j] == 0;
      }
      for (int i = 0; i < cnt; ++i)
        board[i][j] = 0;
    }
    return 0; 
  }

  vector<vector<int>> candyCrush(vector<vector<int>>& board) {
    n = board.size();
    m = board[0].size();
    bool flag = true;
    while (flag) {
      flag = false;
      vector<vector<bool>> visited(n, vector<bool>(m, false));
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
          if (board[i][j] == 0) continue;
          int v = 1, h = 1;
          while (i + v < n && board[i+v][j] == board[i][j]) ++v;
          while (j + h < m && board[i][j+h] == board[i][j]) ++h;
          flag |= v >= 3 || h >= 3;
          if (v >= 3)
            while (v) { --v; visited[i+v][j] = true; }
          if (h >= 3)
            while (h) { --h; visited[i][j+h] = true; } 
        }
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
          if (visited[i][j]) board[i][j] = 0;
      update(board);
      // for (auto l: board) out(l);
      // dump("$$$$");
    }
    return board;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  vector<vector<int>> board;
  vector<int> v; 
  v = {110,5,112,113,114};
  board.push_back(v);
  v = {210,211,5,213,214};
  board.push_back(v);
  v = {310,311,3,313,314};
  board.push_back(v);
  v = {410,411,412,5,414};
  board.push_back(v);
  v = {5,1,512,3,3};
  board.push_back(v);
  v = {610,4,1,613,614};
  board.push_back(v);
  v = {710,1,2,713,714};
  board.push_back(v);
  v = {810,1,2,1,1};
  board.push_back(v);
  v = {1,1,2,2,2};
  board.push_back(v);
  v = {4,1,4,4,1014};
  board.push_back(v);
  Solution s;
  s.candyCrush(board);
  return 0;
}
