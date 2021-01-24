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
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<"\n";cout<<endl;}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

class Solution {
 public:
  vector<string> split(const string &s, char delim) {
    vector<string> ans;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
       if (item.size() > 0) ans.push_back(item);
    }
    return ans;
  }

  vector<string> removeComments(vector<string>& source) {
    string all, ans;
    for (auto s: source) all += s + '#';
    int cur = 0;
    while (cur < all.size()) {
      auto pos_line = all.find("//", cur);
      auto pos_block = all.find("/*", cur);
      if (pos_line == string::npos && pos_block == string::npos) {
        ans += all.substr(cur);
        break;
      }
      ans += all.substr(cur, min(pos_line, pos_block) - cur);
      if (pos_line < pos_block) {
        int pos = all.find("#", pos_line+2);
        cur = pos;
      } else {
        int pos = all.find("*/", pos_block+2);
        cur = pos + 2;
      }
    }
    return split(ans, '#');
    // vector<string> ans;
    // bool block = false;
    // for (auto s: source) {
    //   if (block) {
    //     auto pos = s.find("*/");
    //     if (pos < s.size() - 2) ans.push_back(s.substr(pos));
    //     block = false;:w :e
    //   } else {
    //     auto pos_line = s.find("//");
    //     auto pos_block = s.find("/*");
    //     if (pos_line == s.size() && pos_block == s.size()) {
    //       ans.push_back(s);
    //     } else if (pos_line < pos_block) {
    //       if (pos_line > 0) ans.push_back(s.substr(0, pos_line));
    //     } else {
    //       if (pos_block > 0) ans.push_back(s.substr(0, pos_block));
    //       block = true;
    //       auto pos_block = s.find("*/");
    //       [> adf//sfasfd */ asdfasd /* asdf */ af /* asdfsf <] asdf
    //     }
    //   } 
    // }
    // return ans; 
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  vector<string> source = {"/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"};
  Solution s;
  for (auto v: s.removeComments(source)) dump(v);
  return 0;
}
