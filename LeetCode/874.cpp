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

  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    set<pair<int, int>> s;
    for (auto ob: obstacles) {
      int x = ob[0];
      int y = ob[1];
      s.insert({x, y});
    }
          
    int x = 0;
    int y = 0;
    int d = 0;
    int ans = 0;
    for (auto c: commands) {
      if (c == -1) {
        d = (d + 1) % 4; 
      } else if (c == -2) {
        d = (d + 3) % 4; 
      } else {
        for (int i = 0; i < c; ++i) {
          int nx = x + dx[d];
          int ny = y + dy[d];
          if (s.count({nx, ny})) break;
          x = nx;
          y = ny;
        }
      }
      ans = max(ans, x*x+y*y);
    }
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  vector<int> commands;
  commands.push_back(-2);
  commands.push_back(8);
  commands.push_back(3);
  commands.push_back(7);
  commands.push_back(-1);
  vector<vector<int>> obstacles;
  vector<int> ob;
  ob.push_back(-4);
  ob.push_back(-1);
  obstacles.push_back(ob);
  ob.clear();
  ob.push_back(1);
  ob.push_back(-1);
  obstacles.push_back(ob);
  ob.clear();
  ob.push_back(1);
  ob.push_back(4);
  obstacles.push_back(ob);
  ob.clear();
  ob.push_back(5);
  ob.push_back(0);
  obstacles.push_back(ob);
  ob.clear();
  ob.push_back(4);
  ob.push_back(5);
  obstacles.push_back(ob);
  ob.clear();
  ob.push_back(-2);
  ob.push_back(-1);
  obstacles.push_back(ob);
  ob.clear();
  ob.push_back(2);
  ob.push_back(-5);
  obstacles.push_back(ob);
  ob.clear();
  ob.push_back(5);
  ob.push_back(1);
  obstacles.push_back(ob);
  ob.clear();
  ob.push_back(-3);
  ob.push_back(-1);
  obstacles.push_back(ob);
  ob.clear();
  ob.push_back(5);
  ob.push_back(-3);
  obstacles.push_back(ob);
  ob.clear();

  Solution s;
  cout << s.robotSim(commands, obstacles) << endl;
  return 0;
}
