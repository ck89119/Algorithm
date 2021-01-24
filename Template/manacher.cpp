#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
typedef long long ll;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 1000000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int manacher(string s0) {
  string s = "^#";
  for (int i = 0; i < s0.size(); ++i) {
    s = s + s0[i];
    s = s + "#";
  }
  s += '$';
  for (auto ch: s) cout << ch << ' '; cout << endl;

  int idx = 0, mx = 0, n = s.size();
  vector<int> p(n, 0);
  for (int i = 1; i < n; ++i) {
    if (mx > i) {
      int j = 2 * idx - i;
      p[i] = min(p[j], mx-i);
    } else {
      p[i] = 1;
    }
    while (s[i-p[i]] == s[i+p[i]]) ++p[i];
    if (i + p[i] > mx) {
      mx = i + p[i];
      idx = i;
    } 
  }
  out(p, s.size());

  int max = 0, ii;
  for (int i = 1; i < s.size(); ++i) 
    if (p[i] > max) {
      max = p[i];
      ii = i;
    }
  --max;
  string ans = "";
  for (int i = ii-max; i <= ii+max; ++i)
    if (s[i] != '#') ans = ans + s[i];
  cout << ans << endl;

  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  string s0 = "12212321";
  manacher(s0);
  return 0;
}