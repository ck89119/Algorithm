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

string manacher(string s0) {
  string s = "^#";
  for (int i = 0; i < s0.size(); ++i) {
    s = s + s0[i];
    s = s + "#";
  }
  s += '$';
  // for (auto ch: s) cout << ch << ' '; cout << endl;

  int c = 0, right_most = 0, n = s.size();
  vector<int> r(n, 1);
  for (int i = 1; i < n; ++i) {
    if (right_most > i) {
      r[i] = min(r[2 * c - i], right_most - i);
    }
    while (s[i - r[i]] == s[i + r[i]]) ++r[i];

    if (i + r[i] > right_most) {
      right_most = i + r[i];
      c = i;
    } 
  }
  // out(r, s.size());

  int j = 0;
  for (int i = 1; i < s.size(); ++i) 
    if (r[i] > r[j]) {
      j = i;
    }
  
  // j - r[j] + 2: 第一个有意义字符
  // (i - 2) / 2: s[i]对应在s0中的位置
  return s0.substr((j - r[j]) / 2 , r[j] - 1);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  string s0 = "12212321";
  cout << manacher(s0) << endl;
  return 0;
}
