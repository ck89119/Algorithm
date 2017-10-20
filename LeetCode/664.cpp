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
const int N = 100 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

class Solution {
 public:
  int strangePrinter(string s) {
    string ns = "";
    for (int i = 0; i < s.size();) {
      int j = i+1;
      while (j < s.size() && s[j] == s[i]) ++j;
      ns += s[i];
      i = j;
    }

    int n = ns.size();
    int pre[N];
    map<char, int> m;
    for (char ch = 'a'; ch <= 'z'; ++ch) m[ch] = -1;
    for (int i = 0; i < n; ++i) {
      pre[i] = m[ns[i]];
      m[ns[i]] = i;
    }

    int f[N][N];
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        if (i < j) f[i][j] = INF;
        else if (i == j) f[i][j] = 1;
        else f[i][j] = 0;
      }
    // out(pre, n);

    for (int j = 0; j < n; ++j)
      for (int i = j-1; i >= 0; --i) {
        for (int k = pre[j]; k >= i; k = pre[k]) {
          // dump(i), dump(j), dump(k), dump(f[i][j]);
          f[i][j] = min(f[i][j], f[i][k] + f[k+1][j-1]);
          // dump(f[i][j]), dump("$$$$$$");
        }
        // if (ns[i] == ns[j]) f[i][j] = min(f[i][j], f[i+1][j-1]+1);
        for (int k = i; k < j; ++k)
          f[i][j] = min(f[i][j], f[i][k] + f[k+1][j]);
      }
    return f[0][n-1];
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  // cout << s.strangePrinter("baacdddaaddaaaaccbddbcabdaabdbbcdcbbbacbddcabcaaa") << endl;
  // dump(s.strangePrinter("ab"));
  dump(s.strangePrinter("abcab"));
  // dump(s.strangePrinter("aa"));
  // dump(s.strangePrinter("ababa"));
  // dump(s.strangePrinter("bbb"));
  return 0;
}
