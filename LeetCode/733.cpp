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
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  
  int inborad(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m; 
  }

  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int n = image.size() ;
    int m = image[0].size();
    int c = image[sr][sc]; 
    if (c == newColor) return image;

    queue<pair<int, int>> q; 
    q.push(make_pair(sr, sc));

    while (!q.empty()) {
      auto p = q.front(); q.pop();
      int x = p.first;
      int y = p.second;
      image[x][y] = newColor;
      for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (inborad(nx, ny, n, m) && image[nx][ny] == c) {
          q.push(make_pair(nx, ny));
        }
      }
    }
    return image;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
