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
  bool has_unique_string(const vector<string> &strs) {
    map<string, int> s;
    for (auto str: strs) ++s[str];
    for (auto it: s)
      if (it.second == 1) return true;
    return false;
  }

  bool sub(int cur_s, int cur_p, const string &s, const string &p) {
    if (cur_s >= s.size()) return true;
    
    for (int i = cur_p; i < p.size(); ++i) {
      if (s[cur_s] != p[i]) continue;
      if (sub(cur_s+1, i+1, s, p)) return true;
    }
    return false;
  }

  int findLUSlength(vector<string>& strs) {
    map<int, vector<string>> len;
    for (auto str: strs) {
      int l = str.size();
      len[l].push_back(str);
    }
    
    vector<string> pre_strs;
    for (auto it = len.rbegin(); it != len.rend(); ++it) {
      vector<string> t;
      for (auto cur: it->second) {
        if (pre_strs.size() == 0) {
          t.push_back(cur);
          continue;
        }
        for (auto p: pre_strs)
          if (!sub(0, 0, cur, p)) {
            t.push_back(cur);
            break;
          }
      }

      if (has_unique_string(t)) return it->first;
      pre_strs.insert(pre_strs.end(), t.begin(), t.end()); 
    }
    return -1;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  vector<string> strs;
  // strs.push_back("aba");
  // strs.push_back("cdc");
  // strs.push_back("eae");
  strs.push_back("aabbcc");
  strs.push_back("aabbcc");
  strs.push_back("cb");
  strs.push_back("abc");
  cout << s.findLUSlength(strs) << endl;
  return 0;
}
