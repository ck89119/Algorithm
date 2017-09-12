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
  string shortestPalindrome(string s) {
    if (s == "") return "";

    string str = "^#";  
    for (auto ch: s) {
      str += ch;
      str += "#";
    }
    str += "$";
    
    int p[str.size()];
    int idx = 0;
    int max_idx = 0;
    clr(p, 0);
    for (int i = 1; i < str.size() - 1; ++i) {
      if (p[i] >= max_idx) {
        p[i] = 1;
      } else {
        int j = 2 * idx - i;
        p[i] = p[j] < max_idx - i ? p[j] : max_idx - i;
      }
      while (str[i-p[i]] == str[i+p[i]]) ++p[i];
      if (i + p[i] > max_idx) {
        max_idx = i + p[i];
        idx = i;
      }
    }

    int max_len = 0;
    for (int i = 1; i < str.size() - 1; ++i)
      if (p[i] == i) max_len = p[i];
    string ans = s.substr(max_len - 1);
    reverse(ans.begin(), ans.end());
    ans += s;
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.shortestPalindrome("abbacd") << endl;
  return 0;
}
