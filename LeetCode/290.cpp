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
  vector<string> split(string s) {
    vector<string> ans;
    int l = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ' ') {
        ans.push_back(s.substr(l, i - l));
        while (i < s.size() && s[i] == ' ') ++i;
        l = i;
      }
    }
    if (l < s.size()) ans.push_back(s.substr(l, s.size() - l));
    return ans;
  }

  bool wordPattern(string pattern, string str) {
    map<char, string> m;
    map<string, char> r;
    auto v = split(str);
    if (pattern.size() != v.size()) return false;

    for (int i = 0; i < pattern.size(); ++i) {
      char ch = pattern[i];
      if (m.find(ch) == m.end() && r.find(v[i]) == r.end()) {
        m[ch] = v[i];
        r[v[i]] = ch;
      } else if (m.find(ch) != m.end() && r.find(v[i]) != r.end()) {
        if (m[ch] != v[i] || r[v[i]] != ch) return false;
      } else {
        return false;
      }
    }
    return true;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  Solution s;
  cout << s.wordPattern("abba", "dog cat cat dog") << endl;
  cout << s.wordPattern("abba", "dog cat cat fish") << endl;
  cout << s.wordPattern("aaaa", "dog cat cat dog") << endl;
  cout << s.wordPattern("abba", "dog dog dog dog") << endl;
#endif
  
  return 0;
}
