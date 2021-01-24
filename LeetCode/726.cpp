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
  int str2int(string s) {
    if (s == "") return 1;
    istringstream is(s);
    int n;
    is >> n;
    return n;
  }

  string int2str(int n) {
    if (n == 1) return "";
    ostringstream os;
    os << n;
    return os.str(); 
  }

  map<string, int> cut(string s) {
    map<string, int> ans;
    int n = s.size();
    int idx = 0;
    int cnt = 0;
    for (int i = 0; i < n; ) {
      if (s[i] == '(') ++cnt;
      else if (s[i] == ')') --cnt;
      if (cnt) { ++i; continue; }

      int j = i + 1;
      while (j < n && s[j] >= 'a' && s[j] <= 'z') ++j;
      string sub = s.substr(idx, j-idx);

      i = j;
      while (j < n && s[j] >= '0' && s[j] <= '9') ++j;
      ans[sub] += str2int(s.substr(i, j-i));

      i = idx = j;
    }
    return ans;
  }

  map<string, int> parse(string s) {
    map<string, int> ans;
    while (s[0] == '(' && s[s.size()-1] == ')') s = s.substr(1, s.size()-2);
    if (s.size() < 2 || s.size() == 2 && s[1] >= 'a' && s[1] <= 'z') {
      ans[s] = 1;
      return ans;
    } 
    
    map<string, int> splits = cut(s);
    for (auto p: splits) {
      string token = p.first;
      int times = p.second;
      auto t = parse(token);
      for (auto pp: t) ans[pp.first] += pp.second * times;
    }
    return ans;
  }

  string countOfAtoms(string formula) {
    auto s = parse(formula);
    string ans = "";
    for (auto p: s) {
      ans += p.first ;
      ans += int2str(p.second);
    }
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  dump(s.countOfAtoms("H20"));
  dump(s.countOfAtoms("Mg(OH)2"));
  dump(s.countOfAtoms("K4(ON(SO3)2)2"));
  return 0;
}
