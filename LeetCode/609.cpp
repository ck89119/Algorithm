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
  vector<string> split(string s, char ch) {
    int l = 0, i;
    vector<string> ans;
    for (i = 0; i < s.size(); ++i) {
      if (s[i] == ch) {
        if (i - l > 0) ans.push_back(s.substr(l, i - l));
        l = i + 1;
      }
    }
    if (i - l > 0) ans.push_back(s.substr(l, i - l));
    return ans;
  }

  vector<vector<string>> findDuplicate(vector<string>& paths) {
    map<string, vector<string>> m;
    for (auto path: paths) {
      auto splits = split(path, ' ');
      auto dir = splits[0];
      for (int i = 1; i < splits.size(); ++i) {
        auto file_all = split(splits[i], '(');
        auto file_name = file_all[0];
        auto file_content = file_all[1];
        file_content = file_content.substr(0, file_content.size() - 1);
        if (m.find(file_content) == m.end()) {
          m[file_content] = vector<string>();
        }
        m[file_content].push_back(dir + "/" + file_name);
      }
    }

    vector<vector<string>> ans;
    for (auto item: m) {
      auto file_paths = item.second;
      if (file_paths.size() >= 2) {
        ans.push_back(file_paths);
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
  
  return 0;
}
