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
const int N = 500 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

class Solution {
 public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    vector<int> v(2);
    v[0] = target; v[1] = 0;
    stations.push_back(v);
    int n = stations.size();
    dump(n);
    ll f[N][N];
    clr(f, -1); 
    f[0][0] = startFuel;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j <= i; ++j) {
        if (f[i][j] == -1) continue;
        int d = stations[i][0] - (i == 0 ? 0 : stations[i-1][0]); 
        dump(d);
        if (f[i][j] >= d) {
          f[i+1][j] = max(f[i+1][j], f[i][j]-d);
        }
        if (i > 0 && f[i][j] + stations[i-1][1] >= d) {
          f[i+1][j+1] = max(f[i+1][j+1], f[i][j]+stations[i-1][1]-d);
        }
      }
    dump("$$$");
    for (int i = 0; i <= n; ++i)
      if (f[n][i] >= 0) return i;
    return -1;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  vector<vector<int>> stations;
  cout << s.minRefuelStops(1, 1, stations) << endl;
  return 0;
}
