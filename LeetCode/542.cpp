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
  int n, m;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  int inboard(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m; 
  }

  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    n = matrix.size();
    m = matrix[0].size();

    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> ans(n, vector<int>(m ,-1));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (matrix[i][j] == 0) {
          ans[i][j] = 0;
          q.push(make_pair(0, make_pair(i, j)));
        }

    while (!q.empty()) {
      auto item = q.front(); q.pop();
      auto t = item.first;
      auto x = item.second.first;
      auto y = item.second.second;
      
      for (int i = 0; i < 4; ++i) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (inboard(tx, ty) && ans[tx][ty] == -1) {
          ans[tx][ty] = t + 1;
          q.push(make_pair(t+1, make_pair(tx, ty)));
        }
      }
    }
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  vector<vector<int>> matrix;
  vector<int> tmp;
  tmp.push_back(0);
  tmp.push_back(0);
  tmp.push_back(0);
  matrix.push_back(tmp);
  
  tmp.clear();
  tmp.push_back(0);
  tmp.push_back(1);
  tmp.push_back(0);
  matrix.push_back(tmp);

  tmp.clear();
  tmp.push_back(1);
  tmp.push_back(1);
  tmp.push_back(1);
  matrix.push_back(tmp);

  Solution s;
  for (auto x: s.updateMatrix(matrix))
    out(x);
  return 0;
}
