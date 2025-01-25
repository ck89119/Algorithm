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

bool dfs(unordered_map<int, vector<int>> &g, int cur, unordered_set<int> &s, vector<int> &ans) {
  if (s.size() == 0) {
    return true;
  }
  
  for (auto next: g[cur]) {
    if (s.find(next) != s.end()) {
      s.erase(next);
      ans.push_back(next);
      if (dfs(g, next, s, ans)) {
        return true;
      }
      ans.pop_back();
      s.insert(next);
    } 
  }
  return false;
}

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

  int sum = 0;
  while (getline(cin,line)) {
    istringstream is(line);    
    vector<int> v;
    int a;
    char ch;
    is >> a;
    v.push_back(a);
    while (is >> ch >> a) {
      v.push_back(a);
    }
    
    auto check = [&]() -> bool {
      bool flag = true;
      for (int i = 0; flag && i < v.size(); ++i) {
        auto &vec = g[v[i]];
        for (int j = i + 1; flag && j < v.size(); ++j)
          if (find(vec.begin(), vec.end(), v[j]) == vec.end()) {
            flag = false; 
          }
      } 
      return flag;
    };
    
    if (!check()) {
      // out(v);
      vector<int> ans;
      unordered_set<int> s;
      for (auto x: v) s.insert(x); 
      
      for (auto x: v) {
          s.erase(x);
          ans.push_back(x);
          if (dfs(g, x, s, ans)) {
            break;
          }
          ans.pop_back();
          s.insert(x);
      }

      if (ans.size() == v.size()) {
        sum += ans[v.size() / 2];
      }
    }
  }
  cout << sum << endl;
  return 0;
}
