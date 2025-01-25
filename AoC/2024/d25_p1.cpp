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

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  vector<vector<int>> locks, keys;

  string line;
  while (cin >> line) {
    // dump(line);
    vector<string> g;
    g.emplace_back(line);
    for (int i = 0; i < 6; ++i) {
      cin >> line;
      // dump(line);
      g.emplace_back(line);
    }
    
    vector<int> v;
    if (g[0] == "#####") {
      for (int j = 0; j < 5; ++j) {
        int i = 1;
        while (i < 6 && g[i][j] == '#') ++i;
        v.push_back(i - 1); 
      }
      // out(v);
      locks.emplace_back(v);
    } else {
      for (int j = 0; j < 5; ++j) {
        int i = 5;
        while (i > 0 && g[i][j] == '#') --i;
        v.push_back(5 - i); 
      }
      // out(v);
      keys.emplace_back(v);
    }
  }
  // cout << "locks: " << endl;
  // for (auto &l: locks) out(l);
  // cout << "keys: " << endl;
  // for (auto &l: keys) out(l);

  int ans = 0; 
  for (auto &l: locks)
    for (auto &k: keys) {
      int flag = true;
      for (int i = 0; flag && i < 5; ++i) 
        if (l[i] + k[i] > 5) {
          flag = false; 
        }
      // out(l), out(k);
      // dump(flag);
      ans += flag;
    }
  dump(ans);
  return 0;
}
