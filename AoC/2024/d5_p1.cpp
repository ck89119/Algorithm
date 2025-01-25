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

// bool dfs(const map<int, vector<int>> &g, const vector<int> &v, int idx, int cur) {
//   if (idx == v.size()) return true;

//   auto &children = g[v[idx]] ;
//   for (auto c: children) {
//     if (dfs(g, v, idx))
//   }

//   return dfs(g, v, idx, cur);
// }

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  unordered_map<int, vector<int>> g;

  string line; 
  while (getline(cin,line)) {
    // cout << line << endl;
    if (line == "") {
      break;
    }

    istringstream is(line);    
    int a, b;
    char ch;
    is >> a >> ch >> b;
    // cout << a << " " << b << endl;
    g[a].push_back(b);
  }

  int ans = 0;
  while (getline(cin,line)) {
    // cout << line << endl;
    vector<int> v;
    int a;
    char ch;
    istringstream is(line);    
    is >> a;
    v.push_back(a);
    while (is >> ch >> a) {
      // dump(ch); dump(a);
      v.push_back(a);
    }
    // out(v);
    
    bool flag = true;
    for (int i = 0; flag && i < v.size(); ++i) {
      auto &vec = g[v[i]];
      for (int j = i + 1; flag && j < v.size(); ++j)
        if (find(vec.begin(), vec.end(), v[j]) == vec.end()) {
          flag = false; 
        }
    } 
    if (flag) {
      ans += v[v.size()/2];
    }
  }
  cout << ans << endl;
  return 0;
}
